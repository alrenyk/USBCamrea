#pragma once
#include "afxcmn.h"
#include "afxwin.h"

// ImageView_Dlg dialog

class ImageView_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ImageView_Dlg)

public:
	ImageView_Dlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ImageView_Dlg();

// Dialog Data
	enum { IDD = IDD_IMAGE_VIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void ShowImage(BYTE *RGB, int Height, int width);
	void TestImageShow(int Height, int width);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
