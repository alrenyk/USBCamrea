// DockPanel.cpp : implementation file
//

#include "stdafx.h"
#include "SpeedCam.h"
#include "DockPanel.h"
#include "MainFrm.h"
#include "resource.h"


// DockPanel

IMPLEMENT_DYNAMIC(DockPanel, CDockablePane)

DockPanel::DockPanel()
{
	EnableAutomation();
}

DockPanel::~DockPanel()
{
}


BEGIN_MESSAGE_MAP(DockPanel, CDockablePane)

	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// DockPanel message handlers


int DockPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_Device_ControlDlg.Create(IDD_DIALOG_CONTROL, this);
	m_Device_ControlDlg.ShowWindow(SW_SHOW);

	SetTimer(1394, 100, NULL);//set timer
	InitSetup();

	return 0;
}


void DockPanel::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	m_Device_ControlDlg.SetFocus();
}


void DockPanel::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_Device_ControlDlg.MoveWindow(0, 0, cx, cy);
	UpdateWindow();
}

HTREEITEM hRoot;
HTREEITEM hRoot1;
HTREEITEM  hChild;
HTREEITEM  hChild1;
HTREEITEM  hChild2;
HTREEITEM  hChild3;
HTREEITEM  hChild4;
void DockPanel::InitSetup()
{
	nON_USB = 0;
	nOFF_USB = 0;
	//hRoot = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(L"USB DEVICE Not Connected") ;
	//hChild = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(L"USB PID",hRoot) ;

	m_Device_ControlDlg.m_FitImagSize.SetCheck(true);	//set fit image;

	m_Device_ControlDlg.m_EditInput_ID.SetLimitText(2);
	m_Device_ControlDlg.m_EditInput_Add.SetLimitText(4);
	m_Device_ControlDlg.m_EditInput_Data.SetLimitText(4);

	m_Device_ControlDlg.Usb_TreeCtrl.Expand(hRoot, TVE_EXPAND);
	m_Device_ControlDlg.Usb_TreeCtrl.SetFocus();

	m_Device_ControlDlg.m_EditInput_ID.SetWindowTextW(_T("76"));	//device chip id input box
	m_Device_ControlDlg.m_EditInput_Add.SetWindowTextW(_T("0000"));	//device Address input box
	m_Device_ControlDlg.m_EditInput_Data.SetWindowTextW(_T("0000"));	//device Data input box
	m_Device_ControlDlg.m_Radio_Internel.SetCheck(1);
	m_Device_ControlDlg.m_nTimeout.SetWindowTextW(_T("500"));
	m_Device_ControlDlg.m_BtnStop.EnableWindow(false);		//stop butten enable
	m_Device_ControlDlg.m_Radio_Sensor.EnableWindow(true);	//play butten disable
	m_Device_ControlDlg.m_SaveBtn.EnableWindow(false);		//save butten disable
	m_Device_ControlDlg.m_BtnSctip.EnableWindow(true);		//script open button enable

	//Adress bit control
	m_Device_ControlDlg.m_ABit_16.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit16.SetBuddy(GetDlgItem(IDC_EDIT_ABIT16));
	m_Device_ControlDlg.m_SpainABit16.SetRange(0,1);

	m_Device_ControlDlg.m_ABit15.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit15.SetBuddy(GetDlgItem(IDC_EDIT_ABIT15));
	m_Device_ControlDlg.m_SpainABit15.SetRange(0,1);

	m_Device_ControlDlg.m_ABit14.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit14.SetBuddy(GetDlgItem(IDC_EDIT_ABIT14));
	m_Device_ControlDlg.m_SpainABit14.SetRange(0,1);

	m_Device_ControlDlg.m_ABit13.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit13.SetBuddy(GetDlgItem(IDC_EDIT_ABIT13));
	m_Device_ControlDlg.m_SpainABit13.SetRange(0,1);

	m_Device_ControlDlg.m_ABit12.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit12.SetBuddy(GetDlgItem(IDC_EDIT_ABIT12));
	m_Device_ControlDlg.m_SpainABit12.SetRange(0,1);

	m_Device_ControlDlg.m_ABit11.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit11.SetBuddy(GetDlgItem(IDC_EDIT_ABIT11));
	m_Device_ControlDlg.m_SpainABit11.SetRange(0,1);

	m_Device_ControlDlg.m_ABit10.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit10.SetBuddy(GetDlgItem(IDC_EDIT_ABIT10));
	m_Device_ControlDlg.m_SpainABit10.SetRange(0,1);

	m_Device_ControlDlg.m_ABit9.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit9.SetBuddy(GetDlgItem(IDC_EDIT_ABIT9));
	m_Device_ControlDlg.m_SpainABit9.SetRange(0,1);

	m_Device_ControlDlg.m_ABit8.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit8.SetBuddy(GetDlgItem(IDC_EDIT_ABIT8));
	m_Device_ControlDlg.m_SpainABit8.SetRange(0,1);

	m_Device_ControlDlg.m_ABit7.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit7.SetBuddy(GetDlgItem(IDC_EDIT_ABIT7));
	m_Device_ControlDlg.m_SpainABit7.SetRange(0,1);

	m_Device_ControlDlg.m_ABit6.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit6.SetBuddy(GetDlgItem(IDC_EDIT_ABIT6));
	m_Device_ControlDlg.m_SpainABit6.SetRange(0,1);

	m_Device_ControlDlg.m_ABit5.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit5.SetBuddy(GetDlgItem(IDC_EDIT_ABIT5));
	m_Device_ControlDlg.m_SpainABit5.SetRange(0,1);

	m_Device_ControlDlg.m_ABit4.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit4.SetBuddy(GetDlgItem(IDC_EDIT_ABIT4));
	m_Device_ControlDlg.m_SpainABit4.SetRange(0,1);

	m_Device_ControlDlg.m_ABit3.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit3.SetBuddy(GetDlgItem(IDC_EDIT_ABIT3));
	m_Device_ControlDlg.m_SpainABit3.SetRange(0,1);

	m_Device_ControlDlg.m_ABit2.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit2.SetBuddy(GetDlgItem(IDC_EDIT_ABIT2));
	m_Device_ControlDlg.m_SpainABit2.SetRange(0,1);

	m_Device_ControlDlg.m_ABit1.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainABit1.SetBuddy(GetDlgItem(IDC_EDIT_ABIT1));
	m_Device_ControlDlg.m_SpainABit1.SetRange(0,1);






	//data bit control
	m_Device_ControlDlg.m_DBit16.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit16.SetBuddy(GetDlgItem(IDC_EDIT_DBIT16));
	m_Device_ControlDlg.m_SpainDBit16.SetRange(0,1);

	m_Device_ControlDlg.m_DBit15.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit15.SetBuddy(GetDlgItem(IDC_EDIT_DBIT15));
	m_Device_ControlDlg.m_SpainDBit15.SetRange(0,1);

	m_Device_ControlDlg.m_DBit14.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit14.SetBuddy(GetDlgItem(IDC_EDIT_DBIT14));
	m_Device_ControlDlg.m_SpainDBit14.SetRange(0,1);

	m_Device_ControlDlg.m_DBit13.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit13.SetBuddy(GetDlgItem(IDC_EDIT_DBIT13));
	m_Device_ControlDlg.m_SpainDBit13.SetRange(0,1);

	m_Device_ControlDlg.m_DBit12.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit12.SetBuddy(GetDlgItem(IDC_EDIT_DBIT12));
	m_Device_ControlDlg.m_SpainDBit12.SetRange(0,1);

	m_Device_ControlDlg.m_DBit11.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit11.SetBuddy(GetDlgItem(IDC_EDIT_DBIT11));
	m_Device_ControlDlg.m_SpainDBit11.SetRange(0,1);

	m_Device_ControlDlg.m_DBit10.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit10.SetBuddy(GetDlgItem(IDC_EDIT_DBIT10));
	m_Device_ControlDlg.m_SpainDBit10.SetRange(0,1);

	m_Device_ControlDlg.m_DBit9.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit9.SetBuddy(GetDlgItem(IDC_EDIT_DBIT9));
	m_Device_ControlDlg.m_SpainDBit9.SetRange(0,1);

	m_Device_ControlDlg.m_DBit8.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit8.SetBuddy(GetDlgItem(IDC_EDIT_DBIT8));
	m_Device_ControlDlg.m_SpainDBit8.SetRange(0,1);

	m_Device_ControlDlg.m_DBit7.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit7.SetBuddy(GetDlgItem(IDC_EDIT_DBIT7));
	m_Device_ControlDlg.m_SpainDBit7.SetRange(0,1);

	m_Device_ControlDlg.m_DBit6.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit6.SetBuddy(GetDlgItem(IDC_EDIT_DBIT6));
	m_Device_ControlDlg.m_SpainDBit6.SetRange(0,1);

	m_Device_ControlDlg.m_DBit5.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit5.SetBuddy(GetDlgItem(IDC_EDIT_DBIT5));
	m_Device_ControlDlg.m_SpainDBit5.SetRange(0,1);

	m_Device_ControlDlg.m_DBit4.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit4.SetBuddy(GetDlgItem(IDC_EDIT_DBIT4));
	m_Device_ControlDlg.m_SpainDBit4.SetRange(0,1);

	m_Device_ControlDlg.m_DBit3.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit3.SetBuddy(GetDlgItem(IDC_EDIT_DBIT3));
	m_Device_ControlDlg.m_SpainDBit3.SetRange(0,1);

	m_Device_ControlDlg.m_DBit2.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit2.SetBuddy(GetDlgItem(IDC_EDIT_DBIT2));
	m_Device_ControlDlg.m_SpainDBit2.SetRange(0,1);

	m_Device_ControlDlg.m_DBit1.SetWindowTextW(_T("0"));
	m_Device_ControlDlg.m_SpainDBit1.SetBuddy(GetDlgItem(IDC_EDIT_DBIT1));
	m_Device_ControlDlg.m_SpainDBit1.SetRange(0,1);

	//image select combo box
	m_Device_ControlDlg.m_Combo_Img_Size.AddString(_T("640x480"));		//2
	m_Device_ControlDlg.m_Combo_Img_Size.AddString(_T("1280x960"));		//1
	m_Device_ControlDlg.m_Combo_Img_Size.AddString(_T("1280x1024"));	//0

	m_Device_ControlDlg.m_Combo_Img_Size.SetCurSel(0);
	
	
}

void DockPanel::GetImageSize()
{
	CString sTemp;
	int nSel = m_Device_ControlDlg.m_Combo_Img_Size.GetCurSel();
	m_Device_ControlDlg.m_Combo_Img_Size.GetLBText(nSel,sTemp);
	int len = sTemp.GetLength();
	int nidx = sTemp.Find('x');
	CString wd = sTemp.Left(nidx);
	CString hd = sTemp.Right(len-(nidx+1));

	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->MxConfigParam.m_ImageWidth = _ttoi(wd);
	pAPP->MxConfigParam.m_ImageHeight = _ttoi(hd);
}

void DockPanel::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CDockablePane::OnClose();
}

int nOldFrame = 0;
void DockPanel::OnTimer(UINT_PTR nIDEvent)
{

#if 1
	// TODO: Add your message handler code here and/or call default
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	if(nIDEvent == 1394)
	{
		float frame = pAPP->MxConfigParam.m_DisplayFPS;
		CString sr;
		int nframe = (int)frame;

		sr.Format(_T("Frame Rate :%3d fps"),nframe);
		m_Device_ControlDlg.m_FrameRate_Text.SetWindowTextW(sr);
		nOldFrame = nframe;

		
		if(pAPP != NULL)
		{
			pAPP->m_Usb3Device->Device_Check();
			nCount = pAPP->m_Usb3Device->DevCnt;
			bIsUsb_Con = pAPP->m_Usb3Device->IsUSBOpen;

			if((nCount >0)&&(bIsUsb_Con == true))
			{			
				if(nON_USB == 0)
				{
					hRoot = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(L"USB Camera DEVICE Connected...") ;
					USHORT PID = pAPP->m_Usb3Device->ProductID;
					//hChild = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(L"USB PID",hRoot) ;
					CString strMenu;
					strMenu.Format(_T("Manufactire [ %s ]"), CString(pAPP->m_Usb3Device->sMenu));
					hChild = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(strMenu,hRoot) ;

					strMenu.Format(_T("Product [ %s ]"), CString(pAPP->m_Usb3Device->sProduct));
					hChild1 = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(strMenu,hRoot) ;

					strMenu.Format(_T("Device Friendy Name [ %s ]"), CString(pAPP->m_Usb3Device->strDeviceData));
					hChild2 = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(strMenu,hRoot) ;

					hChild3 = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(_T("Superspeed USB Connected.."),hRoot) ;
					
					hRoot1 = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(L"USB Camera Infomation...") ;
					hChild4 = m_Device_ControlDlg.Usb_TreeCtrl.InsertItem(_T("Display size 1280 x 720"),hRoot1) ;

					m_Device_ControlDlg.Usb_TreeCtrl.Expand(hRoot, TVE_EXPAND);
					m_Device_ControlDlg.Usb_TreeCtrl.Expand(hRoot1, TVE_EXPAND);
					pAPP->MessageOutput(_T(">>USB Camera Device Conneted......"));
					
					pAPP->USB_OpenDevice();
					nON_USB = 1;
					nOFF_USB = 0;
					
				}
				
			}
			else if(bIsUsb_Con == false){
				if(nOFF_USB == 0)
				{
					m_Device_ControlDlg.Usb_TreeCtrl.DeleteAllItems();
					pAPP->MessageOutput(_T(">>USB Camera Device not Conneted......"));

					nOFF_USB = 1;
					nON_USB = 0;
				}
			}
		}
	}
	//KillTimer(1394);
#endif
	CDockablePane::OnTimer(nIDEvent);

}
