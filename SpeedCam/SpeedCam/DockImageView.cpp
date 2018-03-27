// DockImageView.cpp : implementation file
//

#include "stdafx.h"
#include "SpeedCam.h"
#include "DockImageView.h"


// DockImageView

IMPLEMENT_DYNAMIC(DockImageView, CDockablePane)

DockImageView::DockImageView()
{

}

DockImageView::~DockImageView()
{
}


BEGIN_MESSAGE_MAP(DockImageView, CDockablePane)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// DockImageView message handlers




void DockImageView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_ImageView_Dlg.MoveWindow(0, 0, cx, cy);
	//Invalidate(TRUE);
	//UpdateWindow();
}


void DockImageView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDockablePane::OnPaint() for painting messages

	//UpdateWindow();
}


void DockImageView::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);

	// TODO: Add your message handler code here
	SetFocus();
}


BOOL DockImageView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	


	return CDockablePane::OnEraseBkgnd(pDC);
}


int DockImageView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_ImageView_Dlg.Create(IDD_IMAGE_VIEW, this);
	m_ImageView_Dlg.ShowWindow(SW_SHOW);


	return 0;
}
