
// SpeedCamView.cpp : implementation of the CSpeedCamView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SpeedCam.h"
#endif

#include "SpeedCamDoc.h"
#include "SpeedCamView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSpeedCamView

IMPLEMENT_DYNCREATE(CSpeedCamView, CView)

BEGIN_MESSAGE_MAP(CSpeedCamView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSpeedCamView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_OPEN, &CSpeedCamView::OnFileOpen)
END_MESSAGE_MAP()

// CSpeedCamView construction/destruction

CSpeedCamView::CSpeedCamView()
{
	// TODO: add construction code here

}

CSpeedCamView::~CSpeedCamView()
{
}

BOOL CSpeedCamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	 //cs.cx = 1024;
	 //cs.cy = 768;

	 //cs.style &= ~WS_THICKFRAME; //창 크기 조절 기능 비활성화
	 //cs.style &= ~WS_MAXIMIZEBOX; //창 최대화버튼 비활성화

	return CView::PreCreateWindow(cs);
}

// CSpeedCamView drawing

void CSpeedCamView::OnDraw(CDC* /*pDC*/)
{
	CSpeedCamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
#if 0
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CSpeedCamApp *pApp = (CSpeedCamApp*)pFrame->GetActiveDocument();

	pApp->m_csData.Lock();

	TestBMP(pApp->m_pFormatRGB->GetBits());

	pApp->m_csData.Unlock();
	pApp->m_csData.SetEvent();
#endif
}


// CSpeedCamView printing


void CSpeedCamView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSpeedCamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSpeedCamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpeedCamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSpeedCamView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSpeedCamView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSpeedCamView diagnostics

#ifdef _DEBUG
void CSpeedCamView::AssertValid() const
{
	CView::AssertValid();
}

void CSpeedCamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSpeedCamDoc* CSpeedCamView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpeedCamDoc)));
	return (CSpeedCamDoc*)m_pDocument;
}
#endif //_DEBUG


// CSpeedCamView message handlers


void CSpeedCamView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages

	//CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();

	//HWND hwndBox = ::GetDlgItem(this->m_hWnd);

	//CRect rect;
	
	//dc.GetClipBox(&rect);
	//int x= rect.Width();
	//int y = rect.Height();

	//pAPP->CClientRect = rect;

	//if(pAPP->bResult){
	//	TestBMP(pAPP->m_pFormatRGB->GetBits(),rect);
	//}
	//dc.TextOutW(100, 400, _T("Test"));
	/*
	if(bScripMode != true)
	{
		if(!strFilePath.IsEmpty())
		{
			CImage Image;
			HRESULT hResult = Image.Load(strFilePath);

			Image.BitBlt(dc.m_hDC,0,0);
		}
	}
	UpdateWindow();
	*/
	
}


BOOL CSpeedCamView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return CView::OnEraseBkgnd(pDC);
}


void CSpeedCamView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	SetFocus();

}


void CSpeedCamView::OnFileOpen()
{
	// TODO: Add your command handler code here
	//TRACE(_T("Open"));
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

	if(dlg.DoModal() == IDOK){
		//TRACE(_T("Open"));
		strFilePath = dlg.GetPathName();

		CStdioFile rFile;
		
		if(!rFile.Open(dlg.GetPathName(), CFile::modeRead))
		{
			MessageBox(_T("Can't open file"), _T("Warning"), MB_OK|MB_ICONHAND);
			return;
		}

		bScripMode = true;

		while(rFile.ReadString(strTemp))
		{
			nLength = strTemp.GetLength();
			
			//주석 무시
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
			//BYTE H_ADD = 0x07;
			//BYTE Read_ADD = 0x03;

#if 1
			if(i2c_Checker){
				CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();

				pAPP->USB_I2C_Write(Chip_ID, 0x07, Addr[0]);	//High ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x08, Addr[1]);	//LOW  ADD byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x09, Data[0]);	//High Data byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x0a, Data[1]);	//LOW  Data byte i2c write
				pAPP->USB_I2C_Write(Chip_ID, 0x03, 0x03);	//Write Start
				CString strDebug;
				strDebug.Format(TEXT(">> ADD : 0x%02X%02X  DATA : 0x%02X%02X"), Addr[0],Addr[1],Data[0], Data[1]);
				pAPP->MessageOutput(strDebug);
				
			}
#endif
			
			strTemp.Empty();
			strRead_ADD.Empty();

		}//while
		rFile.Close();

	}


	Invalidate();
}

CString CSpeedCamView::ConvertToHex(CString data)
{
	CString returnV;
	int nDec = 0;
	char szHex[16];

	sprintf_s(szHex, "%04X", _ttoi(data));

	returnV = szHex;

	return returnV;
}


BYTE CSpeedCamView::Hexa2Int2(CString aaa)
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

BYTE CSpeedCamView::Hexa2Int(BYTE ch)
{
	BYTE ret = 0;

	if((ch >= '0') && (ch <= '9'))		ret = ch - '0';
	else if((ch >= 'a') && (ch <= 'f'))	ret = ch - 'a' + 10;
	else if((ch >= 'A') && (ch <= 'F'))	ret = ch - 'A' + 10;
	else					ret = 0;

	return(ret);
}


void CSpeedCamView::TestBMP(BYTE *RGB)
{
	
	int m_nHeight = 1280;
	int m_nWidth = 1024;
	//float tf;
	int m_nGainLevel = 0;
	float m_nGainSlope = 1;

	BYTE* gImgDataRGB2 = new BYTE[m_nHeight * m_nWidth *3];
	
#if 0
	BITMAPINFO bmpInfo;

	bmpInfo.bmiHeader.biSize			= 40;
	bmpInfo.bmiHeader.biWidth			= m_nWidth;	// dwWidth-4;
	bmpInfo.bmiHeader.biHeight			= -m_nHeight;		// dwHeight * (-1);
	bmpInfo.bmiHeader.biPlanes			= 1;
	bmpInfo.bmiHeader.biBitCount		= 3 * 8;			//==> 8 비트 비트맵이라서....
	bmpInfo.bmiHeader.biCompression		= 0;
	bmpInfo.bmiHeader.biSizeImage		= (m_nWidth)*m_nHeight * 3;	// (dwWidth-4) * dwHeight * 3;	//==> 8비트니깐 1을 곱하겠져...
	bmpInfo.bmiHeader.biXPelsPerMeter	= 0;
	bmpInfo.bmiHeader.biYPelsPerMeter	= 0;
	bmpInfo.bmiHeader.biClrUsed			= 0;
	bmpInfo.bmiHeader.biClrImportant	= 0;
#else
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
#endif

	//CWinApp *pApp = AfxGetApp(); 
	//CMainFrame *pFrame = (CMainFrame*)pApp->GetMainWnd(); 
	//CSpeedCamView *pView = (CSpeedCamView*)pFrame->GetActiveView();
	CClientDC dc(this);
	//HWND hWnd = this->m_hWnd;
	//CClientDC dc(pView);
	//CClientDC dc(pView);

	//CDC dc;
    //HDC hdc = ::GetDC(hWnd); // View의 핸들로 View의 DC의 핸들을 얻는다.
    //dc.Attach(hdc); // DC에 View의 DC핸들을 연결시켜 View 에 그리게 된다.


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
#if 0
	CFile file;
	file.Open(_T("BMP_Test.bmp"), CFile::modeNoTruncate | CFile::modeCreate | CFile::modeReadWrite );
	file.Write(&bmFileHeader, sizeof(BITMAPFILEHEADER));
	file.Write(&bmInfoHeader, sizeof(BITMAPINFOHEADER));
	file.Write(buf, bmInfoHeader.biSizeImage);
	file.Close();
#endif
	
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
	delete gImgDataRGB2;

	//OnPaint();
	//ReleaseDC(pDCc);
	//dc.Detach(); // DC 핸들 연결 끊기
    //::ReleaseDC(hWnd, hdc);
}


UINT MyDraw(LPVOID arg)
{

    ThreadArg* pArg = (ThreadArg*)arg;
    CDC dc;
    HDC hdc = ::GetDC(pArg->hWnd); // View의 핸들로 View의 DC의 핸들을 얻는다.
    dc.Attach(hdc); // DC에 View의 DC핸들을 연결시켜 View 에 그리게 된다.
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	CSpeedCamView* pView = (CSpeedCamView*)arg;
	
	pView->bThred_VeiwFlag = true;
#if 1
	while(pView->bThred_VeiwFlag)
	{
		//CWinApp *pwApp = AfxGetApp(); 
		//CMainFrame *pFrame = (CMainFrame*)pwApp->GetMainWnd();
		//CSpeedCamApp *pApp = (CSpeedCamApp*)pFrame->GetActiveDocument();

		
		pAPP->m_csData.Lock();
		int nGetTest = pAPP->nTest;
		TRACE(_T("Thread2 %d\r\n"),nGetTest);

		//TestBMP(pAPP->m_pFormatRGB->GetBits());
		BYTE *RGB = pAPP->m_pFormatRGB->GetBits();
		//---------------------------------------------------------------------------------------------------//
			int m_nHeight = pAPP->MxConfigParam.m_ImageHeight;
			int m_nWidth = pAPP->MxConfigParam.m_ImageWidth;
			//float tf;
			int m_nGainLevel = 0;
			float m_nGainSlope = 1;

			BYTE* gImgDataRGB2 = new BYTE[m_nHeight * m_nWidth *3];
	
		#if 0
			BITMAPINFO bmpInfo;

			bmpInfo.bmiHeader.biSize			= 40;
			bmpInfo.bmiHeader.biWidth			= m_nWidth;	// dwWidth-4;
			bmpInfo.bmiHeader.biHeight			= -m_nHeight;		// dwHeight * (-1);
			bmpInfo.bmiHeader.biPlanes			= 1;
			bmpInfo.bmiHeader.biBitCount		= 3 * 8;			//==> 8 비트 비트맵이라서....
			bmpInfo.bmiHeader.biCompression		= 0;
			bmpInfo.bmiHeader.biSizeImage		= (m_nWidth)*m_nHeight * 3;	// (dwWidth-4) * dwHeight * 3;	//==> 8비트니깐 1을 곱하겠져...
			bmpInfo.bmiHeader.biXPelsPerMeter	= 0;
			bmpInfo.bmiHeader.biYPelsPerMeter	= 0;
			bmpInfo.bmiHeader.biClrUsed			= 0;
			bmpInfo.bmiHeader.biClrImportant	= 0;
		#else
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
		#endif

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

	if(pAPP->m_Set_FitSize)
	{
			CRect rect;
			GetClientRect(pArg->hWnd, &rect);
			::StretchDIBits(dc.m_hDC, 
			rect.left, 
			rect.top, 
			rect.Width(), 
			rect.Height(), 
			0, 
			0, 
			m_nWidth, 
			m_nHeight, 
			buf,
			(LPBITMAPINFO)&bmInfoHeader,
			DIB_RGB_COLORS, // usage flags
			SRCCOPY);// raster operation code
	}
	else{

#if 1//원본 그대로 출력
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
#endif
	}

			delete buf;
			delete gImgDataRGB2;
			//---------------------------------------------------------------------------------------------------//
		pAPP->m_csData.Unlock();
		//pAPP->m_csData.SetEvent();
	}
#endif

#if 0
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	CRect rect;

	
    int i, x, y, inc;
    CBrush brush1(RGB(255, 0, 0));
    CBrush brush2(RGB(0, 0, 255));

    switch (pArg->type)
    {
    case 1: // 위쪽에 사각형 그림
        dc.SelectObject(&brush1);
        x = 100, y = 100;
        for (i = 0; i < 100000; i++)
        {
            inc = i / 200;
            dc.Rectangle(x, y, x + inc, y + 20);
        }
        break;
    case 2: // 아래 쪽에 사각형 그림
        dc.SelectObject(&brush2);
        x = 100, y = 200;
        for (i = 0; i < 100000; i++)
        {
            inc = i / 200;
            dc.Rectangle(x, y, x + inc, y + 20);
        }
        break;
    }
	
    dc.Detach(); // DC 핸들 연결 끊기
    ::ReleaseDC(pArg->hWnd, hdc);
#endif
    return 0;
}


void CSpeedCamView::ShowImage()
{

#if debug
	CClientDC dc(this);
	m_arg1.hWnd = this->m_hWnd;
	m_arg1.type = 1;
	
	m_pThread1 = AfxBeginThread(MyDraw, &m_arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	m_pThread1->SetThreadPriority(THREAD_PRIORITY_NORMAL); // 빠르게 지정
	m_pThread1->ResumeThread();
	
#endif
}

void CSpeedCamView::Start_Th()
{
	m_pThread1 = AfxBeginThread(MyDraw, &m_arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	m_pThread1->SetThreadPriority(THREAD_PRIORITY_HIGHEST); // 빠르게 지정
	m_pThread1->ResumeThread();
}

void CSpeedCamView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	ShowImage();
}
