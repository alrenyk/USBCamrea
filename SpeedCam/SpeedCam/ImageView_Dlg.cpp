// ImageView_Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpeedCam.h"
#include "ImageView_Dlg.h"
#include "afxdialogex.h"


// ImageView_Dlg dialog

IMPLEMENT_DYNAMIC(ImageView_Dlg, CDialogEx)

ImageView_Dlg::ImageView_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ImageView_Dlg::IDD, pParent)
{

}

ImageView_Dlg::~ImageView_Dlg()
{
}

void ImageView_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ImageView_Dlg, CDialogEx)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// ImageView_Dlg message handlers


void ImageView_Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	/*
	m_pParentWnd = GetParent();	if(!m_pParentWnd) return;
	CWnd* pList = GetDlgItem(IDD_IMAGE_VIEW);	if(!pList) return;

	CRect rParentRect;
	m_pParentWnd->GetWindowRect(rParentRect);
	ScreenToClient(rParentRect);

	pList->SetWindowPos(NULL, rParentRect.top+20, rParentRect.bottom/2, rParentRect.right ,rParentRect.bottom/2,SWP_NOZORDER);
	*/
	//Invalidate(TRUE);
	UpdateWindow();
}


BOOL ImageView_Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	//CRect rect;
	//GetClientRect(rect);
	//pDC->FillSolidRect( rect, RGB(255,255,255) );

	return CDialogEx::OnEraseBkgnd(pDC);
}


int ImageView_Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	//SetBackgroundColor(RGB(255,255,255));

	return 0;
}

void ImageView_Dlg::TestImageShow(int Height, int Width)
{
	int m_nHeight = Height;
	int m_nWidth = Height;
	//float tf;
	//int m_nGainLevel = 0;
	//float m_nGainSlope = 1;

	BITMAPFILEHEADER bmFileHeader;
	BITMAPINFOHEADER bmInfoHeader;

	// BMP 헤더
	bmFileHeader.bfSize  = sizeof(BITMAPFILEHEADER);
	bmFileHeader.bfType  = 0x4D42;
	bmFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
 
	bmInfoHeader.biSize    = sizeof(BITMAPINFOHEADER);
	bmInfoHeader.biWidth   = m_nWidth; // 너비
	bmInfoHeader.biHeight   = m_nHeight; // 높이
	bmInfoHeader.biPlanes   = 1;
	bmInfoHeader.biBitCount   = 24; // 색상 비트
	bmInfoHeader.biCompression = 0;
	bmInfoHeader.biSizeImage = bmInfoHeader.biWidth * bmInfoHeader.biHeight * (bmInfoHeader.biBitCount/8);

	bmInfoHeader.biXPelsPerMeter = 0;
	bmInfoHeader.biYPelsPerMeter = 0;
	bmInfoHeader.biClrUsed = 0;
	bmInfoHeader.biClrImportant = 0;

	CClientDC dc(this);

	BYTE* buf = new BYTE[m_nHeight * m_nWidth *3];
    int c = 0;
  
    for ( int i = 0; i < m_nHeight; i++ )
    {
        for ( int j = 0; j < m_nWidth; j++ )
        {
			/*
            buf[ c + 0 ] = (BYTE) 0;
            buf[ c + 1 ] = (BYTE) 0;
            buf[ c + 2 ] = (BYTE) 255;
  
            c += 3;
			*/
			//tf = m_nGainSlope * ( (float)RGB[(j*m_nWidth + (m_nWidth-i))*3]- m_nGainLevel ) + m_nGainLevel ;
			buf[ (i*m_nWidth + j)*3 + 0 ] = 255;
            buf[ (i*m_nWidth + j)*3 + 1 ] = 0;
            buf[ (i*m_nWidth + j)*3 + 2 ] = 0;
        }
    }

	//dc.TextOutW(100, 400, _T("Test"));

	::StretchDIBits(dc.m_hDC,  // handle to device context
    0,    // x-coordinate of upper-left corner of dest. rectangle
    0,                  // y-coordinate of upper-left corner of dest. rectangle
    m_nWidth,          // width of destination rectangle
    m_nHeight,        // height of destination rectangle
    0,                 // x-coordinate of upper-left corner of source rectangle
    0,                 // y-coordinate of upper-left corner of source rectangle
    m_nWidth,         // width of source rectangle
    m_nHeight,       // height of source rectangle
    buf,           // address of bitmap bits
    (LPBITMAPINFO)&bmInfoHeader,//LPBITMAPINFO address of bitmap data
    DIB_RGB_COLORS, // usage flags
    SRCCOPY);// raster operation code
	
	
	delete buf;
}

void ImageView_Dlg::ShowImage(BYTE *RGB, int Height, int width)
{
	int m_nHeight = Height;
	int m_nWidth = width;
	//float tf;
	//int m_nGainLevel = 0;
	//float m_nGainSlope = 1;

	BITMAPFILEHEADER bmFileHeader;
	BITMAPINFOHEADER bmInfoHeader;

	// BMP 헤더
	bmFileHeader.bfSize  = sizeof(BITMAPFILEHEADER);
	bmFileHeader.bfType  = 0x4D42;
	bmFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
 
	bmInfoHeader.biSize    = sizeof(BITMAPINFOHEADER);
	bmInfoHeader.biWidth   = m_nWidth; // 너비
	bmInfoHeader.biHeight   = m_nHeight; // 높이
	bmInfoHeader.biPlanes   = 1;
	bmInfoHeader.biBitCount   = 24; // 색상 비트
	bmInfoHeader.biCompression = 0;
	bmInfoHeader.biSizeImage = bmInfoHeader.biWidth * bmInfoHeader.biHeight * (bmInfoHeader.biBitCount/8);

	bmInfoHeader.biXPelsPerMeter = 0;
	bmInfoHeader.biYPelsPerMeter = 0;
	bmInfoHeader.biClrUsed = 0;
	bmInfoHeader.biClrImportant = 0;

	CClientDC dc(this);

	BYTE* buf = new BYTE[m_nHeight * m_nWidth *3];
    int c = 0;
  
    for ( int i = 0; i < m_nHeight; i++ )
    {
        for ( int j = 0; j < m_nWidth; j++ )
        {
			/*
            buf[ c + 0 ] = (BYTE) 0;
            buf[ c + 1 ] = (BYTE) 0;
            buf[ c + 2 ] = (BYTE) 255;
  
            c += 3;
			*/
			//tf = m_nGainSlope * ( (float)RGB[(j*m_nWidth + (m_nWidth-i))*3]- m_nGainLevel ) + m_nGainLevel ;
			buf[ (i*m_nWidth + j)*3 + 0 ] = RGB[(i*m_nWidth + (m_nWidth + j))*3 + 0];
            buf[ (i*m_nWidth + j)*3 + 1 ] = RGB[(i*m_nWidth + (m_nWidth + j))*3 + 1];
            buf[ (i*m_nWidth + j)*3 + 2 ] = RGB[(i*m_nWidth + (m_nWidth + j))*3 + 2];
        }
    }

	//dc.TextOutW(100, 400, _T("Test"));

	::StretchDIBits(dc.m_hDC,  // handle to device context
    0,    // x-coordinate of upper-left corner of dest. rectangle
    0,                  // y-coordinate of upper-left corner of dest. rectangle
    m_nWidth,          // width of destination rectangle
    m_nHeight,        // height of destination rectangle
    0,                 // x-coordinate of upper-left corner of source rectangle
    0,                 // y-coordinate of upper-left corner of source rectangle
    m_nWidth,         // width of source rectangle
    m_nHeight,       // height of source rectangle
    buf,           // address of bitmap bits
    (LPBITMAPINFO)&bmInfoHeader,//LPBITMAPINFO address of bitmap data
    DIB_RGB_COLORS, // usage flags
    SRCCOPY);// raster operation code
	
	
	delete buf;


	//UpdateWindow();

}
