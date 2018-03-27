//#############################################################################
// Copyright 2012-2014 People & Chips Co., Ltd
// MARBLIX¢â-U
// MarblixUsb3.h
// Version 1.0.2	July 24, 2014
// joe@peoplechips.co.kr
//#############################################################################
#pragma once

#include ".\lib\CyAPI.h"
#include <initguid.h>
#include <dbt.h>

typedef unsigned int MxReturnStatus_t;

enum MxErrorCode_t
{
	MX_SUCCESS = 0,
	MX_ERROR_USB_DISCONNECTED,
	MX_ERROR_POWER_RANGE,
	MX_ERROR_POWER_CH_SEL,
	MX_ERROR_MCLK_CFG,
	MX_ERROR_MCLK_RANGE,
	MX_ERROR
};

enum MxPowerChannel_t
{
	MX_PWR_CH0,
	MX_PWR_CH1,
	MX_PWR_CH2,
	MX_PWR_CH3,
	MX_PWR_CH4,
	MX_PWR_IO
};

enum MxDataType_t
{
	MX_DT_YUV422_8BIT	= 0x1E,
	MX_DT_RGB888		= 0x24,
	MX_DT_RGB565		= 0x22,
	MX_DT_RAW8			= 0x2A,
	MX_DT_RAW10			= 0x2B,
	MX_DT_YUV420_8BIT	= 0x1A, // Legacy
	MX_DT_YUV420_10BIT	= 0x19,	// TBD
	MX_DT_YUV422_10BIT	= 0x1F,
	MX_DT_RGB666		= 0x23,
	MX_DT_RGB555		= 0x21, // TBD
	MX_DT_RGB444		= 0x20,
	MX_DT_RAW6			= 0x28, // TBD
	MX_DT_RAW7			= 0x29, // TBD
	MX_DT_RAW12			= 0x2C,
	MX_DT_RAW14			= 0x2D
};

#define MX_BOOT_HW			0
#define MX_BOOT_USB			1

#define MX_FW_RAM			0
#define MX_FW_SPI			1	// TBD
#define MX_FW_EEPROM		2	// TBD

#define	MX_STATE_LOW		0
#define MX_STATE_HIGH		1

#define MX_MCLK_PROG		0
#define MX_MCLK_FIXED		1

#define MX_POL_NORMAL		0
#define MX_POL_INVERSION	1

#define MX_SENSOR_PARALLEL	0
#define MX_SENSOR_MIPI		1
#define MX_SESNOR_BT656		2

#define MX_MIPI_ECC_OFF		0
#define MX_MIPI_ECC_ON		1

#define MX_POWER_OFF		0
#define MX_POWER_ON			1

#define MX_I2C_100K			0
#define MX_I2C_400K			1
#define MX_I2C_NORMAL		0

enum MxI2CProtocol_t
{
	MX_I2C_A1D1,
	MX_I2C_A1D2,
	MX_I2C_A2D1,
	MX_I2C_A2D2
};

#define	MX_VID		0x04B4
#define	MX_PID_0	0x00F0
#define	MX_PID_1	0x00F1
#define	MX_PID_2	0x00F2
#define	MX_PID_3	0x00F4
#define	MX_PID_BOOT	0x00F3

class MarblixUsb3
{
public:
	MarblixUsb3(void);
	virtual ~MarblixUsb3(void);

public:
	CCyUSBDevice*		pMxDevice[4]; //USB 3.0A, USB 3.0B, USB 3.0C, USB 3.0D
	CCyFX3Device*		pFx3Device;

public:
	ULONG	m_TimeOut;
	int		m_PktCnt;

private:
	int CalOTCData(float data, bool MKhz);
	int MyPow(int to1,int to2);
	MxReturnStatus_t	MxSetPwrDAC(char DeviceIndex, BYTE PwrChannel, int Vdata);
	MxReturnStatus_t	MxSetImageSize(char DeviceIndex, WORD ImageWidth, WORD ImageHeight);

public:
	MxReturnStatus_t	MxFWDownLoad(char DeviceIndex, CString sFileName, BYTE TargetMemory);
	MxReturnStatus_t	MxDeviceOpen(char DeviceIndex);
	MxReturnStatus_t	MxSetSensorClock(char DeviceIndex, BYTE MclkMode, float TargetFreq);
	MxReturnStatus_t	MxSetSensorPower(char DeviceIndex, BYTE PwrChannel, float TargetVolt);
	MxReturnStatus_t	MxSetSensorReset(char DeviceIndex, BYTE ResetState);
	MxReturnStatus_t	MxSetSensorEnable(char DeviceIndex, BYTE EnableState);
	MxReturnStatus_t	MxSetVsyncPolarity(char DeviceIndex, BYTE VsyncPolarity);
	MxReturnStatus_t	MxSetHsyncPolarity(char DeviceIndex, BYTE HsyncPolarity);
	MxReturnStatus_t	MxSetPclkPolarity(char DeviceIndex, BYTE PclkPolarity);
	MxReturnStatus_t	MxI2CWrite(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
								   BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode);
	MxReturnStatus_t	MxI2CRead(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pRdData,
								  BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode);
	MxReturnStatus_t	MxI2CWriteBurst(char DeviceIndex, BYTE ChipID, BYTE* pAddr, BYTE* pWrData,
										BYTE I2CSpeed, BYTE I2CProtocol, BYTE I2CMode);
	MxReturnStatus_t	MxI2CRWTest(char DeviceIndex, BYTE I2CSpeed, BYTE I2CMode, int LoopCnt);
	MxReturnStatus_t	MxSetImageParameter(char DeviceIndex, BYTE SensorMode, BYTE DataType,
											WORD ImageWidth, WORD ImageHeight, BYTE MipiLane, BYTE MipiEcc);
	MxReturnStatus_t	MxSetPwrChOnOff(char DeviceIndex, BYTE PwrChannel, BYTE PwrState);
	MxReturnStatus_t	MxSetHwPlay(char DeviceIndex);
	MxReturnStatus_t	MxGetImageFrame(char DeviceIndex, BYTE* pImageData,WORD Width, WORD Height, INT64* pTimeStamp);
};