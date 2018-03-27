
// SpeedCam.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "SpeedCam.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "SpeedCamDoc.h"
#include "SpeedCamView.h"
//#include "DockPanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSpeedCamApp

BEGIN_MESSAGE_MAP(CSpeedCamApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CSpeedCamApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_FILE_OPEN, &CSpeedCamApp::OnFileOpen)
END_MESSAGE_MAP()


// CSpeedCamApp construction

CSpeedCamApp::CSpeedCamApp()
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("SpeedCam.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CSpeedCamApp object

CSpeedCamApp theApp;


// CSpeedCamApp initialization

BOOL CSpeedCamApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_SpeedCamTYPE,
		RUNTIME_CLASS(CSpeedCamDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CSpeedCamView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;
	// call DragAcceptFiles only if there's a suffix
	//  In an MDI app, this should occur immediately after setting m_pMainWnd

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	//mdi new window off
	//cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;

	//if (cmdInfo.m_nShellCommand != CCommandLineInfo::FileNew && !ProcessShellCommand(cmdInfo))
	// The main window has been initialized, so show and update it

	
	//if ( cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew )
	//{
	//	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing ;
	//}

	// Dispatch commands specified on the command line
	//if (!ProcessShellCommand(cmdInfo))
	//	return FALSE;

	//if (cmdInfo.m_nShellCommand != CCommandLineInfo::FileNew && !ProcessShellCommand(cmdInfo))

	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	Default_InitValue();

	return TRUE;
}

void CSpeedCamApp::Default_InitValue()
{
	//#########################################################################
	// 0. Create Class USB Device
	//#########################################################################
#if 1
	m_Usb3Device = new CUSB3_DEV();
	m_MxUsb3 = new MarblixUsb3();

	MxConfigParam.m_DeviceIndex		= 1;
	MxConfigParam.m_SensorMode		= MX_SENSOR_PARALLEL;
	MxConfigParam.m_TimeStamp		= 10;
	MxConfigParam.m_ImageWidth		= 1280;//1600;
	MxConfigParam.m_ImageHeight		= 960;// 896 960 1024 1088 1152
	MxConfigParam.m_Resistor_Mode = true;	//is FPGA i2C MODE

	CWinApp *pApp = AfxGetApp(); 
	CMainFrame *pFrame = (CMainFrame*)pApp->GetMainWnd();
	pFrame->m_DockPanel.GetImageSize();

	MessageOutput(_T(">> Loading Application....."));
	
	//m_UsbConnect_Thread = AfxBeginThread(USB_CheckThread, (LPVOID)this, 0, CREATE_SUSPENDED);

	m_pFormatRGB = new CFormatRGB(MxConfigParam.m_ImageWidth,MxConfigParam.m_ImageHeight);
	m_pFormatRGB->SetBuffer();

	m_pFormatConvert = new CFormatConvert();
	m_Set_FitSize = true;	//set fit image size

	OnFileNew();//Debug Mode

#endif
	//int nSize = 16384;
	//m_pBits = new BYTE[nSize];
	//ZeroMemory(m_pBits, nSize);


}

void CSpeedCamApp::USB_OpenDevice()
{
	//#########################################################################
	// 1. USB Device Open
	//#########################################################################
	MxReturnStatus_t RetStatus = MX_ERROR;
	m_Usb3Device->DeviceOpen();

	RetStatus = m_MxUsb3->MxDeviceOpen(MxConfigParam.m_DeviceIndex);
	if(RetStatus == MX_SUCCESS)
	{
		USB_Open = true;
	}
	else
	{
		USB_Open = false;
	}
	
}

void CSpeedCamApp::USB_I2C_Write(BYTE Chip_ID, BYTE Addr, BYTE Data)
{
	//ReturnStatus RetStatus = _ERROR_USB;
	MxReturnStatus_t RetStatus = MX_ERROR;

	BYTE	ChipID_W = Chip_ID;
	BYTE	Addr_W[4];
	BYTE	WrData_W[4];

	Addr_W[0] = Addr;
	WrData_W[0] = Data;

	//FPGA MODE
	RetStatus = m_MxUsb3->MxI2CWrite(MxConfigParam.m_DeviceIndex, ChipID_W, Addr_W, WrData_W,
		MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);
	if(RetStatus == MX_ERROR)
	{
		MessageOutput(_T(">>I2C Write False..............................................."));
	}
}


void CSpeedCamApp::USB_I2C_Read(BYTE Chip_ID, BYTE Addr, BYTE Data)
{

	MxReturnStatus_t RetStatus = MX_ERROR;

	BYTE	ChipID_R = Chip_ID;
	BYTE	Addr_R[4];
	BYTE	RdData_R[4];

	Addr_R[0] = Addr;

	RetStatus = m_MxUsb3->MxI2CRead(MxConfigParam.m_DeviceIndex, ChipID_R, Addr_R, RdData_R,
		MX_I2C_100K, MX_I2C_A1D1, MX_I2C_NORMAL);

	
	if(MxConfigParam.m_Resistor_Mode == true)
	{
		//FPGA MODE
		CString read_data8;
		read_data8.Format(TEXT(">>Return Read Date = id : 0x%02X,  addr : 0x%02X,  Readdata : 0x%02X"), Chip_ID, Addr, RdData_R[0]);

		MessageOutput(read_data8);

		CMainFrame *pOutView = (CMainFrame*)AfxGetMainWnd();
		read_data8.Format(TEXT("   Read Date = [ 0x%02X ]"), RdData_R[0]);
		pOutView->m_DockPanel.m_Device_ControlDlg.m_TextReadValue.SetWindowTextW(read_data8);
	}else

	{
		CString read_data8;
		read_data8.Format(TEXT("   Read Date = [ 0x%02X ]"), RdData_R[0]);
		S_RdData_R[0] = RdData_R[0];
	}

	if(RetStatus == MX_ERROR)
	{
		MessageOutput(_T(">>I2C Read False..............................................."));
	}

}

int CSpeedCamApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	/*
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}
	*/
	//delete [] m_pBits;
	Close();

	return CWinAppEx::ExitInstance();
}

// CSpeedCamApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// App command to run the dialog
void CSpeedCamApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSpeedCamApp customization load/save methods

void CSpeedCamApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CSpeedCamApp::LoadCustomState()
{
}

void CSpeedCamApp::SaveCustomState()
{
}

//Play USB
void CSpeedCamApp::UsbConnect()
{	
	MxReturnStatus_t RetStatus = MX_ERROR;
	ReturnStatus RetStatus_ = _SUCCESS_USB;
	INT64* Time_Stp;
	INT64 nt = 1;

	Time_Stp = &nt;
	ULONG	TimeOut;
	TimeOut = 20;
	//BufferSize = 16384;
	int nfalse =1;
	//ULONG error;
	bResult = false;
	int CurTime, LastTime;
	
	CurTime = GetTickCount();
	nTest ++;
	
#if 1
		
		RetStatus = m_MxUsb3->MxGetImageFrame(MxConfigParam.m_DeviceIndex, m_pFormatRaw8->m_pBits,MxConfigParam.m_ImageWidth,MxConfigParam.m_ImageHeight,  &MxConfigParam.m_TimeStamp);
		if(RetStatus == MX_SUCCESS)
		{
			LastTime = GetTickCount();
			MxConfigParam.m_DisplayFPS = 1000.0f/(float)(LastTime - CurTime);
			//TRACE(_T("Data Out OK!\r\n"));
			printf("Fx3 Get Data OK!\r\n");

			bResult = m_pFormatConvert->ConvBayer8_Gray(*m_pFormatRaw8, *m_pFormatRGB, 0);
			//GetData = m_pFormatRGB->GetBits();
			PBYTE Gdata = m_pFormatRGB->GetBits();
			TRACE(_T("Thread1 %d\r\n"),nTest);
#if 0
			if(bResult){
			CWinApp *pApp = AfxGetApp(); 
			CMainFrame *pFrame = (CMainFrame*)pApp->GetMainWnd();
			pFrame->m_DockImageView.m_ImageView_Dlg.ShowImage(m_pFormatRGB->GetBits(),(int)MxConfigParam.m_ImageHeight, (int)MxConfigParam.m_ImageWidth );
			pFrame->m_DockImageView.Invalidate(true);
			//SpeedCamView *pView = (CSpeedCamView*)pFrame->GetActiveView();
			//pView->TestBMP(m_pFormatRGB->GetBits(), CClientRect);
			//pView->ShowImage();
			//MessageOutput(_T("Data Get Sucssec.."));
			m_nFrameRate++;
			}
			LastTime = GetTickCount();
			MxConfigParam.m_DisplayFPS = 1000.0f/(float)(LastTime - CurTime);
#endif
			if(bResult){
				m_nFrameRate++;
			}
			

			//m_DockPanel.m_Device_ControlDlg.m_TextReadValue.SetWindowTextW(read_data8);
		}
		else
		{
			printf("Fx3 Get Data Error!\r\n");
#if 0
			CWinApp *pApp = AfxGetApp(); 
			CMainFrame *pFrame = (CMainFrame*)pApp->GetMainWnd();
			pFrame->m_DockImageView.m_ImageView_Dlg.TestImageShow((int)MxConfigParam.m_ImageHeight, (int)MxConfigParam.m_ImageWidth);
#endif
		}

		
#else

#endif

	m_csData.SetEvent();
}

void CSpeedCamApp::UpdateWindowView()
{

}


void CSpeedCamApp::Thread_Start()
{
#if 1
	m_pFormatRaw8 = new CFormatBayer8(MxConfigParam.m_ImageWidth, MxConfigParam.m_ImageHeight);
	m_pFormatRaw8->SetBuffer();
	m_Usb3Device->DeviceOpen();

	//CMainFrame *pOutView = (CMainFrame*)AfxGetMainWnd();
	//pOutView->m_DockPanel.m_Device_ControlDlg.m_BtnStop.EnableWindow(false);	//stop butten enable
	//pOutView->m_DockPanel.m_Device_ControlDlg.m_Radio_Sensor.EnableWindow(true);	//play butten enable

	m_UsbConnect_Thread = AfxBeginThread(USB_CheckThread, (LPVOID)this, 0, CREATE_SUSPENDED);
	//arg1.hwnd = this->m_hWnd;
	//m_UsbConnect_Thread = AfxBeginThread(USB_CheckThread, arg1, THREAD_PRIORITY_NORMAL,0,0);
	MessageOutput(_T(">>Play..."));
	
	//CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	//CSpeedCamView *pView = (CSpeedCamView*)pFrame->GetActiveView();
	//pView->TestBMP();
#endif
}

UINT CSpeedCamApp::USB_CheckThread(LPVOID lParam)
{
	
	CSpeedCamApp* pUSB = (CSpeedCamApp*)lParam;
	pUSB->bThred_Flag = true;
	BYTE chip = 0x76;
	BYTE add = 0x0d;
	BYTE data = 0x00;
	pUSB->USB_I2C_Write(chip,add, data);
	data = 0x01;
	pUSB->USB_I2C_Write(chip,add, data);
#if 1
	while(pUSB->bThred_Flag)
	{		
		if(pUSB->bThred_Flag == false)
		{
			CWinApp *pApp = AfxGetApp(); 
			CMainFrame *pFrame = (CMainFrame*)pApp->GetMainWnd();
			CSpeedCamView *pview = (CSpeedCamView*)AfxGetApp();
			//pview->bThred_VeiwFlag;
		}
		pUSB->UsbConnect();
	}
#else
	for(int i =0; i<4000 ; i++)
	{
		pUSB->UsbConnect();
	}
#endif

	//pUSB->bThred_Flag = false;
	//::WaitForSingleObject(USB_CheckThread, INFINITE);
	//ExitThread(0);

	return 0;
}

// CSpeedCamApp message handlers

void CSpeedCamApp::Close()
{
	MessageOutput(_T(">> Closed Application"));
	
	bThred_Flag = false;
	//CSpeedCamView *pView = (CSpeedCamView*)AfxGetMainWnd();
	//pView->bThred_VeiwFlag = false;
}

void CSpeedCamApp::MessageOutput(CString strMsg)
{

	CMainFrame *pOutView = (CMainFrame*)AfxGetMainWnd();
	if(pOutView != NULL)
	{
		pOutView->m_wndOutput.m_wndOutputBuild.AddString(strMsg);
		pOutView->m_wndOutput.SendMessage(WM_VSCROLL, SB_BOTTOM);
		pOutView->m_wndOutput.m_wndOutputBuild.SetTopIndex(pOutView->m_wndOutput.m_wndOutputBuild.GetCount()-1);
	}
}



void CAboutDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnClose();
}


void CSpeedCamApp::OnFileOpen()
{
	// TODO: Add your command handler code here
	TRACE(_T("Test"));
}

void CSpeedCamApp::SaveToBmp(CString strPath)
{
	//CSpeedCamView *pview = (CSpeedCamView*)AfxGetApp();
	//pview->DrawSave(strPath);
	if(USB_Open == true)
	{
		bResult = m_pFormatConvert->Save2BMP(strPath, *m_pFormatRGB);
		if(bResult)
		{
			CString Temp;
			Temp.Format(TEXT(">>Image Capture File Save....."));
			MessageOutput(Temp);
			MessageOutput(strPath);
		}
	}
}