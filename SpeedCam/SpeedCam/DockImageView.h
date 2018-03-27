#pragma once

#include "ImageView_Dlg.h"
#include "resource.h"
// DockImageView

class DockImageView : public CDockablePane
{
	DECLARE_DYNAMIC(DockImageView)

public:
	DockImageView();
	virtual ~DockImageView();

	ImageView_Dlg m_ImageView_Dlg;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


