#pragma once
#include "Device_Control.h"
#include "resource.h"

// DockPanel

class DockPanel : public CDockablePane
{
	DECLARE_DYNAMIC(DockPanel)

public:
	DockPanel();
	virtual ~DockPanel();

	Device_Control m_Device_ControlDlg;

	void InitSetup();
	void GetImageSize();

public:
	bool bIsUsb_Con;
	UCHAR nCount;

	int nON_USB;
	int nOFF_USB;
	

protected:
	DECLARE_MESSAGE_MAP()

public:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


