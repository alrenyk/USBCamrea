// Device_Control.cpp : implementation file
//

#include "stdafx.h"
#include "SpeedCam.h"
#include "Device_Control.h"
#include "afxdialogex.h"
#include "stdio.h"

//#include "MainFrm.h"
//#include "SpeedCamView.h"

// Device_Control dialog

IMPLEMENT_DYNAMIC(Device_Control, CDialogEx)

Device_Control::Device_Control(CWnd* pParent /*=NULL*/)
	: CDialogEx(Device_Control::IDD, pParent)
	
{

}

Device_Control::~Device_Control()
{
}

void Device_Control::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_DEVICE_TREE, Usb_TreeCtrl);
	DDX_Control(pDX, IDC_BUTTON_REG_WRITE, m_i2c_Write_Btn);
	DDX_Control(pDX, IDC_EDIT_DEVICE_ID_EDITCONTROL, m_EditInput_ID);
	DDX_Control(pDX, IDC_EDIT_ADD_EDITCONTROL, m_EditInput_Add);
	DDX_Control(pDX, IDC_EDIT_DATA_EDITCONTROL, m_EditInput_Data);
	DDX_Control(pDX, IDC_STATIC_READ, m_TextReadValue);
	DDX_Control(pDX, IDC_RADIO_Internel_Setting, m_Radio_Internel);
	DDX_Control(pDX, IDC_BUTTON1_PLAY, m_Radio_Sensor);
	DDX_Control(pDX, IDC_EDIT1, m_nTimeout);
	DDX_Control(pDX, IDC_STATIC_FRAME, m_FrameRate_Text);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_BtnStop);
	DDX_Control(pDX, IDC_EDIT_ABIT16, m_ABit_16);
	DDX_Control(pDX, IDC_SPIN_ABIT16, m_SpainABit16);
	DDX_Control(pDX, IDC_EDIT_ABIT15, m_ABit15);
	DDX_Control(pDX, IDC_EDIT_ABIT14, m_ABit14);
	DDX_Control(pDX, IDC_EDIT_ABIT13, m_ABit13);
	DDX_Control(pDX, IDC_EDIT_ABIT12, m_ABit12);
	DDX_Control(pDX, IDC_EDIT_ABIT11, m_ABit11);
	DDX_Control(pDX, IDC_EDIT_ABIT10, m_ABit10);
	DDX_Control(pDX, IDC_EDIT_ABIT9, m_ABit9);
	DDX_Control(pDX, IDC_EDIT_ABIT8, m_ABit8);
	DDX_Control(pDX, IDC_EDIT_ABIT7, m_ABit7);
	DDX_Control(pDX, IDC_EDIT_ABIT6, m_ABit6);
	DDX_Control(pDX, IDC_EDIT_ABIT5, m_ABit5);
	DDX_Control(pDX, IDC_EDIT_ABIT4, m_ABit4);
	DDX_Control(pDX, IDC_EDIT_ABIT3, m_ABit3);
	DDX_Control(pDX, IDC_EDIT_ABIT2, m_ABit2);
	DDX_Control(pDX, IDC_EDIT_ABIT1, m_ABit1);
	DDX_Control(pDX, IDC_SPIN_ABIT1, m_SpainABit1);
	DDX_Control(pDX, IDC_SPIN_ABIT2, m_SpainABit2);
	DDX_Control(pDX, IDC_SPIN_ABIT3, m_SpainABit3);
	DDX_Control(pDX, IDC_SPIN_ABIT4, m_SpainABit4);
	DDX_Control(pDX, IDC_SPIN_ABIT5, m_SpainABit5);
	DDX_Control(pDX, IDC_SPIN_ABIT6, m_SpainABit6);
	DDX_Control(pDX, IDC_SPIN_ABIT7, m_SpainABit7);
	DDX_Control(pDX, IDC_SPIN_ABIT8, m_SpainABit8);
	DDX_Control(pDX, IDC_SPIN_ABIT9, m_SpainABit9);
	DDX_Control(pDX, IDC_SPIN_ABIT10, m_SpainABit10);
	DDX_Control(pDX, IDC_SPIN_ABIT11, m_SpainABit11);
	DDX_Control(pDX, IDC_SPIN_ABIT12, m_SpainABit12);
	DDX_Control(pDX, IDC_SPIN_ABIT13, m_SpainABit13);
	DDX_Control(pDX, IDC_SPIN_ABIT14, m_SpainABit14);
	DDX_Control(pDX, IDC_SPIN_ABIT15, m_SpainABit15);
	DDX_Control(pDX, IDC_EDIT_DBIT1, m_DBit1);
	DDX_Control(pDX, IDC_EDIT_DBIT2, m_DBit2);
	DDX_Control(pDX, IDC_EDIT_DBIT3, m_DBit3);
	DDX_Control(pDX, IDC_EDIT_DBIT4, m_DBit4);
	DDX_Control(pDX, IDC_EDIT_DBIT5, m_DBit5);
	DDX_Control(pDX, IDC_EDIT_DBIT6, m_DBit6);
	DDX_Control(pDX, IDC_EDIT_DBIT7, m_DBit7);
	DDX_Control(pDX, IDC_EDIT_DBIT8, m_DBit8);
	DDX_Control(pDX, IDC_EDIT_DBIT9, m_DBit9);
	DDX_Control(pDX, IDC_EDIT_DBIT10, m_DBit10);
	DDX_Control(pDX, IDC_EDIT_DBIT11, m_DBit11);
	DDX_Control(pDX, IDC_EDIT_DBIT12, m_DBit12);
	DDX_Control(pDX, IDC_EDIT_DBIT13, m_DBit13);
	DDX_Control(pDX, IDC_EDIT_DBIT14, m_DBit14);
	DDX_Control(pDX, IDC_EDIT_DBIT15, m_DBit15);
	DDX_Control(pDX, IDC_EDIT_DBIT16, m_DBit16);
	DDX_Control(pDX, IDC_SPIN_DBIT1, m_SpainDBit1);
	DDX_Control(pDX, IDC_SPIN_DBIT2, m_SpainDBit2);
	DDX_Control(pDX, IDC_SPIN_DBIT3, m_SpainDBit3);
	DDX_Control(pDX, IDC_SPIN_DBIT4, m_SpainDBit4);
	DDX_Control(pDX, IDC_SPIN_DBIT5, m_SpainDBit5);
	DDX_Control(pDX, IDC_SPIN_DBIT6, m_SpainDBit6);
	DDX_Control(pDX, IDC_SPIN_DBIT7, m_SpainDBit7);
	DDX_Control(pDX, IDC_SPIN_DBIT8, m_SpainDBit8);
	DDX_Control(pDX, IDC_SPIN_DBIT9, m_SpainDBit9);
	DDX_Control(pDX, IDC_SPIN_DBIT10, m_SpainDBit10);
	DDX_Control(pDX, IDC_SPIN_DBIT11, m_SpainDBit11);
	DDX_Control(pDX, IDC_SPIN_DBIT12, m_SpainDBit12);
	DDX_Control(pDX, IDC_SPIN_DBIT13, m_SpainDBit13);
	DDX_Control(pDX, IDC_SPIN_DBIT14, m_SpainDBit14);
	DDX_Control(pDX, IDC_SPIN_DBIT15, m_SpainDBit15);
	DDX_Control(pDX, IDC_SPIN_DBIT16, m_SpainDBit16);
	DDX_Control(pDX, IDC_COMBO_IMG_SIZE, m_Combo_Img_Size);
	DDX_Control(pDX, IDC_BUTTON_SAV_IMG, m_SaveBtn);

	DDX_Control(pDX, IDC_CHECK_SIZE, m_FitImagSize);
	DDX_Control(pDX, IDC_BUTTON_SCRIPT, m_BtnSctip);
}


BEGIN_MESSAGE_MAP(Device_Control, CDialogEx)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON_REG_WRITE, &Device_Control::OnBnClickedButtonRegWrite)
	ON_BN_CLICKED(IDC_BUTTON_REG_READ, &Device_Control::OnBnClickedButtonRegRead)
	ON_BN_CLICKED(IDC_BUTTON1_PLAY, &Device_Control::OnBnClickedButton1Play)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &Device_Control::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_RADIO_Internel_Setting, &Device_Control::OnBnClickedRadioInternelSetting)
	ON_BN_CLICKED(IDC_RADIO_Sensor_Setting, &Device_Control::OnBnClickedRadioSensorSetting)
	ON_BN_CLICKED(IDC_BUTTON1, &Device_Control::OnBnClickedButton1)
	ON_EN_UPDATE(IDC_EDIT_ADD_EDITCONTROL, &Device_Control::OnEnUpdateEditAddEditcontrol)
	ON_WM_CTLCOLOR()
//	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ABIT1, &Device_Control::OnDeltaposSpinAbit1)
	ON_EN_CHANGE(IDC_EDIT_ABIT1, &Device_Control::OnEnChangeEditAbit1)
	ON_EN_CHANGE(IDC_EDIT_ABIT2, &Device_Control::OnEnChangeEditAbit2)
	ON_EN_CHANGE(IDC_EDIT_ABIT3, &Device_Control::OnEnChangeEditAbit3)
	ON_EN_CHANGE(IDC_EDIT_ABIT4, &Device_Control::OnEnChangeEditAbit4)
	ON_EN_CHANGE(IDC_EDIT_ABIT5, &Device_Control::OnEnChangeEditAbit5)
	ON_EN_CHANGE(IDC_EDIT_ABIT6, &Device_Control::OnEnChangeEditAbit6)
	ON_EN_CHANGE(IDC_EDIT_ABIT7, &Device_Control::OnEnChangeEditAbit7)
	ON_EN_CHANGE(IDC_EDIT_ABIT8, &Device_Control::OnEnChangeEditAbit8)
	ON_EN_CHANGE(IDC_EDIT_ABIT9, &Device_Control::OnEnChangeEditAbit9)
	ON_EN_CHANGE(IDC_EDIT_ABIT10, &Device_Control::OnEnChangeEditAbit10)
	ON_EN_CHANGE(IDC_EDIT_ABIT11, &Device_Control::OnEnChangeEditAbit11)
	ON_EN_CHANGE(IDC_EDIT_ABIT12, &Device_Control::OnEnChangeEditAbit12)
	ON_EN_CHANGE(IDC_EDIT_ABIT13, &Device_Control::OnEnChangeEditAbit13)
	ON_EN_CHANGE(IDC_EDIT_ABIT14, &Device_Control::OnEnChangeEditAbit14)
	ON_EN_CHANGE(IDC_EDIT_ABIT15, &Device_Control::OnEnChangeEditAbit15)
	ON_EN_CHANGE(IDC_EDIT_ABIT16, &Device_Control::OnEnChangeEditAbit16)
	ON_EN_UPDATE(IDC_EDIT_DATA_EDITCONTROL, &Device_Control::OnEnUpdateEditDataEditcontrol)
	ON_EN_CHANGE(IDC_EDIT_DBIT1, &Device_Control::OnEnChangeEditDbit1)
	ON_EN_CHANGE(IDC_EDIT_DBIT2, &Device_Control::OnEnChangeEditDbit2)
	ON_EN_CHANGE(IDC_EDIT_DBIT3, &Device_Control::OnEnChangeEditDbit3)
	ON_EN_CHANGE(IDC_EDIT_DBIT4, &Device_Control::OnEnChangeEditDbit4)
	ON_EN_CHANGE(IDC_EDIT_DBIT5, &Device_Control::OnEnChangeEditDbit5)
	ON_EN_CHANGE(IDC_EDIT_DBIT6, &Device_Control::OnEnChangeEditDbit6)
	ON_EN_CHANGE(IDC_EDIT_DBIT7, &Device_Control::OnEnChangeEditDbit7)
	ON_EN_CHANGE(IDC_EDIT_DBIT8, &Device_Control::OnEnChangeEditDbit8)
	ON_EN_CHANGE(IDC_EDIT_DBIT9, &Device_Control::OnEnChangeEditDbit9)
	ON_EN_CHANGE(IDC_EDIT_DBIT10, &Device_Control::OnEnChangeEditDbit10)
	ON_EN_CHANGE(IDC_EDIT_DBIT11, &Device_Control::OnEnChangeEditDbit11)
	ON_EN_CHANGE(IDC_EDIT_DBIT12, &Device_Control::OnEnChangeEditDbit12)
	ON_EN_CHANGE(IDC_EDIT_DBIT13, &Device_Control::OnEnChangeEditDbit13)
	ON_EN_CHANGE(IDC_EDIT_DBIT14, &Device_Control::OnEnChangeEditDbit14)
	ON_EN_CHANGE(IDC_EDIT_DBIT15, &Device_Control::OnEnChangeEditDbit15)
	ON_EN_CHANGE(IDC_EDIT_DBIT16, &Device_Control::OnEnChangeEditDbit16)
	ON_CBN_SELCHANGE(IDC_COMBO_IMG_SIZE, &Device_Control::OnCbnSelchangeComboImgSize)
	ON_BN_CLICKED(IDC_BUTTON_SAV_IMG, &Device_Control::OnBnClickedButtonSavImg)
	ON_BN_CLICKED(IDC_CHECK_SIZE, &Device_Control::OnBnClickedCheckSize)
	ON_BN_CLICKED(IDC_BUTTON_SCRIPT, &Device_Control::OnBnClickedButtonScript)
END_MESSAGE_MAP()


// Device_Control message handlers


void Device_Control::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	UpdateWindow();
}


int Device_Control::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	DefaultSetup();

	return 0;
}

void Device_Control::DefaultSetup()
{
	i2c_Error = true;
}

BYTE Device_Control::Hexa2Int2(CString aaa)
{
	BYTE ret = 0;
	char buf[5];

	//strcpy_s(buf, aaa.GetBuffer(0));

	size_t nConv = 0;
	wcstombs_s(&nConv, buf, aaa, aaa.GetLength()); 
	
	ret += Hexa2Int(buf[0]) << 4;
	ret += Hexa2Int(buf[1]);

	return(ret);
}

BYTE Device_Control::Hexa2Int(BYTE ch)
{
	BYTE ret = 0;

	if((ch >= '0') && (ch <= '9'))		ret = ch - '0';
	else if((ch >= 'a') && (ch <= 'f'))	ret = ch - 'a' + 10;
	else if((ch >= 'A') && (ch <= 'F'))	ret = ch - 'A' + 10;
	else					ret = 0;

	return(ret);
}

void Device_Control::I2C_Function(bool I2cWR)
{
	//I2cWR == write is true
	//I2cWR == write is false
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();

	BYTE Chip_ID;
	BYTE Addr[2];
	BYTE WrData[2];
	CString str;
	CString temp;
	int nStr;

	m_EditInput_ID.GetWindowTextW(str);
	if(str.IsEmpty())
	{
		ASSERT(_T("Is Empty"));
		MessageBox(_T("Is Empty"), _T("ASSERT"), MB_ICONWARNING);
		i2c_Error = false;
		Error_Mes();
		return;
	}
	Chip_ID = Hexa2Int2(str);

	m_EditInput_Add.GetWindowTextW(str);
	if(str.IsEmpty())
	{
		ASSERT(_T("Is Empty"));
		MessageBox(_T("Is Empty"), _T("ASSERT"), MB_ICONWARNING);
		i2c_Error = false;
		Error_Mes();
		return;
	}

	nStr = str.GetLength();
	if(nStr == 4)
	{
		temp = str.Left(2);
		Addr[0] = Hexa2Int2(temp);
		temp = str.Right(2);
		Addr[1] = Hexa2Int2(temp);
		i2c_Error = true;
	}else{i2c_Error = false;Error_Mes();return;}

	m_EditInput_Data.GetWindowTextW(str);
	if(str.IsEmpty())
	{
		ASSERT(_T("Is Empty"));
		MessageBox(_T("Is Empty"), _T("ASSERT"), MB_ICONWARNING);
		i2c_Error = false;
		Error_Mes();
		return;
	}
	
	nStr = str.GetLength();
	if(nStr == 4)
	{
		temp = str.Left(2);
		WrData[0] = Hexa2Int2(temp);
		temp = str.Right(2);
		WrData[1] = Hexa2Int2(temp);
		i2c_Error = true;
	}else{i2c_Error = false; Error_Mes();return;}

	if(i2c_Error)
	{
		CString strMeg;
		strMeg.Format(TEXT(">>Write Date = id : 0x%02X,  addr : 0x%02X%02X,  data : 0x%02X%02X"), Chip_ID, Addr[0],Addr[1], WrData[0],WrData[1]);
	
		pAPP->MessageOutput(strMeg);
		pAPP->MessageOutput(_T("------------------------------------------------------------------------------------------------------------------"));
		CString strDbug_Meg;
		strDbug_Meg.Format(TEXT(">>Write Date = id : 0x%02X,  addr[HIGH BYTE] : 0x%02X,  data[HIGH BYTE] : 0x%02X"), Chip_ID, Addr[0], WrData[0]);
		pAPP->MessageOutput(strDbug_Meg);
		strDbug_Meg.Format(TEXT(">>Write Date = id : 0x%02X,  addr[LOW BYTE] : 0x%02X,  data[LOW BYTE] : 0x%02X"), Chip_ID, Addr[1], WrData[1]);
		pAPP->MessageOutput(strDbug_Meg);
		pAPP->MessageOutput(_T("------------------------------------------------------------------------------------------------------------------"));
	}else{Error_Mes();}

	if(I2cWR)
	{//write mode
		if(i2c_Error){
#if 1
			if(pAPP->MxConfigParam.m_Resistor_Mode) //FPGA MODE
			{
				pAPP->USB_I2C_Write(Chip_ID, Addr[0], WrData[0]);
				pAPP->MessageOutput(_T(">>System Control for Resistor mode Write"));
			}
			else{
				//Sensor Registor mode
				pAPP->USB_I2C_Write(Chip_ID, 0x07, Addr[0]);	//High ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x08, Addr[1]);	//LOW  ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x09, WrData[0]);	//High Data byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x0a, WrData[1]);	//LOW  Data byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x03, 0x03);	//Write Start

				pAPP->MessageOutput(_T(">>Sensor Control for Resistor mode Write"));
			}
#endif
		} else{Error_Mes();}
	}
	else{//read mode
#if 1
		if(i2c_Error){
			if(pAPP->MxConfigParam.m_Resistor_Mode) //FPGA MODE
			{
				pAPP->USB_I2C_Read(Chip_ID, Addr[0], WrData[0]);
				pAPP->MessageOutput(_T(">>System Control for Resistor mode Read"));
			}
			else{
				//Sensor Registor mode
				pAPP->USB_I2C_Write(Chip_ID, 0x07, Addr[0]);	//High ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x08, Addr[1]);	//LOW  ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x03, 0x01);	//Read Starts
				pAPP->USB_I2C_Read(Chip_ID, 0x0b, WrData[0]);	//High Read byte
				BYTE R_Data_H[4];

				R_Data_H[0] = pAPP->S_RdData_R[0];
				CString read_data_H,read_data_L ;
				read_data_H.Format(TEXT("0x%02X"), R_Data_H[0]);

				pAPP->USB_I2C_Read(Chip_ID, 0x0c, WrData[1]);	//Low Read byte
				R_Data_H[1] = pAPP->S_RdData_R[0];
				read_data_L.Format(TEXT("%02X"), R_Data_H[1]);
				read_data_H = read_data_H + read_data_L;


				pAPP->MessageOutput(_T(">>Sensor Control for Resistor mode Read"));
				m_TextReadValue.SetWindowTextW(read_data_H);

				CString strDbug_Meg;
				strDbug_Meg.Format(TEXT(">>Sensor ADD : 0x%02X%02X, Read  : %s"),Addr[0],Addr[1], read_data_H);
				pAPP->MessageOutput(strDbug_Meg);


			}

		} else{Error_Mes();}
#endif
	}
}

void Device_Control::Error_Mes()
{
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->MessageOutput(_T(">>Registor Control Error check again..."));
}

void Device_Control::OnBnClickedButtonRegWrite()
{
	// TODO: Add your control notification handler code here
#if 1
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	if(pAPP->MxConfigParam.m_Resistor_Mode)
	{
		I2C_Function(true);	//FPGA MODE
	}
	else{
		I2C_Function(true);	//Sensor Mode
	}
#endif
}


void Device_Control::OnBnClickedButtonRegRead()
{
	// TODO: Add your control notification handler code here
#if 1
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	if(pAPP->MxConfigParam.m_Resistor_Mode)
	{
		I2C_Function(false);//FPGA MODE
	}else{
		I2C_Function(false);	//Sensor MODE
	}
#endif
}


void Device_Control::OnBnClickedButton1Play()
{
	// TODO: Add your control notification handler code here
#if 1
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	if(pAPP->USB_Open)
	{
		pAPP->Thread_Start();
		m_Radio_Sensor.EnableWindow(false);	//play butten disable
		m_BtnStop.EnableWindow(true);		//stop butten disable

		m_Combo_Img_Size.EnableWindow(false);	//combobox disable
		m_SaveBtn.EnableWindow(true);	//save butten
		//m_BtnSctip.EnableWindow(true);	//script open button
	}
#else
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->Start_Btn();
#endif
}


void Device_Control::OnBnClickedButtonStop()
{
	// TODO: Add your control notification handler code here
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	
	if(pAPP->USB_Open)
	{
		//pAPP->Thread_Start();
		m_Radio_Sensor.EnableWindow(true);	//play butten disable
		m_BtnStop.EnableWindow(false);		//stop butten disable
		pAPP->bThred_Flag = false;
		pAPP->MessageOutput(_T(">>Play Stop ........."));
		m_Combo_Img_Size.EnableWindow(true);	//combobox disable
		m_SaveBtn.EnableWindow(false);	//save butten disable
		//m_BtnSctip.EnableWindow(false);	//script open button
	}
	
}


void Device_Control::OnBnClickedRadioInternelSetting()
{
	// TODO: Add your control notification handler code here
	m_Radio_Sensor.SetCheck(0);
#if 1
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->MxConfigParam.m_Resistor_Mode = true; //FGPA MODE
#endif
}


void Device_Control::OnBnClickedRadioSensorSetting()
{
	// TODO: Add your control notification handler code here
	m_Radio_Internel.SetCheck(0);
#if 1
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->MxConfigParam.m_Resistor_Mode = false;
#endif
}


void Device_Control::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString str;

	m_nTimeout.GetWindowTextW(str);
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->m_MxUsb3->m_TimeOut = _ttoi(str);
	CString strDbug_Meg;
	strDbug_Meg.Format(TEXT(">>Set time value is %s"),str);
	pAPP->MessageOutput(strDbug_Meg);
}


void Device_Control::OnEnUpdateEditAddEditcontrol()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.

	// TODO:  Add your control notification handler code here

	CString str;
	CString temp;
	int nStr;
	BYTE Addr[2];
	unsigned char bit[4];

	m_EditInput_Add.GetWindowTextW(str);
	if(str.IsEmpty())
	{
		ASSERT(_T("Is Empty"));
		MessageBox(_T("Is Empty"), _T("ASSERT"), MB_ICONWARNING);
		//i2c_Error = false;
		Error_Mes();
		return;
	}
	if(Set_BitControl == 1)
	{
		Set_BitControl = 0;
		return;
	}

	nStr = str.GetLength();
	if(nStr == 4)
	{
		temp = str.Left(2);
		Addr[0] = Hexa2Int2(temp);
		temp = str.Right(2);
		Addr[1] = Hexa2Int2(temp);
		bit[0] = Addr[1] & 0x0f;
		bit[1] = Addr[1] & 0xf0;

		bit[2] = Addr[0] & 0x0f;
		bit[3] = Addr[0] & 0xf0;

		BitControl[0] = Addr[1];	//low byte
		BitControl[1] = Addr[0];	//hight byte
		
		//[3:0]
#if 1
		switch(bit[0])
		{
			case 0x00:	//0
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("0"));
				nColor = 111;	// red
			break;

			case 0x01:		//1
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("1"));				
			break;

			case 0x02:	//2
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("0"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("0"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("0"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				b_EditChk = true;
				m_ABit4.SetWindowTextW(_T("1"));
				m_ABit3.SetWindowTextW(_T("1"));
				m_ABit2.SetWindowTextW(_T("1"));
				m_ABit1.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		//[7:4]
#if 1
		bit[1] = bit[1] >> 4;
		switch(bit[1])
		{
			case 0x00:	//0
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_ABit8.SetWindowTextW(_T("0"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("0"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("0"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_ABit8.SetWindowTextW(_T("1"));
				m_ABit7.SetWindowTextW(_T("1"));
				m_ABit6.SetWindowTextW(_T("1"));
				m_ABit5.SetWindowTextW(_T("1"));
			break;
		}
#endif
		//[11:8]
#if 1
		switch(bit[2])
		{
			case 0x00:	//0
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_ABit12.SetWindowTextW(_T("0"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("0"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("0"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_ABit12.SetWindowTextW(_T("1"));
				m_ABit11.SetWindowTextW(_T("1"));
				m_ABit10.SetWindowTextW(_T("1"));
				m_ABit9.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		//[16:12]
#if 1
		bit[3] = bit[3] >> 4;

		switch(bit[3])
		{
			case 0x00:	//0
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_ABit_16.SetWindowTextW(_T("0"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("0"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("0"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_ABit_16.SetWindowTextW(_T("1"));
				m_ABit15.SetWindowTextW(_T("1"));
				m_ABit14.SetWindowTextW(_T("1"));
				m_ABit13.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		b_EditChk = false;
	}
	else
	{
		//b_EditChk = false;
	}
	//::InvalidateRect();
}


HBRUSH Device_Control::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired
	int nRet = pWnd->GetDlgCtrlID();


	//IDC_EDIT_ADD_EDITCONTROL
	//IDC_EDIT_DATA_EDITCONTROL

	if(nRet == IDC_EDIT_ADD_EDITCONTROL)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}

	if(nRet == IDC_EDIT_DATA_EDITCONTROL)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}

	if(nRet == IDC_EDIT_ABIT1)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT2)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT3)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT4)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT5)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT6)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT7)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT8)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT9)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT10)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT11)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT12)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT13)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT14)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT15)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}
	if(nRet == IDC_EDIT_ABIT16)
	{
		pDC->SetTextColor(RGB(0xFF, 0x00, 0x00));
	}


	if(nRet == IDC_EDIT_DBIT1)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT2)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT3)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT4)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT5)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT6)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT7)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT8)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT9)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT10)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT11)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT12)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT13)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT14)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT15)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}
	if(nRet == IDC_EDIT_DBIT16)
	{
		pDC->SetTextColor(RGB(0x00, 0x00, 0xFF));
	}

	return hbr;
}


int nTemp;

void Device_Control::OnEnChangeEditAbit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	//if(b_EditChk){
		if(nTemp > 9){
			m_ABit1.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[0] = BitControl[0] | 0x01;
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
				Set_BitControl = 1;
				m_EditInput_Add.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[0] = BitControl[0] & 0xFE;
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
				Set_BitControl = 1;
				m_EditInput_Add.SetWindowTextW(sData);
			}
		}
	//}
}


void Device_Control::OnEnChangeEditAbit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit2.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x02;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xFD;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit3.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x04;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xFB;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit4.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x08;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xF7;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit5.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x10;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xEF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit6.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x20;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xDF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit7.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x40;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0xBF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit8.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[0] = BitControl[0] | 0x80;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[0] = BitControl[0] & 0x7F;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTemp++;
	if(nTemp > 9){
		m_ABit9.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x01;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xFE;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	//nTemp++;

	if(nTemp > 9){
		m_ABit10.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x02;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xFD;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}

}


void Device_Control::OnEnChangeEditAbit11()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit11.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x04;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xFB;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}

}


void Device_Control::OnEnChangeEditAbit12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit12.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x08;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xF7;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit13.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x10;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xEF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit14.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x20;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xDF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit15.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x40;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0xBF;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}


void Device_Control::OnEnChangeEditAbit16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTemp++;
	if(nTemp > 9){
		m_ABit_16.GetWindowTextW(sTad);

		if(sTad == "1")
		{		
			BitControl[1] = BitControl[1] | 0x80;	//high bit
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}

		if(sTad == "0")
		{
			BitControl[1] = BitControl[1] & 0x7F;
			CString sData;
			sData.Format(TEXT("%02X%02X"),BitControl[1],BitControl[0]);
			Set_BitControl = 1;
			m_EditInput_Add.SetWindowTextW(sData);
		}
	}
}




//data input control

void Device_Control::OnEnUpdateEditDataEditcontrol()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.

	// TODO:  Add your control notification handler code here
	
	CString str;
	CString temp;
	int nStr;
	BYTE WrData[2];
	unsigned char bit[4];

	m_EditInput_Data.GetWindowTextW(str);
	if(str.IsEmpty())
	{
		ASSERT(_T("Is Empty"));
		MessageBox(_T("Is Empty"), _T("ASSERT"), MB_ICONWARNING);
		//i2c_Error = false;
		Error_Mes();
		return;
	}
	if(Set_BitControl == 1)
	{
		Set_BitControl = 0;
		return;
	}

	nStr = str.GetLength();
	if(nStr == 4)
	{
		temp = str.Left(2);
		WrData[0] = Hexa2Int2(temp);
		temp = str.Right(2);
		WrData[1] = Hexa2Int2(temp);
		bit[0] = WrData[1] & 0x0f;
		bit[1] = WrData[1] & 0xf0;

		bit[2] = WrData[0] & 0x0f;
		bit[3] = WrData[0] & 0xf0;

		BitControl[2] = WrData[1];	//low byte
		BitControl[3] = WrData[0];	//hight byte
		
		//[3:0]
#if 1
		switch(bit[0])
		{
			case 0x00:	//0
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("0"));
				nColor = 111;	// red
			break;

			case 0x01:		//1
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("1"));				
			break;

			case 0x02:	//2
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("0"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("0"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("0"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				b_EditChk = true;
				m_DBit4.SetWindowTextW(_T("1"));
				m_DBit3.SetWindowTextW(_T("1"));
				m_DBit2.SetWindowTextW(_T("1"));
				m_DBit1.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		//[7:4]
#if 1
		bit[1] = bit[1] >> 4;
		switch(bit[1])
		{
			case 0x00:	//0
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_DBit8.SetWindowTextW(_T("0"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("0"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("0"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_DBit8.SetWindowTextW(_T("1"));
				m_DBit7.SetWindowTextW(_T("1"));
				m_DBit6.SetWindowTextW(_T("1"));
				m_DBit5.SetWindowTextW(_T("1"));
			break;
		}
#endif
		//[11:8]
#if 1
		switch(bit[2])
		{
			case 0x00:	//0
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_DBit12.SetWindowTextW(_T("0"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("0"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("0"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_DBit12.SetWindowTextW(_T("1"));
				m_DBit11.SetWindowTextW(_T("1"));
				m_DBit10.SetWindowTextW(_T("1"));
				m_DBit9.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		//[16:12]
#if 1
		bit[3] = bit[3] >> 4;

		switch(bit[3])
		{
			case 0x00:	//0
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x01:		//1
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x02:	//2
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x03:	//3
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x04:	//4
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x05:	//5
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x06:	//6
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x07:	//7
				m_DBit16.SetWindowTextW(_T("0"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x08:	//8
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;
				
			case 0x09:	//9
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x0a:	//10
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x0b:	//11
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("0"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x0c:	//12
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x0d:	//13
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("0"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;

			case 0x0e:	//14
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("0"));
			break;

			case 0x0f:	//15
				m_DBit16.SetWindowTextW(_T("1"));
				m_DBit15.SetWindowTextW(_T("1"));
				m_DBit14.SetWindowTextW(_T("1"));
				m_DBit13.SetWindowTextW(_T("1"));
			break;
		}//swtich
#endif
		b_EditChk = false;
	}
	else
	{
		//b_EditChk = false;
	}
}

//data bit control

int nTempA;
void Device_Control::OnEnChangeEditDbit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit1.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x01;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xFE;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit2.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x02;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xFD;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit3.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x04;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xFB;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit4.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x08;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xF7;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit5.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x10;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xEF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit6.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x20;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xDF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit7.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x40;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0xBF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit8.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[2] = BitControl[2] | 0x80;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[2] = BitControl[2] & 0x7F;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	nTempA++;
		if(nTempA > 9){
			m_DBit9.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x01;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xFE;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit10.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x02;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xFD;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}

}


void Device_Control::OnEnChangeEditDbit11()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit11.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x04;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xFB;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}

}


void Device_Control::OnEnChangeEditDbit12()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit12.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x08;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xF7;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}

}


void Device_Control::OnEnChangeEditDbit13()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit13.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x10;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xEF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit14()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit14.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x20;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xDF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit15.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x40;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0xBF;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


void Device_Control::OnEnChangeEditDbit16()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	CString sTad;
	//nTempA++;
		if(nTempA > 9){
			m_DBit16.GetWindowTextW(sTad);

			if(sTad == "1")
			{		
				BitControl[3] = BitControl[3] | 0x80;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}

			if(sTad == "0")
			{
				BitControl[3] = BitControl[3] & 0x7F;	//low bit data
				CString sData;
				sData.Format(TEXT("%02X%02X"),BitControl[3],BitControl[2]);
				Set_BitControl = 1;
				m_EditInput_Data.SetWindowTextW(sData);
			}
		}
}


//combobox Image size changed
void Device_Control::OnCbnSelchangeComboImgSize()
{
	// TODO: Add your control notification handler code here
	//this->SendMessage(WM_COMMAND, IDC_BUTTON_STOP, 0);

	CString sTemp;
	int nSel = m_Combo_Img_Size.GetCurSel();
	m_Combo_Img_Size.GetLBText(nSel,sTemp);
	int len = sTemp.GetLength();
	int nidx = sTemp.Find('x');
	CString wd = sTemp.Left(nidx);
	CString hd = sTemp.Right(len-(nidx+1));

	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	pAPP->MxConfigParam.m_ImageWidth = _ttoi(wd);
	pAPP->MxConfigParam.m_ImageHeight = _ttoi(hd);

	pAPP->m_pFormatRGB->SetBuffer();
}


void Device_Control::OnBnClickedButtonSavImg()
{
	// TODO: Add your control notification handler code here
	CString m_strPath;
	CStdioFile file;
	// CFile file;
	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("BMP Files(*.bmp)|*.bmp|"), NULL);

	if(dlg.DoModal() == IDOK)
	{
		m_strPath = dlg.GetPathName();
		if(m_strPath.Right(4) != "bmp")
		{
			//m_strPath += ".bmp";
		}
		CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
		pAPP->SaveToBmp(m_strPath);
	}

}


void Device_Control::OnBnClickedCheckSize()
{
	// TODO: Add your control notification handler code here
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	int ncheck;
	ncheck = m_FitImagSize.GetCheck();
	if(ncheck == 1)
	{
		pAPP->m_Set_FitSize = true;
	}
	if(ncheck == 0)
	{
		pAPP->m_Set_FitSize = false;
	}
}


CString Device_Control::ConvertToHex(CString data)
{
	CString returnV;
	int nDec = 0;
	char szHex[16];

	sprintf_s(szHex, "%04X", _ttoi(data));

	returnV = szHex;

	return returnV;
}


void Device_Control::OnBnClickedButtonScript()
{
	// TODO: Add your control notification handler code here

	char filter[] = "Raw files (*.*)|*.txt||";
	
	CFileDialog dlg(TRUE);
	CString strTemp, strTempA, strTempB;
	CString strRead_ADD;
	int nLength;
	int nIndexA = 0;
	int nIndexB = 0;
	CString ADD_H, ADD_L;

	BYTE Addr[2];
	BYTE Data[2];
	bool i2c_Checker = false;
	//CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	//if(pAPP->USB_Open)
	//{
		if(dlg.DoModal() == IDOK){
			//strFilePath = dlg.GetPathName();

			CStdioFile rFile;
		
			if(!rFile.Open(dlg.GetPathName(), CFile::modeRead))
			{
				MessageBox(_T("Can't open file"), _T("Warning"), MB_OK|MB_ICONHAND);
				return;
			}

			while(rFile.ReadString(strTemp))
			{
				nLength = strTemp.GetLength();
			
				//林籍 公矫
				if(strTemp.GetAt(0) == '/')
					continue;

				if(strTemp == "EnableClockMngmnt1[]")
				{
					nIndexA = strTemp.Find(',');
				
				}
				nLength = strTemp.GetLength();
			
				//林籍 公矫
				if(strTemp.GetAt(0) == '/')
					continue;

				if(strTemp == "EnableClockMngmnt1[]")
				{
					nIndexA = strTemp.Find(',');
				
				}


				nIndexA = strTemp.Find(',');
				nIndexB = strTemp.Find('(');
				if(( nIndexA != -1) && (nIndexB != -1))
				{
					i2c_Checker = true;
					int ntemp = nIndexA - nIndexB;
					for(int i=nIndexB; i<nIndexA-1; i++)
					{
						strRead_ADD = strRead_ADD + strTemp.GetAt(i+1);//
					}

					strTempA = ConvertToHex(strRead_ADD);
					strTempB = strTempA.Left(2);
					Addr[0] = Hexa2Int2(strTempB);

					strTempB = strTempA.Right(2);
					Addr[1] = Hexa2Int2(strTempB);

					ADD_H.Format(TEXT("0x%02X"), Addr[0]);
					ADD_L.Format(TEXT("0x%02X"), Addr[1]);
					//strTemp.Empty();
					strRead_ADD.Empty();
				}
				else{
					i2c_Checker = false;
				}

				nIndexA = strTemp.Find('x');
				nIndexB = strTemp.Find(')');
				if(( nIndexA != -1) && (nIndexB != -1))
				{
					i2c_Checker = true;
					int ntemp = nIndexB - nIndexA;
					for(int i=nIndexA; i<nIndexB-1; i++)
					{
						strRead_ADD = strRead_ADD + strTemp.GetAt(i+1);//
					}

					strTempA = strRead_ADD;
					strTempB = strTempA.Left(2);
					Data[0] = Hexa2Int2(strTempB);

					strTempB = strTempA.Right(2);
					Data[1] = Hexa2Int2(strTempB);

					ADD_H.Format(TEXT("0x%02X"), Data[0]);
					ADD_L.Format(TEXT("0x%02X"), Data[1]);
				
				}
				else{
					i2c_Checker = false;
				}

				BYTE Chip_ID = 0x76;

				if(i2c_Checker){
					CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
					if(pAPP->USB_Open){
					pAPP->USB_I2C_Write(Chip_ID, 0x07, Addr[0]);	//High ADD byte i2c write
					pAPP->USB_I2C_Write(Chip_ID, 0x08, Addr[1]);	//LOW  ADD byte i2c write
					pAPP->USB_I2C_Write(Chip_ID, 0x09, Data[0]);	//High Data byte i2c write
					pAPP->USB_I2C_Write(Chip_ID, 0x0a, Data[1]);	//LOW  Data byte i2c write
					pAPP->USB_I2C_Write(Chip_ID, 0x03, 0x03);	//Write Start
					CString strDebug;
					strDebug.Format(TEXT(">> ADD : 0x%02X%02X  DATA : 0x%02X%02X"), Addr[0],Addr[1],Data[0], Data[1]);
					pAPP->MessageOutput(strDebug);
					}
					else{
						AfxMessageBox(_T("USB Not Connected.."));
					}
				
				}
				strTemp.Empty();
				strRead_ADD.Empty();
			}//while
			rFile.Close();
		}//if
	//}
	Invalidate();
}
