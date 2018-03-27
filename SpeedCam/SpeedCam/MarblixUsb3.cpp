//#############################################################################
// Copyright 2012-2014 People & Chips Co., Ltd
// MARBLIX¢â-U
// MarblixUsb3.h
// Version 1.1.0	Sep 25, 2014
// joe@peoplechips.co.kr
//#############################################################################
#include "stdafx.h"
#include "MarblixUsb3.h"
#include <dbt.h>
#include "direct.h"

MarblixUsb3::MarblixUsb3(void)
{
	pMxDevice[0] = new CCyUSBDevice(NULL);
	pMxDevice[1] = new CCyUSBDevice(NULL);
	pMxDevice[2] = new CCyUSBDevice(NULL);
	pMxDevice[3] = new CCyUSBDevice(NULL);

	pFx3Device = NULL;

	m_TimeOut = 500;
	//m_PktCnt  = 38;//235;
	//m_TimeOut = 2500;
	m_PktCnt  = 1;//235;
}

MarblixUsb3::~MarblixUsb3(void)
{
	for(int i=0; i<4; i++) {
		if (pMxDevice[i]->IsOpen())
		{
			pMxDevice[i]->Close();
			pMxDevice[i]->~CCyUSBDevice();
		}
		if (pMxDevice[i] != NULL)
		{
			delete pMxDevice[i];
			pMxDevice[i] = NULL;
		}
	}

	if (pFx3Device->IsOpen()) {
		pFx3Device->Close();
		pFx3Device->~CCyFX3Device();
	}
	
	if (pFx3Device != NULL) {
		delete pFx3Device;
		pFx3Device = NULL;
	}
}

int MarblixUsb3::MyPow(int to1,int to2)
{
	int num = 1;
	for(int i=0;i<to2;i++)
	{
		num = num*to1;
	}
	return num;
}

int MarblixUsb3::CalOTCData(float data, bool MKhz)
{
	int OtCdata = 0;
	if (MKhz == true) // is Mhz
	{
		if ((data > 0.001039) && (data < 0.002076))
		{
			OtCdata = 0;
		}
		else if ((data > 0.002078) && (data < 0.004152))
		{
			OtCdata = 1;
		}
		else if ((data > 0.004156) && (data < 0.008304))
		{
			OtCdata = 2;
		}
		else if ((data > 0.008312) && (data < 0.01661))
		{
			OtCdata = 3;
		}
		else if ((data > 0.01662) && (data < 0.03322))
		{
			OtCdata = 4;
		}
		else if ((data > 0.03325) && (data < 0.06643))
		{
			OtCdata = 5;
		}
		else if ((data > 0.0665) && (data < 0.1329))
		{
			OtCdata = 6;
		}
		else if ((data > 0.133) && (data < 0.2657))
		{
			OtCdata = 7;
		}
		else if ((data > 0.266) && (data < 0.5314))
		{
			OtCdata = 8;
		}
		else if ((data > 0.532) && (data < 1.063))
		{
			OtCdata = 9;
		}
		else if ((data > 1) && (data < 2.126))
		{
			OtCdata = 10;
		}
		else if ((data > 2.128) && (data < 4.252))
		{
			OtCdata = 11;
		}
		else if ((data > 4.256) && (data < 8.503))
		{
			OtCdata = 12;
		}
		else if ((data > 8.511) && (data < 17.01))
		{
			OtCdata = 13;
		}
		else if ((data > 17.02) && (data < 34.01))
		{
			OtCdata = 14;
		}
		else if ((data > 34.05) && (data < 68.03))
		{
			OtCdata = 15;
		}

	}

	if (MKhz == false)//is Khz
	{
		if ((data > 1.039) && (data < 2.076))
		{
			OtCdata = 0;
		}
		else if ((data > 2.078) && (data < 4.152))
		{
			OtCdata = 1;
		}
		else if ((data > 4.156) && (data < 8.304))
		{
			OtCdata = 2;
		}
		else if ((data > 8.312) && (data < 16.61))
		{
			OtCdata = 3;
		}
		else if ((data > 16.62) && (data < 33.22))
		{
			OtCdata = 4;
		}
		else if ((data > 33.25) && (data < 66.43))
		{
			OtCdata = 5;
		}
		else if ((data > 66.5) && (data < 132.9))
		{
			OtCdata = 6;
		}
		else if ((data > 133) && (data < 265.7))
		{
			OtCdata = 7;
		}
		else if ((data > 266) && (data < 531.4))
		{
			OtCdata = 8;
		}
		else if ((data > 532) && (data < 1063))
		{
			OtCdata = 9;
		}
	}
	 return OtCdata;
}

MxReturnStatus_t MarblixUsb3::MxSetPwrDAC(char DeviceIndex, BYTE PwrChannel, int Vdata)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0x20;
	BYTE	Addr[4];
	BYTE	WrData[4];

	BYTE	DacSet = 0x80;
	BYTE	DacLoad = 0x90;

	DacSet |= PwrChannel;
	DacLoad = PwrChannel | PwrChannel;

	if ( PwrChannel > 5 ) return MX_ERROR;

	Addr[0]		= 0x26;
	WrData[0]	= 0xFF;
	WrData[1]	= 0xFF;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D2, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0]		= 0x40;
	WrData[0]	= 0xFF;
	WrData[1]	= 0x00;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D2, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0]		= 0x50;
	WrData[0]	= 0xFF;
	WrData[1]	= 0xF8;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D2, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0]		= DacSet;
	WrData[0]	= (BYTE)(Vdata>>8);
	WrData[1]	= (BYTE)((Vdata)>>0);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D2, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0]		= DacLoad;
	WrData[0]	= 0xFF;
	WrData[1]	= 0xF0;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D2, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetImageSize(char DeviceIndex, WORD ImageWidth, WORD ImageHeight)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];

	BYTE	XMSB;
	BYTE	XLSB;
	BYTE	YMSB;
	BYTE	YLSB;

	XMSB = (ImageWidth&0xFF00)>>8;
	Addr[0] = 0x32;
	WrData[0] = XMSB;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	XLSB = ImageWidth&0x00FF;
	Addr[0] = 0x33;
	WrData[0] = XLSB;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	YMSB = (ImageHeight&0xFF00)>>8;
	Addr[0] = 0x34;
	WrData[0] = YMSB;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	YLSB = ImageHeight&0x00FF;
	Addr[0] = 0x35;
	WrData[0] = YLSB;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

//#############################################################################
MxReturnStatus_t MarblixUsb3::MxFWDownLoad(char DeviceIndex, CString sFileName, BYTE TargetMemory)
{
	MxReturnStatus_t RetStatus = MX_ERROR;

	CString FileName;
	pFx3Device = new CCyFX3Device();
	FX3_FWDWNLOAD_ERROR_CODE dwld_status = FAILED;

	if ((pMxDevice[DeviceIndex]->VendorID == MX_VID) && (pMxDevice[DeviceIndex]->ProductID == MX_PID_BOOT)) 
	{
		if(pFx3Device->Open(0))
		{
			bool status = pFx3Device->IsBootLoaderRunning();
			char WorkDir[100];
			_getcwd(WorkDir, MAX_PATH);
			FileName = (LPCSTR)(LPSTR)WorkDir;
			FileName = FileName + "\\"+sFileName;
			//wsprintf(WorkDir, "%s", FileName);
			dwld_status = pFx3Device->DownloadFw(WorkDir,RAM);
		}
	}
	
	if(dwld_status == SUCCESS)
	{
		RetStatus = MX_SUCCESS;
	}
	return RetStatus;
}

MxReturnStatus_t MarblixUsb3::MxDeviceOpen(char DeviceIndex)
{
	MxReturnStatus_t RetStatus = MX_ERROR;

	UCHAR DevCnt = pMxDevice[DeviceIndex]->DeviceCount();
	USHORT VendorID, ProductID, TargetPID;
	bool TargetDevDet = false;

	if (DeviceIndex == 0) {
		TargetPID = MX_PID_0;
	}
	else if (DeviceIndex == 1) {
		TargetPID = MX_PID_1;
	}
	else if (DeviceIndex == 2) {
		TargetPID = MX_PID_2;
	}
	else if (DeviceIndex == 3) {
		TargetPID = MX_PID_3;
	}

	for(int i=0; i<DevCnt; i++)
	{
		pMxDevice[DeviceIndex]->Open(i);

		VendorID = pMxDevice[DeviceIndex]->VendorID;
		ProductID = pMxDevice[DeviceIndex]->ProductID;

		if (VendorID = MX_VID && ProductID == TargetPID) {
			TargetDevDet = true;
			break;
		}
	}
	if (TargetDevDet) {
		//ControlEndPoint
		//pMxDevice[DeviceIndex]->ControlEndPt;

		// BulkIn EndPoint
		UCHAR EndPointCount = pMxDevice[DeviceIndex]->EndPointCount();
		for(int i=1; i<EndPointCount;i++)
		{
			bool bAddrFlag = ((pMxDevice[DeviceIndex]->EndPoints[i]->Address & 0x81) == 0x81);
			bool bAttrFlag = (pMxDevice[DeviceIndex]->EndPoints[i]->Attributes == 2);

			if (bAttrFlag && bAddrFlag) {
				pMxDevice[DeviceIndex]->BulkInEndPt = (CCyBulkEndPoint *) pMxDevice[DeviceIndex]->EndPoints[i];
			}
		}
		RetStatus = MX_SUCCESS;
	}
	else {
		RetStatus = MX_ERROR;
	}

	return RetStatus;
}

MxReturnStatus_t MarblixUsb3::MxSetSensorClock(char DeviceIndex, BYTE MclkMode, float TargetFreq)
{
	// MclkMode : TBD

	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];

	if (MclkMode > 2) return MX_ERROR_MCLK_CFG;

	Addr[0] = 0x0C;
	WrData[0] = MclkMode;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	if (MclkMode == MX_MCLK_FIXED) return MX_SUCCESS;

	// Set Programmable Clock
	int OTC = 0;
	float ClockData = 0;
	int data = 0;

	if ((TargetFreq > 0.001039) && (TargetFreq < 68.03))
	{
		OTC = CalOTCData(TargetFreq, true);
	}
	else
	{
		return MX_ERROR_MCLK_RANGE;
	}
	data = MyPow(2,(OTC));
	int test = (2078 * data);
	float tf = ((TargetFreq * 1000000)) / 1024;
	ClockData = 2048 - (test / tf);
	int Fdata = OTC << 12;
    int jdata = (int)ClockData << 2;
    int kdata = Fdata | jdata;
    int addr = ((kdata & 0xff00) >> 8);

	ChipID = 0x2E;
	Addr[0] = (BYTE)addr;
	addr = (kdata & 0x00ff);
    addr = addr | 0x0002;
	WrData[0] = (BYTE)addr;

	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetSensorPower(char DeviceIndex, BYTE PwrChannel, float TargetVolt)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	float	CalibratedVolt;
	double	vData = 0;
	int		DoData = 0;

	if (PwrChannel > 5) return MX_ERROR_POWER_CH_SEL;

	if (TargetVolt < 0.1)
	{
		RetStatus = MxSetPwrChOnOff(DeviceIndex, PwrChannel, MX_POWER_OFF);
		if (RetStatus == MX_ERROR) return MX_ERROR;
	}
	else if((TargetVolt > 1.49)&&(TargetVolt < 5.1))
	{
		// Calibration
		CalibratedVolt = TargetVolt + 0.1f;
		// Calc. DAC Setting Value
		vData = (7.056 - CalibratedVolt)/0.002713;
		DoData = (int)vData;
		DoData = DoData<<4;
		// Set DAC
		RetStatus = MxSetPwrDAC(DeviceIndex, PwrChannel, DoData);
		if (RetStatus == MX_ERROR) return MX_ERROR;
		// Power ON
		RetStatus = MxSetPwrChOnOff(DeviceIndex, PwrChannel, MX_POWER_ON);
		if (RetStatus == MX_ERROR) return MX_ERROR;
	}
	else 
	{
		return MX_ERROR_POWER_RANGE;
	}

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetPwrChOnOff(char DeviceIndex, BYTE PwrChannel, BYTE PwrState)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	if ( (PwrChannel > 5) || (PwrState > 2) ) return MX_ERROR;

	Addr[0] = 0x06;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	RdData[0] |= 0x80;
	BYTE Mask = ~(0x01 << PwrChannel);
	WrData[0] = (RdData[0] & Mask) | (PwrState<<PwrChannel);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetSensorReset(char DeviceIndex, BYTE ResetState)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	if (ResetState > 2) return MX_ERROR;

	Addr[0] = 0x05;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	WrData[0] = (RdData[0] & 0xFE) | ResetState;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetSensorEnable(char DeviceIndex, BYTE EnableState)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	if (EnableState > 2) return MX_ERROR;

	Addr[0] = 0x05;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	WrData[0] = (RdData[0] & 0xFD) | (EnableState<<1);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetVsyncPolarity(char DeviceIndex, BYTE VsyncPolarity)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	if (VsyncPolarity > 2) return MX_ERROR;

	Addr[0] = 0x30;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	WrData[0] = (RdData[0] & 0xFB) | (VsyncPolarity<<2);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetHsyncPolarity(char DeviceIndex, BYTE HsyncPolarity)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	if (HsyncPolarity > 2) return MX_ERROR;

	Addr[0] = 0x30;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	WrData[0] = (RdData[0] & 0xFD) | (HsyncPolarity<<1);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetPclkPolarity(char DeviceIndex, BYTE PclkPolarity)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];

	if (PclkPolarity > 2) return MX_ERROR;

	Addr[0] = 0x36;

	WrData[0] = PclkPolarity;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxI2CWrite(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
										  BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode)
{
	if(MxDeviceOpen(DeviceIndex) != MX_SUCCESS)		
		{
			return MX_ERROR;
	}
	
	MxReturnStatus_t bStatus = MX_ERROR;
	BYTE buffer [512];
	LONG size = sizeof(buffer);
	RtlZeroMemory(buffer, size);

	pMxDevice[DeviceIndex]->ControlEndPt->Direction = DIR_TO_DEVICE;
	pMxDevice[DeviceIndex]->ControlEndPt->Value = (WORD)ChipID;
	pMxDevice[DeviceIndex]->ControlEndPt->TimeOut = 10;
	pMxDevice[DeviceIndex]->ControlEndPt->ReqCode = ((I2CMode<<6) | (I2CSpeed<<5) | I2CProtocol);

	if(I2CProtocol == MX_I2C_A1D1)
	{
		pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)(*pAddr);
		buffer[0] = (*pWrData);
	}
	else if(I2CProtocol == MX_I2C_A1D2)
	{
		pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)(*pAddr);
		BYTE TempA[2];
		memcpy(TempA, pWrData, sizeof(pWrData));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB
	}
	else if(I2CProtocol == MX_I2C_A2D1)
	{
		BYTE TempA[2];
		memcpy(TempA, pAddr, sizeof(pAddr));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB

		BYTE TempB[2];
		memcpy(TempB, pWrData, sizeof(pWrData));
		pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)TempB[0];

	}
	else if(I2CProtocol == MX_I2C_A2D2)
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
	if (pMxDevice[DeviceIndex]->ControlEndPt->XferData(buffer, size))
	{
		bStatus = MX_SUCCESS;
	}
	Sleep(1);
	return bStatus;
}

MxReturnStatus_t MarblixUsb3::MxI2CRead(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pRdData,
										 BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode)
{
	if(MxDeviceOpen(DeviceIndex) != MX_SUCCESS)		
		{
			return MX_ERROR;
	}

	MxReturnStatus_t bStatus = MX_ERROR;
	BYTE buffer[2];
	LONG size = sizeof(buffer);
	RtlZeroMemory(buffer, size);

	pMxDevice[DeviceIndex]->ControlEndPt->Direction = DIR_FROM_DEVICE;
	pMxDevice[DeviceIndex]->ControlEndPt->Value =  (WORD)ChipID;
	pMxDevice[DeviceIndex]->ControlEndPt->TimeOut = 10;
	pMxDevice[DeviceIndex]->ControlEndPt->ReqCode = ((I2CMode<<6) | (I2CSpeed<<5) | I2CProtocol);

	if(I2CProtocol == MX_I2C_A1D1)
	{
		pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)(*pAddr);
		buffer[0] = 0;//(*DATA);
	}
	else if(I2CProtocol == MX_I2C_A1D2)
	{
		pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)(*pAddr);
		//BYTE TempA[2];
		//memcpy(TempA, DATA, sizeof(DATA));
		buffer[0] = 0;//TempA[0];		//MSB
		buffer[1] = 0;//TempA[1];		//LSB
	}
	else if(I2CProtocol == MX_I2C_A2D1)
	{
		BYTE TempA[2];
		memcpy(TempA, pAddr, sizeof(pAddr));
		buffer[0] = TempA[0];		//MSB
		buffer[1] = TempA[1];		//LSB

		//BYTE TempB[2];
		//memcpy(TempB, DATA, sizeof(DATA));
		pMxDevice[DeviceIndex]->ControlEndPt->Index = 0;//(WORD)TempB[0];//data
	}
	else if(I2CProtocol == MX_I2C_A2D2)
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

	if(pMxDevice[DeviceIndex]->ControlEndPt->XferData(buffer, size))
	{
		memcpy(pRdData, buffer, sizeof(buffer));
		bStatus = MX_SUCCESS;
	}
	//Sleep(1);
	return bStatus;
}

MxReturnStatus_t MarblixUsb3::MxI2CWriteBurst(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
											   BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE buffer [512];
	LONG size = sizeof(buffer);
	RtlZeroMemory(buffer, size);

	pMxDevice[DeviceIndex]->ControlEndPt->Direction = DIR_TO_DEVICE;
	pMxDevice[DeviceIndex]->ControlEndPt->Value = (WORD)(ChipID);
	pMxDevice[DeviceIndex]->ControlEndPt->Index = (WORD)(*pAddr);

	pMxDevice[DeviceIndex]->ControlEndPt->ReqCode = ((I2CMode<<6) | (I2CSpeed<<5) | I2CProtocol);

	if (pMxDevice[DeviceIndex]->ControlEndPt->XferData(pWrData, size))
	{
		RetStatus = MX_SUCCESS;
	}
	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxI2CRWTest(char DeviceIndex, BYTE I2CSpeed, BYTE I2CMode, int LoopCnt)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	int i;
	for(i=0; i< LoopCnt;i++)
	{
		Addr[0] = 0x00;
		RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
		if (RetStatus == MX_ERROR) return MX_ERROR;

		WrData[0] = RdData[0];
		RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
		if (RetStatus == MX_ERROR) return MX_ERROR;
		if (RdData[0] != 0xA4) return MX_ERROR;
	}

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetImageParameter(char DeviceIndex, BYTE SensorMode, BYTE DataType,
											WORD ImageWidth, WORD ImageHeight, BYTE MipiLane, BYTE MipiEcc)
{
	MxReturnStatus_t RetStatus = MX_ERROR;

	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];
	BYTE	RdData[4];

	// Check Parameter
	if ( (SensorMode > 3) || (MipiEcc > 2)) return MX_ERROR;

	// Set Sensor Mode (MIPI/PARALLEL)
	Addr[0] = 0x02;
	WrData[0] = SensorMode;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// Set Data Type
	Addr[0] = 0x31;	// For VFE
	WrData[0] = DataType;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0] = 0x39;	// For MIPI CSI2 Rx
	WrData[0] = DataType;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// Set MIPI Lane
	Addr[0] = 0x38;
	WrData[0] = MipiLane;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// Set MIPI Ecc
	Addr[0] = 0x3A;
	RetStatus = MxI2CRead(DeviceIndex, ChipID, Addr, RdData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	WrData[0] = (RdData[0] & 0xFE) | (MipiEcc);
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// Set Image Size
	RetStatus = MxSetImageSize(DeviceIndex, ImageWidth, ImageHeight);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// DVP RAW10/RAW12/RAW14 Data Align Settings
	Addr[0] = 0x04;
	WrData[0] = 0x00;
	if (SensorMode == MX_SENSOR_PARALLEL) {
		if (DataType ==  MX_DT_RAW10)	WrData[0] = 0x01;
		else if (DataType ==  MX_DT_RAW10) WrData[0] = 0x02;
		else WrData[0] = 0x03;
	}

	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	// Set Packet Count
	double FrameSizeByte = ImageWidth * ImageHeight * 2;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxSetHwPlay(char DeviceIndex)
{
	MxReturnStatus_t RetStatus = MX_ERROR;
	BYTE	ChipID = 0xA4;
	BYTE	Addr[4];
	BYTE	WrData[4];

	Addr[0] = 0x08;
	WrData[0] = 0x01;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	Addr[0] = 0x03;
	WrData[0] = 0x01;
	RetStatus = MxI2CWrite(DeviceIndex, ChipID, Addr, WrData, MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if (RetStatus == MX_ERROR) return MX_ERROR;

	return MX_SUCCESS;
}

MxReturnStatus_t MarblixUsb3::MxGetImageFrame(char DeviceIndex, BYTE* pImageData,WORD Width, WORD Height, INT64* pTimeStamp)
{

	MxReturnStatus_t RetStatus = MX_ERROR;


	LONG	BufferSize	= pMxDevice[DeviceIndex]->BulkInEndPt->MaxPktSize * m_PktCnt * sizeof(BYTE);
	ULONG	TimeOut		= m_TimeOut;
	//int nSize = 1280 * 1024;
	BufferSize = Width * Height;

	//ULONG nsizen = pMxDevice[DeviceIndex]->BulkInEndPt->GetXferSize();
	if (pMxDevice[DeviceIndex]->BulkInEndPt)
	{
		pMxDevice[DeviceIndex]->BulkInEndPt->SetXferSize((ULONG)BufferSize);
		pMxDevice[DeviceIndex]->BulkInEndPt->TimeOut = TimeOut;
		if(!pMxDevice[DeviceIndex]->BulkInEndPt->XferData(pImageData,BufferSize))
		{
			//pMxDevice[DeviceIndex]->BulkInEndPt->Reset();
			(*pTimeStamp)++;
			//TRACE(_T("Data Error %d\n"),&pTimeStamp);
			//printf("Fx3 Get Data Error!\r\n");
			return MX_ERROR;
		}
	}


	return MX_SUCCESS;
}