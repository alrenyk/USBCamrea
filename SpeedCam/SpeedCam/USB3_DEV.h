//#############################################################################
// Copyright 2018 TakeRix Co., Ltd
// FX3 USB Control Device
// USB3_DEV.h
// Version 1.1.0
// alren@takerix.com
//#############################################################################


#pragma once

#include ".\lib\CyAPI.h"
#include <initguid.h>
#include <dbt.h>

typedef unsigned int ReturnStatus;

enum _ErrorCode_
{
	_SUCCESS_USB = 0,
	_ERROR_USB_DISCONNECTED = 1,
	_ERROR_I2C_WRITE = 2,
	_ERROR_I2C_READ = 3,
	_ERROR_USB = 4
};

//i2c Protocol
enum I2CProtocol_t
{
	MX_I2C_A1D1_,	//8bit 8bit
	MX_I2C_A1D2_,	//8bit 16bit
	MX_I2C_A2D1_,	//16bit 8bit
	MX_I2C_A2D2_		//16bit 16bit
};

#define MX_I2C_100K			0	//i2c speed
#define MX_I2C_400K			1	//i2c speed
#define MX_I2C_NORMAL		0

#define MX_SENSOR_PARALLEL	0
#define MX_SENSOR_MIPI		1
#define MX_SESNOR_BT656		2

class CUSB3_DEV
{
public:
	CUSB3_DEV(void);
	virtual ~CUSB3_DEV(void);

private:
	ULONG	m_TimeOut;
	int		m_PktCnt;

public:
	CCyUSBDevice* m_UsbDevice;
	CCyFX3Device* m_FxDevice;
	CCyUSBEndPoint* BulkInEndPt_;
	UCHAR DevCnt;//Device Conut;
	USHORT VendorID, ProductID;
	UCHAR EndPointCount;
	bool IsUSBOpen;
	CString strDeviceData;
	CString sMenu;
	CString sProduct;

public:
	ReturnStatus	I2CWrite(BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
								BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode);
	ReturnStatus	I2CRead(BYTE ChipID, BYTE* pAddr, BYTE* pRdData,
								BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode);
	ReturnStatus	GetImageFrame(PUCHAR pImageData, INT64* pTimeStamp);
	ReturnStatus	DeviceOpen();
	ReturnStatus	Device_Check();
};

