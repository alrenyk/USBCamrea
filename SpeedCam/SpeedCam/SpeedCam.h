
// SpeedCam.h : main header file for the SpeedCam application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif


#include "resource.h"       // main symbols
#include "USB3_DEV.h"		//USB Device Header
#include "FormatConvert.h"
#include "FormatYCbCr.h"
#include "FormatRGB.h"
#include "MarblixUsb3.h"
// CSpeedCamApp:
// See SpeedCam.cpp for the implementation of this class
//

typedef struct _MX_CONFIGURATION_PARAM
{
	BYTE				m_BootMode;
	char				m_DeviceIndex;
	BYTE				m_SensorMode;
	BYTE				m_DataType;
	WORD				m_ImageWidth;
	WORD				m_ImageHeight;
	BYTE				m_MipiLane;
	BYTE				m_MipiEcc;
	BYTE				m_PixelOrder;
	BYTE				m_I2CChipID;
	BYTE				m_I2CSpeed;
	BYTE				m_I2CProtocol;
	BYTE				m_I2CMode;
	bool				m_Resistor_Mode;	//true; //FGPA MODE false //Sensor Mode

	float				m_PowerIO_Volt;
	float				m_PowerCh0_Volt;
	float				m_PowerCh1_Volt;
	float				m_PowerCh2_Volt;
	float				m_PowerCh3_Volt;
	float				m_PowerCh4_Volt;

	float				m_MCLK;

	BYTE				m_PclkPolarity;
	BYTE				m_VsyncPolarity;
	BYTE				m_HsyncPolarity;

	INT64				m_TimeStamp;
	ULONG				m_FrameSize;	// Byte

	float				m_DisplayFPS;

} MxConfigParam_t;

typedef unsigned int        UINT;

class CSpeedCamApp : public CWinAppEx
{
public:
	CSpeedCamApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	//#############################################################################
	// MARBLIX¢â-U
	//#############################################################################
	CUSB3_DEV*	m_Usb3Device;
	MxConfigParam_t		MxConfigParam;
	MarblixUsb3*		m_MxUsb3;
	CFormatConvert*		m_pFormatConvert;
	CFormatBayer8*		m_pFormatRaw8;
	CFormatBayer10*		m_pFormatRaw10;
	CFormatYCbCr*		m_pFormatYCbCr;
	CFormatRGB*			m_pFormatRGB;

	CEvent m_csData;

	void UsbConnect();
	void MessageOutput(CString strMsg);
	void USB_OpenDevice();
	void USB_I2C_Write(BYTE Chip_ID, BYTE Addr, BYTE Data);
	void USB_I2C_Read(BYTE Chip_ID, BYTE Addr, BYTE Data);
	CWinThread*	m_UsbConnect_Thread;//USB connect checker thread
	void Thread_Start();
	static UINT USB_CheckThread(LPVOID lParam);
	void Default_InitValue();
	void Close();
	CRect CClientRect;
	void UpdateWindowView();
	bool bResult;
	void SaveToBmp(CString strPath);

	bool m_Set_FitSize;
	//BYTE* GetData;



public:
	bool USB_Open;
	bool bThred_Flag;
	UCHAR nUSB_Conut;
	PBYTE m_pBits;	//Recevice Data
	BYTE	S_RdData_R[4];
	int m_nFrameRate;
	int nTest;

	//PUCHAR			*buffers;	//recevice buffer
	
	afx_msg void OnFileOpen();
};

extern CSpeedCamApp theApp;
