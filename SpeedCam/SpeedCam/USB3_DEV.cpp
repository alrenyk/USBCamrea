//#############################################################################
// Copyright 2018 TakeRix Co., Ltd
// FX3 USB Control Device
// USB3_DEV.h
// Version 1.1.0
// alren@takerix.com
//#############################################################################

#include "StdAfx.h"
#include "USB3_DEV.h"
#include <dbt.h>
#include "direct.h"

CUSB3_DEV::CUSB3_DEV(void)
{
	m_UsbDevice = new CCyUSBDevice(NULL);
	m_FxDevice = NULL;

	m_TimeOut = 17;
	m_PktCnt  = 38;
}


CUSB3_DEV::~CUSB3_DEV(void)
{
	if (m_UsbDevice->IsOpen())
	{
		m_UsbDevice->Close();
		m_UsbDevice->~CCyUSBDevice();
	}

	if (m_UsbDevice != NULL)
	{
		delete m_UsbDevice;
		m_UsbDevice = NULL;
	}

	if (m_FxDevice->IsOpen()) {
		m_FxDevice->Close();
		m_FxDevice->~CCyFX3Device();
	}
	
	if (m_FxDevice != NULL) {
		delete m_FxDevice;
		m_FxDevice = NULL;
	}
}

ReturnStatus CUSB3_DEV::DeviceOpen()
{

	ReturnStatus RetStatus = _SUCCESS_USB;

	DevCnt = m_UsbDevice->DeviceCount();
	VendorID, ProductID;
	IsUSBOpen = false;

	if(DevCnt !=0)
	{
			IsUSBOpen = m_UsbDevice->Open(0);
			VendorID = m_UsbDevice->VendorID;
			ProductID = m_UsbDevice->ProductID;

	}
	else{
		RetStatus = _ERROR_USB;
	}

	if(IsUSBOpen)
	{
		// BulkIn EndPoint
		EndPointCount = m_UsbDevice->EndPointCount();
		for(int i=0; i<EndPointCount;i++)
		{
			bool bAddrFlag = ((m_UsbDevice->EndPoints[i]->Address & 0x81) == 0x81);
			bool bAttrFlag = (m_UsbDevice->EndPoints[i]->Attributes == 2);

			if (bAttrFlag && bAddrFlag) {
				//m_UsbDevice->BulkInEndPt = (CCyBulkEndPoint *) m_UsbDevice->EndPoints[i];
				//BulkInEndPt_ = (CCyBulkEndPoint *) m_UsbDevice->EndPointOf((UCHAR)i);;
			}
		}
		RetStatus = _SUCCESS_USB;
	}
	else
	{
		RetStatus = _ERROR_USB;
	}
	

	return RetStatus;
}

ReturnStatus CUSB3_DEV::Device_Check()
{
	ReturnStatus RetStatus = _SUCCESS_USB;
	DevCnt = m_UsbDevice->DeviceCount();
	IsUSBOpen = m_UsbDevice->Open(0);

	strDeviceData;
	strDeviceData.Format(_T("%s"), CString(m_UsbDevice->FriendlyName));

	sMenu;
	sMenu.Format(_T("%s"), CString(m_UsbDevice->Manufacturer));

	sProduct;
	sProduct.Format(_T("%s"), CString(m_UsbDevice->Product));

	return RetStatus;
}

ReturnStatus CUSB3_DEV::I2CWrite(BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
								BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode)
{
	ReturnStatus RetStatus = _SUCCESS_USB;
	BYTE buffer [512];
	LONG size = sizeof(buffer);
	RtlZeroMemory(buffer, size);

	m_UsbDevice->ControlEndPt->Direction = DIR_TO_DEVICE;
	m_UsbDevice->ControlEndPt->Value = (WORD)ChipID;
	m_UsbDevice->ControlEndPt->TimeOut = 10;
	m_UsbDevice->ControlEndPt->ReqCode = ((I2CMode<<6) | (I2CSpeed<<5) | I2CProtocol);

	if(I2CProtocol == MX_I2C_A1D1_)
	{
		m_UsbDevice->ControlEndPt->Index = (WORD)(*pAddr);
		buffer[0] = (*pWrData);
	}
	else if(I2CProtocol == MX_I2C_A1D2_)
	{
		m_UsbDevice->ControlEndPt->Index = (WORD)(*pAddr);
		BYTE TempA[2];
		memcpy(TempA, pWrData, sizeof(pWrData));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB
	}
	else if(I2CProtocol == MX_I2C_A2D1_)
	{
		BYTE TempA[2];
		memcpy(TempA, pAddr, sizeof(pAddr));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB

		BYTE TempB[2];
		memcpy(TempB, pWrData, sizeof(pWrData));
		m_UsbDevice->ControlEndPt->Index = (WORD)TempB[0];
	}
	else if(I2CProtocol == MX_I2C_A2D2_)
	{
		BYTE TempA[2];
		memcpy(TempA, pWrData, sizeof(pWrData));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB
		BYTE TempB[2];
		memcpy(TempB, pAddr, sizeof(pAddr));
		buffer[2] = TempB[0];		//MSB
		buffer[3] = TempB[1];		//LSB
	}

	if (m_UsbDevice->ControlEndPt->XferData(buffer, size))
	{
		RetStatus = _SUCCESS_USB;
	}
	Sleep(1);

	return RetStatus;
}

ReturnStatus CUSB3_DEV::I2CRead(BYTE ChipID, BYTE* pAddr, BYTE* pRdData,
								BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode)
{
	ReturnStatus RetStatus = _SUCCESS_USB;

	BYTE buffer [2];
	LONG size = sizeof(buffer);
	RtlZeroMemory(buffer, size);

	m_UsbDevice->ControlEndPt->Direction = DIR_FROM_DEVICE;
	m_UsbDevice->ControlEndPt->Value = (WORD)ChipID;
	m_UsbDevice->ControlEndPt->TimeOut = 10;
	m_UsbDevice->ControlEndPt->ReqCode = ((I2CMode<<6) | (I2CSpeed<<5) | I2CProtocol);

	if(I2CProtocol == MX_I2C_A1D1_)
	{
		m_UsbDevice->ControlEndPt->Index = (WORD)(*pAddr);
		buffer[0] = 0;//(*DATA);
	}
	else if(I2CProtocol == MX_I2C_A1D2_)
	{
		m_UsbDevice->ControlEndPt->Index = (WORD)(*pAddr);
		//BYTE TempA[2];
		//memcpy(TempA, DATA, sizeof(DATA));
		buffer[0] = 0;//TempA[0];		//MSB
		buffer[1] = 0;//TempA[1];		//LSB
	}
	else if(I2CProtocol == MX_I2C_A2D1_)
	{
		BYTE TempA[2];
		memcpy(TempA, pAddr, sizeof(pAddr));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB

		//BYTE TempB[2];
		//memcpy(TempB, DATA, sizeof(DATA));
		m_UsbDevice->ControlEndPt->Index = 0;//(WORD)TempB[0];//data
	}
	else if(I2CProtocol == MX_I2C_A2D2_)
	{
		//BYTE TempA[2];
		//memcpy(TempA, DATA, sizeof(DATA));
		buffer[0] = 0;//TempA[0];		//MSB
		buffer[1] = 0;//TempA[1];		//LSB
		BYTE TempB[2];
		memcpy(TempB, pAddr, sizeof(pAddr));
		buffer[2] = TempB[0];		//MSB
		buffer[3] = TempB[1];		//LSB
	}
	if(m_UsbDevice->ControlEndPt->XferData(buffer, size))
	{
		memcpy(pRdData, buffer, sizeof(buffer));
		RetStatus = _SUCCESS_USB;
	}


	return RetStatus;
}

ReturnStatus CUSB3_DEV::GetImageFrame(BYTE* pImageData, INT64* pTimeStamp)
{
	//OVERLAPPED		inOvLap;
	//inOvLap.hEvent = CreateEvent(NULL, false, false, NULL);
	//BulkInEndPt_ = (CCyBulkEndPoint *)m_UsbDevice->BulkInEndPt;

#if 0
	ReturnStatus RetStatus = _SUCCESS_USB;
    OVERLAPPED inOvLap; 
    bool bRequest = FALSE;
	LONG BufferSize = ((LONG)16384);
   
    inOvLap.hEvent   = CreateEvent(NULL, false, false, NULL);
	m_UsbDevice->BulkInEndPt->SetXferSize((ULONG)BufferSize);
    UCHAR  *inContext = m_UsbDevice->BulkInEndPt->BeginDataXfer(pImageData,BufferSize, &inOvLap);
    if(!m_UsbDevice->BulkInEndPt->WaitForXfer(&inOvLap,1000))
    {  
       m_UsbDevice->BulkInEndPt->Reset();
       CloseHandle(inOvLap.hEvent);
       return _ERROR_USB;;  
    }

    bRequest = m_UsbDevice->BulkInEndPt->FinishDataXfer(pImageData,BufferSize, &inOvLap,inContext);
    CloseHandle(inOvLap.hEvent);

   
    if(!bRequest)
    {
        m_UsbDevice->BulkInEndPt->Abort();
        m_UsbDevice->BulkInEndPt->Reset();
    }

#else
	ReturnStatus RetStatus = _SUCCESS_USB;

	LONG	BufferSize	= m_UsbDevice->BulkInEndPt->MaxPktSize * m_PktCnt * sizeof(BYTE);
	ULONG	TimeOut		= m_TimeOut;
	BufferSize = ((LONG)16384);
	ULONG nsizen = m_UsbDevice->BulkInEndPt->GetXferSize();

	if (m_UsbDevice->BulkInEndPt)
	{
		m_UsbDevice->BulkInEndPt->SetXferSize((ULONG)BufferSize);
		m_UsbDevice->BulkInEndPt->TimeOut = TimeOut;
		if(!m_UsbDevice->BulkInEndPt->XferData(pImageData,BufferSize))
		{
			(*pTimeStamp)++;
			return _ERROR_USB;
		}
	}
#endif

	return RetStatus;
}