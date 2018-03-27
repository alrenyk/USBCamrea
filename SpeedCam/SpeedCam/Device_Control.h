#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// Device_Control dialog

class Device_Control : public CDialogEx
{
	DECLARE_DYNAMIC(Device_Control)

public:
	Device_Control(CWnd* pParent = NULL);   // standard constructor
	virtual ~Device_Control();

// Dialog Data
	enum { IDD = IDD_DIALOG_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void DefaultSetup();
	void Error_Mes();
	BYTE Hexa2Int2(CString aaa);
	BYTE Hexa2Int(BYTE ch);
	bool i2c_Error;
	bool b_EditChk;
	int Set_BitControl;
	//BYTE Hexa2Int2(CString aaa);
	CString ConvertToHex(CString data);


	// USB DEVICE TreeCotrol
	CTreeCtrl Usb_TreeCtrl;
	// //i2c write button
	CButton m_i2c_Write_Btn;
	// Editinput device chip id
	CEdit m_EditInput_ID;
	// Editinput address
	CEdit m_EditInput_Add;
	// Edit input Data
	CEdit m_EditInput_Data;

public:
	afx_msg void OnBnClickedButtonRegWrite();
	void I2C_Function(bool I2cWR);
	afx_msg void OnBnClickedButtonRegRead();
	// read data value display
	CStatic m_TextReadValue;
	afx_msg void OnBnClickedButton1Play();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedRadioInternelSetting();
	afx_msg void OnBnClickedRadioSensorSetting();

	CButton m_Radio_Internel;
	CButton m_Radio_Sensor;//play Btn
	CEdit m_nTimeout;
	afx_msg void OnBnClickedButton1();
	CStatic m_FrameRate_Text;
	CButton m_BtnStop;	//play stop
	//Adress bit edit
	CEdit m_ABit_16;

	int nColor;	//color number
	BYTE BitControl[4];

	CSpinButtonCtrl m_SpainABit16;
	CEdit m_ABit15;
	CEdit m_ABit14;
	CEdit m_ABit13;
	CEdit m_ABit12;
	CEdit m_ABit11;
	CEdit m_ABit10;
	CEdit m_ABit9;
	CEdit m_ABit8;
	CEdit m_ABit7;
	CEdit m_ABit6;
	CEdit m_ABit5;
	CEdit m_ABit4;
	CEdit m_ABit3;
	CEdit m_ABit2;
	CEdit m_ABit1;
	CSpinButtonCtrl m_SpainABit1;
	CSpinButtonCtrl m_SpainABit2;
	CSpinButtonCtrl m_SpainABit3;
	CSpinButtonCtrl m_SpainABit4;
	CSpinButtonCtrl m_SpainABit5;
	CSpinButtonCtrl m_SpainABit6;
	CSpinButtonCtrl m_SpainABit7;
	CSpinButtonCtrl m_SpainABit8;
	CSpinButtonCtrl m_SpainABit9;
	CSpinButtonCtrl m_SpainABit10;
	CSpinButtonCtrl m_SpainABit11;
	CSpinButtonCtrl m_SpainABit12;
	CSpinButtonCtrl m_SpainABit13;
	CSpinButtonCtrl m_SpainABit14;
	CSpinButtonCtrl m_SpainABit15;
	afx_msg void OnEnUpdateEditAddEditcontrol();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

//	afx_msg void OnDeltaposSpinAbit1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEditAbit1();
	afx_msg void OnEnChangeEditAbit2();
	afx_msg void OnEnChangeEditAbit3();
	afx_msg void OnEnChangeEditAbit4();
	afx_msg void OnEnChangeEditAbit5();
	afx_msg void OnEnChangeEditAbit6();
	afx_msg void OnEnChangeEditAbit7();
	afx_msg void OnEnChangeEditAbit8();
	afx_msg void OnEnChangeEditAbit9();
	afx_msg void OnEnChangeEditAbit10();
	afx_msg void OnEnChangeEditAbit11();
	afx_msg void OnEnChangeEditAbit12();
	afx_msg void OnEnChangeEditAbit13();
	afx_msg void OnEnChangeEditAbit14();
	afx_msg void OnEnChangeEditAbit15();
	afx_msg void OnEnChangeEditAbit16();


	CEdit m_DBit1;
	CEdit m_DBit2;
	CEdit m_DBit3;
	CEdit m_DBit4;
	CEdit m_DBit5;
	CEdit m_DBit6;
	CEdit m_DBit7;
	CEdit m_DBit8;
	CEdit m_DBit9;
	CEdit m_DBit10;
	CEdit m_DBit11;
	CEdit m_DBit12;
	CEdit m_DBit13;
	CEdit m_DBit14;
	CEdit m_DBit15;
	CEdit m_DBit16;
	CSpinButtonCtrl m_SpainDBit1;
	CSpinButtonCtrl m_SpainDBit2;
	CSpinButtonCtrl m_SpainDBit3;
	CSpinButtonCtrl m_SpainDBit4;
	CSpinButtonCtrl m_SpainDBit5;
	CSpinButtonCtrl m_SpainDBit6;
	CSpinButtonCtrl m_SpainDBit7;
	CSpinButtonCtrl m_SpainDBit8;
	CSpinButtonCtrl m_SpainDBit9;
	CSpinButtonCtrl m_SpainDBit10;
	CSpinButtonCtrl m_SpainDBit11;
	CSpinButtonCtrl m_SpainDBit12;
	CSpinButtonCtrl m_SpainDBit13;
	CSpinButtonCtrl m_SpainDBit14;
	CSpinButtonCtrl m_SpainDBit15;
	CSpinButtonCtrl m_SpainDBit16;
	afx_msg void OnEnUpdateEditDataEditcontrol();
	afx_msg void OnEnChangeEditDbit1();
	afx_msg void OnEnChangeEditDbit2();
	afx_msg void OnEnChangeEditDbit3();
	afx_msg void OnEnChangeEditDbit4();
	afx_msg void OnEnChangeEditDbit5();
	afx_msg void OnEnChangeEditDbit6();
	afx_msg void OnEnChangeEditDbit7();
	afx_msg void OnEnChangeEditDbit8();
	afx_msg void OnEnChangeEditDbit9();
	afx_msg void OnEnChangeEditDbit10();
	afx_msg void OnEnChangeEditDbit11();
	afx_msg void OnEnChangeEditDbit12();
	afx_msg void OnEnChangeEditDbit13();
	afx_msg void OnEnChangeEditDbit14();
	afx_msg void OnEnChangeEditDbit15();
	afx_msg void OnEnChangeEditDbit16();
	//image size select
	CComboBox m_Combo_Img_Size;
	afx_msg void OnCbnSelchangeComboImgSize();
	afx_msg void OnBnClickedButtonSavImg();
	// Save button value
	CButton m_SaveBtn;

	// m_FitImagSize
	CButton m_FitImagSize;
	afx_msg void OnBnClickedCheckSize();
	afx_msg void OnBnClickedButtonScript();
	// m_BtnSctip
	CButton m_BtnSctip;
};
