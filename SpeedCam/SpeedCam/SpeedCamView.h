
// SpeedCamView.h : interface of the CSpeedCamView class
//

#pragma once
#include "MainFrm.h"
#include "FormatConvert.h"
#include "FormatYCbCr.h"
#include "FormatRGB.h"
#include "MarblixUsb3.h"


#define debug	1

#if debug
struct ThreadArg
{
    HWND hWnd; // 윈도우 핸들
    int type; // 1이면 위쪽, 2이면 아래 막대를 그린다.
};
#endif

class CSpeedCamView : public CView
{
protected: // create from serialization only
	CSpeedCamView();
	DECLARE_DYNCREATE(CSpeedCamView)

// Attributes
public:
	CSpeedCamDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSpeedCamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


public:

	CString strFilePath;
	BYTE Hexa2Int2(CString aaa);
	BYTE Hexa2Int(BYTE ch);
	CString ConvertToHex(CString data);
	bool bScripMode;
	void ShowImage(BYTE *RGB, WORD m_ImageWidth, WORD m_ImageHeight);
	void TestBMP(BYTE *RGB);
	CRect CClientRect;
	bool bThred_VeiwFlag;


protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileOpen();
	virtual void OnInitialUpdate();

#if debug
	CWinThread* m_pThread1;
    ThreadArg m_arg1;
#endif
	void ShowImage();
	void Start_Th();

};

#ifndef _DEBUG  // debug version in SpeedCamView.cpp
inline CSpeedCamDoc* CSpeedCamView::GetDocument() const
   { return reinterpret_cast<CSpeedCamDoc*>(m_pDocument); }
#endif

