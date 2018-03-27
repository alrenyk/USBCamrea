#include "StdAfx.h"
#include "FormatConvert.h"
#include "USB3_DEV.h"
#include "MarblixUsb3.h"
#include "SpeedCam.h"

inline BYTE COMP(BYTE chVal) { if(chVal > 255) return 255; if(chVal < 0) return 0; return (BYTE)chVal;}

CFormatConvert::CFormatConvert()
{
	// Default Setting
	//m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	//m_BitmapInfo.bmiHeader.biWidth = 0; 
	//m_BitmapInfo.bmiHeader.biHeight = 0; 
	//m_BitmapInfo.bmiHeader.biPlanes = 1;
	//m_BitmapInfo.bmiHeader.biBitCount = 24; 
	//m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
	//m_BitmapInfo.bmiHeader.biSizeImage = 0; 
	//m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
	//m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
	//m_BitmapInfo.bmiHeader.biClrUsed = 0; 
	//m_BitmapInfo.bmiHeader.biClrImportant = 0; 

	m_pYCbCr2RGBTable = NULL;

	InitYCbCr2RGBTable();
}

CFormatConvert::~CFormatConvert()
{
	if(NULL != m_pYCbCr2RGBTable) {
		delete m_pYCbCr2RGBTable;
		m_pYCbCr2RGBTable = NULL;
	}
}


bool CFormatConvert::InitYCbCr2RGBTable()
{
	int Y, U, V, nMaskPicxlData = 0;

	if(NULL == m_pYCbCr2RGBTable) {
		m_pYCbCr2RGBTable = new YCbCr_TABLE;
	}
	
	for(Y=0; Y<256; Y++) {
		for(U=0; U<256; U++) {
			for(V=0; V<256; V++) {
				m_pYCbCr2RGBTable->V2R[Y][V] = (BYTE)COMP(Y + (BYTE)(1.402*(V-128)));
				m_pYCbCr2RGBTable->UV2G[Y][U][V] = (BYTE)COMP(Y - (BYTE)(0.334*(U-128)) - (BYTE)(0.715*(V-128)));
				m_pYCbCr2RGBTable->U2B[Y][U] = (BYTE)COMP(Y + (BYTE)(1.773*(U-128)));
			}
		}
	}

	//for(i = 0;i < 256;i++) {
	//	nMaskPixelVal = (int)(1.402f * (i - 128 ));				// R
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cr2R[i] = nMaskPixelVal;

	//	nMaskPixelVal = (int)(0.715f * (i - 128 ));				// G
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cr2G[i] = nMaskPixelVal;

	//	nMaskPixelVal = (int)(1.773f * (i - 128 ));				// B
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cb2B[i] = nMaskPixelVal;


	//	nMaskPixelVal = (int)(0.000f * (i - 128 )); // R  Cb
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cb2R[i] = nMaskPixelVal;  // R  Cb
	//	
	//	nMaskPixelVal = (int)(0.344f * (i - 128 )); // G  Cb
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cb2G[i] = nMaskPixelVal; // G  Cb
	//	
	//	nMaskPixelVal = (int)(0.000f * (i - 128 )); // B  Cr
	//		if( nMaskPixelVal < -127 )  nMaskPixelVal=-127;
	//		if( nMaskPixelVal > 127 )  nMaskPixelVal=127;
	//	m_pYCbCr2RGBTable->Cr2B[i] = nMaskPixelVal; // B  Cr

	//} // for(i)

	return true;
}

//==============================================================================================================
// RGB -> YUV data convert
//==============================================================================================================
bool CFormatConvert::ConvRGB_YUV(CFormatRGB& rRGB, CFormatYCbCr& rYCbCr, bool bFlip)
{
	int count = 0;
	int nWidth = rRGB.GetWidth();			//RGB데이터의 가로 길이
	int nHeight = rRGB.GetHeight();			//			  세로 길이

	int i, j, nMaskPicelVal = 0;

	rYCbCr.SetWidth(nWidth);
	rYCbCr.SetHeight(nHeight);
	rYCbCr.SetBuffer();

	PBYTE pSrc = rRGB.GetBits();			//RGB데이터 선언
	PBYTE pTgt = rYCbCr.GetBits();			//YUV데이터 선언
	
	BYTE B, G, R, B2, G2, R2;							//RGB 변환용 각 색값 선언

	for(i=0; i < nHeight; i++) {
		for(j=0; j < nWidth; j+=2) {
			B = *(pSrc);
			G = *(pSrc+1);
			R = *(pSrc+2);
			B2 = *(pSrc+3);
			G2 = *(pSrc+4);
			R2 = *(pSrc+5);

			////////////////////////////////////////////////////////////////////////////////////
			// YUV 변환
			////////////////////////////////////////////////////////////////////////////////////
			nMaskPicelVal = (int)( 0.299 * R + 0.587 * G + 0.114 * B);					// Y0
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*pTgt = nMaskPicelVal;

			nMaskPicelVal = (int)( -0.147 * R - 0.289 * G + 0.436 * B + 128);			// U0
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+1) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.299 * R2 + 0.587 * G2 + 0.114 * B2);				// Y1
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*(pTgt+2) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.615 * R2 - 0.515 * G2 - 0.100 * B2 + 128);			// V1
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+3) = nMaskPicelVal;

/*
			////////////////////////////////////////////////////////////////////////////////////
			// YCbCr 변환
			////////////////////////////////////////////////////////////////////////////////////
			nMaskPicelVal = (int)( 0.299 * R + 0.587 * G + 0.114 * B);					// Y0
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*pTgt = nMaskPicelVal;

			nMaskPicelVal = (int)( -0.169 * R - 0.331 * G + 0.5 * B + 128);				// Cb0
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+1) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.299 * R2 + 0.587 * G2 + 0.114 * B2);				// Y1
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*(pTgt+2) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.500 * R2 - 0.419 * G2 - 0.081 * B2 + 128);			// Cr1
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+3) = nMaskPicelVal;
*/
			pTgt += 4;
			pSrc += 6;
		}
	}

	return true;
}

//==============================================================================================================
// RGB -> YCbCr data convert
//==============================================================================================================
bool CFormatConvert::ConvRGB_YCbCr(CFormatRGB& rRGB, CFormatYCbCr& rYCbCr, bool bFlip)
{
	int count = 0;
	int nWidth = rRGB.GetWidth();			//RGB데이터의 가로 길이
	int nHeight = rRGB.GetHeight();			//			  세로 길이

	int i, j, nMaskPicelVal = 0;

	rYCbCr.SetWidth(nWidth);
	rYCbCr.SetHeight(nHeight);
	rYCbCr.SetBuffer();

	PBYTE pSrc = rRGB.GetBits();			//RGB데이터 선언
	PBYTE pTgt = rYCbCr.GetBits();			//YUV데이터 선언
	
	BYTE B, G, R, B2, G2, R2;				//RGB 변환용 각 색값 선언

	for(i=0; i < nHeight; i++) {
		for(j=0; j < nWidth; j+=2) {
			B = *(pSrc);
			G = *(pSrc+1);
			R = *(pSrc+2);
			B2 = *(pSrc+3);
			G2 = *(pSrc+4);
			R2 = *(pSrc+5);

			/*			
			////////////////////////////////////////////////////////////////////////////////////
			// YUV 변환
			////////////////////////////////////////////////////////////////////////////////////
			nMaskPicelVal = (int)( 0.299 * R + 0.587 * G + 0.114 * B);					// Y0
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*pTgt = nMaskPicelVal;

			nMaskPicelVal = (int)( -0.147 * R - 0.289 * G + 0.436 * B + 128);			// U0
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+1) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.299 * R2 + 0.587 * G2 + 0.114 * B2);				// Y1
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*(pTgt+2) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.615 * R2 - 0.515 * G2 - 0.100 * B2 + 128);			// V1
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+3) = nMaskPicelVal;
			*/


			////////////////////////////////////////////////////////////////////////////////////
			// YCbCr 변환
			////////////////////////////////////////////////////////////////////////////////////
			nMaskPicelVal = (int)( 0.299 * R + 0.587 * G + 0.114 * B);					// Y0
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*pTgt = nMaskPicelVal;

			nMaskPicelVal = (int)( -0.169 * R - 0.331 * G + 0.5 * B + 128);				// Cb0
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+1) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.299 * R2 + 0.587 * G2 + 0.114 * B2);				// Y1
			if( nMaskPicelVal < 0 )  nMaskPicelVal=0;
			if( nMaskPicelVal > 255 )  nMaskPicelVal=255;
			*(pTgt+2) = nMaskPicelVal;

			nMaskPicelVal = (int)( 0.500 * R2 - 0.419 * G2 - 0.081 * B2 + 128);			// Cr1
			if(nMaskPicelVal < 0) nMaskPicelVal = 0;
			if(nMaskPicelVal > 255) nMaskPicelVal = 255;							
			*(pTgt+3) = nMaskPicelVal;

			pTgt += 4;
			pSrc += 6;
		}
	}
	return true;
}

//==============================================================================================================
// YCbCr -> RGB data convert
//==============================================================================================================
bool CFormatConvert::ConvYCbCr_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder, bool bFlip)
{
	int count = 0;
	int x, y, nMaskPixelData = 0;
	int nColorDepth = 0;
	int nWidth = rYCbCr.GetWidth();
	int nHeight = rYCbCr.GetHeight();

	PBYTE pSrc		= rYCbCr.GetBits();

	PBYTE pTgt		= rRGB.GetBits();
	nColorDepth		= rRGB.GetColorDepth();

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight))
	{
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth*8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// used lookuptable
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//BYTE Y1, Cb, Y2, Cr;
	//for(i=0; i < nHeight; i++) {
	//	for(j=0; j < nWidth; j+=2) {
	//		Y1 = *(pSrc);
	//		Cb= *(pSrc+1);
	//		Y2 = *(pSrc+2);
	//		Cr = *(pSrc+3);

	//		*pTgt++ = m_pYCbCr2RGBTable->U2B[Y1][Cb];		//B
	//		*pTgt++ = m_pYCbCr2RGBTable->UV2G[Y1][Cb][Cr];	//G
	//		*pTgt++ = m_pYCbCr2RGBTable->V2R[Y1][Cr];		//R

	//		*pTgt++ = m_pYCbCr2RGBTable->U2B[Y2][Cb];		//B
	//		*pTgt++ = m_pYCbCr2RGBTable->UV2G[Y2][Cb][Cr];	//G
	//		*pTgt++ = m_pYCbCr2RGBTable->V2R[Y2][Cr];		//R

	//		pSrc += 4;
	//	}
	//}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Not used lookuptable
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	BYTE Y1, Cb, Y2, Cr;
	for(y=0; y<nHeight; y++)
	{
		for(x=0; x<nWidth; x+=2)
		{
			switch(nOrder)
			{
				case 0 :	//YUYV
					Cb = *(pSrc);
					Y1 = *(pSrc + 1);
					Cr = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 1 :	//UYVY
					Y1 = *(pSrc);
					Cb = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cr = *(pSrc + 3);
					break;
				case 2 :	//YVYU
					Cr = *(pSrc);
					Y1 = *(pSrc + 1);
					Cb = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 3 :	//VYUY
					Y1 = *(pSrc);
					Cr = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cb = *(pSrc + 3);
					break;
			}

			nMaskPixelData = (int)(Y1 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			pSrc += 4;
		}
	}
	return true;
}

//==============================================================================================================
// CCIR656P NTSC -> RGB data convert
//==============================================================================================================
bool CFormatConvert::ConvCCIR656N_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder, bool bFlip)
{
	int nTgtIndex = 0;
	int x, y, nMaskPixelData = 0;
	int nColorDepth = 0;
	int nWidth = rYCbCr.GetWidth();
	int nHeight = rYCbCr.GetHeight();

	PBYTE pSrc		= rYCbCr.GetBits();

	PBYTE pTgt		= rRGB.GetBits();
	nColorDepth		= rRGB.GetColorDepth();

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight)) {
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth*8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Not used lookuptable
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	BYTE Y1, Cb, Y2, Cr;
	UINT nLineIndex = 0;

	nTgtIndex = 0;
	for(y=0; y<(nHeight/2)+1; y++)
	{
		nLineIndex = (nWidth*3) * (nTgtIndex*2);
		pTgt = rRGB.GetBits();
		pTgt += nLineIndex;
		for(x=0; x<nWidth; x+=2)
		{
			switch(nOrder)
			{
				case 0 :	//YUYV
					Cb = *(pSrc);
					Y1 = *(pSrc + 1);
					Cr = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 1 :	//UYVY
					Y1 = *(pSrc);
					Cb = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cr = *(pSrc + 3);
					break;
				case 2 :	//YVYU
					Cr = *(pSrc);
					Y1 = *(pSrc + 1);
					Cb = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 3 :	//VYUY
					Y1 = *(pSrc);
					Cr = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cb = *(pSrc + 3);
					break;
			}

			nMaskPixelData = (int)(Y1 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			pSrc += 4;
		}
		nTgtIndex++;
	}


	nTgtIndex	= 1;
	for(y=(nHeight/2)+1; y<nHeight; y++)
	{
		nLineIndex = (nWidth*3) * ((nTgtIndex*2)-1);
		pTgt = rRGB.GetBits();
		pTgt += nLineIndex;
		for(x=0; x<nWidth; x+=2)
		{
			switch(nOrder)
			{
				case 0 :	//YUYV
					Cb = *(pSrc);
					Y1 = *(pSrc + 1);
					Cr = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 1 :	//UYVY
					Y1 = *(pSrc);
					Cb = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cr = *(pSrc + 3);
					break;
				case 2 :	//YVYU
					Cr = *(pSrc);
					Y1 = *(pSrc + 1);
					Cb = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 3 :	//VYUY
					Y1 = *(pSrc);
					Cr = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cb = *(pSrc + 3);
					break;
			}

			nMaskPixelData = (int)(Y1 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			pSrc += 4;
		}
	nTgtIndex++;
	}

	return true;
}

//==============================================================================================================
// CCIR656P PAL -> RGB data convert
//==============================================================================================================
bool CFormatConvert::ConvCCIR656P_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder, bool bFlip)
{
	int nTgtIndex = 0;
	int x, y, nMaskPixelData = 0;
	int nColorDepth = 0;
	int nWidth = rYCbCr.GetWidth();
	int nHeight = rYCbCr.GetHeight();

	PBYTE pSrc		= rYCbCr.GetBits();

	PBYTE pTgt		= rRGB.GetBits();
	nColorDepth		= rRGB.GetColorDepth();

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight)) {
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth*8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Not used lookuptable
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	BYTE Y1, Cb, Y2, Cr;
	UINT nLineIndex = 0;

	nTgtIndex = 0;
	for(y=0; y<(nHeight/2); y++)
	{
		nLineIndex = (nWidth*3) * (nTgtIndex*2);
		pTgt = rRGB.GetBits();
		pTgt += nLineIndex;
		for(x=0; x<nWidth; x+=2)
		{
			switch(nOrder)
			{
				case 0 :	//YUYV
					Cb = *(pSrc);
					Y1 = *(pSrc + 1);
					Cr = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 1 :	//UYVY
					Y1 = *(pSrc);
					Cb = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cr = *(pSrc + 3);
					break;
				case 2 :	//YVYU
					Cr = *(pSrc);
					Y1 = *(pSrc + 1);
					Cb = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 3 :	//VYUY
					Y1 = *(pSrc);
					Cr = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cb = *(pSrc + 3);
					break;
			}

			nMaskPixelData = (int)(Y1 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			pSrc += 4;
		}
		nTgtIndex++;
	}


	nTgtIndex	= 1;
	for(y=(nHeight/2)+1; y<nHeight; y++)
	{
		nLineIndex = (nWidth*3) * ((nTgtIndex*2)-1);
		pTgt = rRGB.GetBits();
		pTgt += nLineIndex;
		for(x=0; x<nWidth; x+=2)
		{
			switch(nOrder)
			{
				case 0 :	//YUYV
					Cb = *(pSrc);
					Y1 = *(pSrc + 1);
					Cr = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 1 :	//UYVY
					Y1 = *(pSrc);
					Cb = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cr = *(pSrc + 3);
					break;
				case 2 :	//YVYU
					Cr = *(pSrc);
					Y1 = *(pSrc + 1);
					Cb = *(pSrc + 2);
					Y2 = *(pSrc + 3);
					break;
				case 3 :	//VYUY
					Y1 = *(pSrc);
					Cr = *(pSrc + 1);
					Y2 = *(pSrc + 2);
					Cb = *(pSrc + 3);
					break;
			}

			nMaskPixelData = (int)(Y1 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y1 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.773*(Cb-128));						// B
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 - 0.344*(Cb-128) - 0.715*(Cr-128));		// G
			if(nMaskPixelData < 0) nMaskPixelData = 0;
			if(nMaskPixelData > 255) nMaskPixelData = 255;							
			*pTgt++ = nMaskPixelData;

			nMaskPixelData = (int)(Y2 + 1.402*(Cr-128));						// R
			if( nMaskPixelData < 0 )  nMaskPixelData=0;
			if( nMaskPixelData > 255 )  nMaskPixelData=255;
			*pTgt++ = nMaskPixelData;

			pSrc += 4;
		}
	nTgtIndex++;
	}

	return true;
}

bool CFormatConvert::ConvBayer8_Gray(CFormatBayer8& rBayer8, CFormatRGB& rRGB, bool bFlip)
{
	CSpeedCamApp *pAPP = (CSpeedCamApp*)AfxGetApp();
	int i, count = 0;
	int nColorDepth = 0;
	int nWidth = rBayer8.GetWidth();
	int nHeight = rBayer8.GetHeight();

	PBYTE pSrc = rBayer8.GetBits();
	PBYTE pTgt = rRGB.GetBits();

	nColorDepth		= rRGB.GetColorDepth();
	//CString str;
	

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight)) {
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth * 8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}

	CString str;
	CString sData;
	CString str_index;

	CFile wfile;
#if 0
	int ni = 1;
#endif
	for (i = 0; i < nWidth*nHeight; i++)
	{
		*pTgt++ = pSrc[i];
		*pTgt++ = pSrc[i];
		*pTgt++ = pSrc[i];


#if 0
		str.Format(_T("0x%02X "),pSrc[i]);
		str_index.Format(_T("Index [ 0x%02X ]"), i);
		sData.Append(str);

			if((ni%16) == 0){
				sData.Append(str_index + _T("\n"));

			}
		ni ++;
#endif
	}
#if 0
	wfile.Open(_T("test.txt"), CFile::modeCreate | CFile::modeWrite, NULL);
	wfile.Write(sData, sData.GetLength() * sizeof(TCHAR));
	wfile.Close();
#endif
	return true;
}

bool CFormatConvert::ConvBayer10_Gray(CFormatBayer10& rBayer10, CFormatRGB& rRGB, BYTE SensorMode, bool bFlip)
{
	int i, count = 0;
	int nColorDepth = 0;
	int nWidth = rBayer10.GetWidth();
	int nHeight = rBayer10.GetHeight();

	PBYTE pSrc = rBayer10.GetBits();
	PBYTE pTgt = rRGB.GetBits();

	nColorDepth		= rRGB.GetColorDepth();

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight)) {
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth * 8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}

	if (SensorMode == MX_SENSOR_MIPI)
	{
		int temp = rBayer10.GetBufferSize();
		//for (i = 1; i < rBayer10.GetBufferSize(); i+=2)
		//{
		//	BYTE SrcVal = pSrc[i];
		//	*pTgt++ = pSrc[i];
		//	*pTgt++ = pSrc[i];
		//	*pTgt++ = pSrc[i];
		//}
		// i : Dst Pointer 921600 (hxwx3)
		// k : Src Pointer 384000 (hxwx1.25)
		int k= 0;
		for (i = 0; i < (nWidth*nHeight); i+=4)
		{
			//BYTE SrcVal = pSrc[i];
			*pTgt++ = pSrc[k];
			*pTgt++ = pSrc[k];
			*pTgt++ = pSrc[k];
			*pTgt++ = pSrc[k+1];
			*pTgt++ = pSrc[k+1];
			*pTgt++ = pSrc[k+1];
			*pTgt++ = pSrc[k+2];
			*pTgt++ = pSrc[k+2];
			*pTgt++ = pSrc[k+2];
			*pTgt++ = pSrc[k+3];
			*pTgt++ = pSrc[k+3];
			*pTgt++ = pSrc[k+3];
			k = k+5;
		}
	}
	else
	{
		for (i = 0; i < (nWidth*nHeight)*2; i+=2)
		{
			//BYTE SrcVal = pSrc[i];
			*pTgt++ = pSrc[i];
			*pTgt++ = pSrc[i];
			*pTgt++ = pSrc[i];
		}
	}
	return true;
}

bool CFormatConvert::ConvBayer10_Gray2Bin(CFormatBayer10& rBayer10, CFormatRGB& rRGB, bool bFlip)
{
	UINT i, x, y;
	UINT nColorDepth = 0;
	UINT nWidth = rBayer10.GetWidth();
	UINT nHeight = rBayer10.GetHeight();
	
	UINT nIndex;

	UINT nGray2BinConv1[692];
	UINT nGray2BinConv2[1384];
	UINT nGray2BinSrc = 0;

	PBYTE pSrc = rBayer10.GetBits();
	PBYTE pTgt = rRGB.GetBits();

	nColorDepth		= rRGB.GetColorDepth();

	if((m_BitmapInfo.bmiHeader.biWidth != nWidth) || (m_BitmapInfo.bmiHeader.biHeight != nHeight)) {
		// Initialize
		m_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		m_BitmapInfo.bmiHeader.biWidth = nWidth; 
		m_BitmapInfo.bmiHeader.biHeight = (nHeight*(-1)); 
		m_BitmapInfo.bmiHeader.biPlanes = 1;
		m_BitmapInfo.bmiHeader.biBitCount = nColorDepth * 8; 
		m_BitmapInfo.bmiHeader.biCompression = BI_RGB; 
		m_BitmapInfo.bmiHeader.biSizeImage = nWidth * nHeight * nColorDepth; 
		m_BitmapInfo.bmiHeader.biXPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biYPelsPerMeter = 0; 
		m_BitmapInfo.bmiHeader.biClrUsed = 0; 
		m_BitmapInfo.bmiHeader.biClrImportant = 0; 
	}

	memset(nGray2BinConv1, 0, sizeof(UINT)*692);
	memset(nGray2BinConv2, 0, sizeof(UINT)*1384);

	for (i = 0; i < (nWidth/2); i++)
	{
		nGray2BinConv1[i] |= (((i >> 10)&0x01)) << 10;
		nGray2BinConv1[i] |= (((i >> 10)&0x01) ^ ((i >> 9)&0x01)) << 9;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 9)&0x01) ^ ((i >> 8)&0x01)) << 8;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 8)&0x01) ^ ((i >> 7)&0x01)) << 7;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 7)&0x01) ^ ((i >> 6)&0x01)) << 6;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 6)&0x01) ^ ((i >> 5)&0x01)) << 5;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 5)&0x01) ^ ((i >> 4)&0x01)) << 4;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 4)&0x01) ^ ((i >> 3)&0x01)) << 3;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 3)&0x01) ^ ((i >> 2)&0x01)) << 2;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 2)&0x01) ^ ((i >> 1)&0x01)) << 1;
		nGray2BinConv1[i] |= (((nGray2BinConv1[i] >> 1)&0x01) ^ ((i >> 0)&0x01)) << 0;
	}


	for (i = 0; i < nWidth; i+=2)
	{
		nGray2BinConv2[i] = nGray2BinConv1[i/2] * 2;
		nGray2BinConv2[i+1] = (nGray2BinConv1[i/2] * 2) + 1;
	}

	for( y = 0; y < nHeight; y++)
	{
		for( x = 0; x < nWidth; x++)
		{
			nIndex = nGray2BinConv2[x];

			if (nIndex >= (nWidth-1))
			{
				*pTgt++ = 255;
				*pTgt++ = 0;
				*pTgt++ = 0;
			}
			else
			{
				//nGray2BinSrc = ((pSrc[(y*nWidth*2) + (nIndex+1)]) << 2) | ((pSrc[(y*nWidth*2) + (nIndex+0)]) >> 6);

				*pTgt++ = pSrc[(y*nWidth*2) + (nIndex + (nIndex+1))];
				*pTgt++ = pSrc[(y*nWidth*2) + (nIndex + (nIndex+1))];
				*pTgt++ = pSrc[(y*nWidth*2) + (nIndex + (nIndex+1))];
			}
		}
	}

	return true;
}

bool CFormatConvert::Load4BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB)
{
//	int					nDumy, nColor;
	PBYTE				pDib, pTargetDib;
	DWORD				size,len;

	HANDLE fd=CreateFile(lpszPathName,GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);

	if(fd < 0) return false;
	if(!ReadFile(fd, (LPSTR)&m_bmpHeader, sizeof(m_bmpHeader), &len, NULL)) return false;
	if (m_bmpHeader.bfType != DIB_HEADER_MARKER) return false;

	size = m_bmpHeader.bfSize-sizeof(m_bmpHeader);

	pTargetDib = new BYTE[size];

	if(!ReadFile(fd, pTargetDib, size, &len, NULL)) return false;
	if(len != size) return false;

	CloseHandle(fd);

	m_BitmapInfo = *(LPBITMAPINFO)pTargetDib;

	if (m_BitmapInfo.bmiHeader.biBitCount != 24) {
		AfxMessageBox(TEXT("This TMBV is only support 24bit color!!!"));
		return false;
	}

	rRGB.SetWidth((int) m_BitmapInfo.bmiHeader.biWidth);
	rRGB.SetHeight((int) m_BitmapInfo.bmiHeader.biHeight);
	rRGB.SetBuffer(size);

	pDib = rRGB.GetBits();
	memcpy(pDib, (pTargetDib + *(LPDWORD)pTargetDib), size);

	delete pTargetDib;

	return true;
}

bool CFormatConvert::Save2BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB)
{
	HANDLE hFile = ::CreateFile(lpszPathName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(INVALID_HANDLE_VALUE == hFile)
	{
		return false;
	} // if

	ULONG dumy = (m_BitmapInfo.bmiHeader.biWidth * 3) % 4;
	((4-dumy)==4)?dumy = 0:dumy = 4-dumy;

	ULONG nImageSize = ((m_BitmapInfo.bmiHeader.biWidth*3)+dumy) * abs(m_BitmapInfo.bmiHeader.biHeight);


	if (m_bmpHeader.bfType != DIB_HEADER_MARKER) {
		m_bmpHeader.bfType = DIB_HEADER_MARKER;
		m_bmpHeader.bfSize = sizeof(BITMAPFILEHEADER) + m_BitmapInfo.bmiHeader.biSize + nImageSize;
		m_bmpHeader.bfReserved1 = 0;
		m_bmpHeader.bfReserved2 = 0;
		m_bmpHeader.bfOffBits = 54;
	}

	DWORD NumberOfBytesWritten;
	BOOL bSuccess = ::WriteFile(hFile, &m_bmpHeader, sizeof(BITMAPFILEHEADER), &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);
		
		return false;
	} // if

	bSuccess = ::WriteFile(hFile, &m_BitmapInfo, m_BitmapInfo.bmiHeader.biSize, &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);

		return false;
	} // if

	PBYTE pRGBData = rRGB.GetBits();
	bSuccess = ::WriteFile(hFile, pRGBData, nImageSize, &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);

		return false;
	} // if

	::CloseHandle(hFile);

	return true;
} // CMyBitmap::Save()

bool CFormatConvert::Save2BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB, BITMAPINFO tagBitmapInfo)
{
	HANDLE hFile = ::CreateFile(lpszPathName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if(INVALID_HANDLE_VALUE == hFile) {
		return false;
	} // if

	ULONG dumy = (tagBitmapInfo.bmiHeader.biWidth * 3) % 4;
	((4-dumy)==4)?dumy = 0:dumy = 4-dumy;

	ULONG nImageSize = ((tagBitmapInfo.bmiHeader.biWidth*3)+dumy) * abs(tagBitmapInfo.bmiHeader.biHeight);


	if (m_bmpHeader.bfType != DIB_HEADER_MARKER) {
		m_bmpHeader.bfType = DIB_HEADER_MARKER;
		m_bmpHeader.bfSize = sizeof(BITMAPFILEHEADER) + tagBitmapInfo.bmiHeader.biSize + nImageSize;
		m_bmpHeader.bfReserved1 = 0;
		m_bmpHeader.bfReserved2 = 0;
		m_bmpHeader.bfOffBits = 54;
	}

	DWORD NumberOfBytesWritten;
	BOOL bSuccess = ::WriteFile(hFile, &m_bmpHeader, sizeof(BITMAPFILEHEADER), &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);
		
		return false;
	} // if

	bSuccess = ::WriteFile(hFile, &tagBitmapInfo, tagBitmapInfo.bmiHeader.biSize, &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);

		return false;
	} // if

	PBYTE pRGBData = rRGB.GetBits();
	bSuccess = ::WriteFile(hFile, pRGBData, nImageSize, &NumberOfBytesWritten, NULL);
	if(!bSuccess) {
		::CloseHandle(hFile);

		return false;
	} // if

	::CloseHandle(hFile);

	return true;
} // CMyBitmap::Save()

bool CFormatConvert::Save2PPM(LPCTSTR lpszPathName, CFormatRGB& rRGB, UINT nWidth, UINT nHeight)
{
	UINT x, y;
	PBYTE pRGB;
	CString strType;
	CString strWidth;
	CString strHeight;
	CString strSize;
	CString strData;

	CStdioFile		stdfd;

	if( !stdfd.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite, NULL ) )
	{
		AfxMessageBox(_T("Can not save Image."));
		return false;
	}

	pRGB		= rRGB.GetBits();
	strType		= _T("P3");
	strSize		= _T("255");
	strWidth.Format(_T("%d"), nWidth);
	strHeight.Format(_T("%d"), nHeight);

	stdfd.WriteString(strType);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strWidth + _T(" ") + strHeight);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strSize);
	stdfd.WriteString(_T("\r\n"));

	for( y = 0; y < nHeight; y++)
	{
		for( x = 0; x < (nWidth * 3); x+=3)
		{
			strData.Format(_T("%d"), pRGB[(y*nWidth*3)+x+2]);	//R
			stdfd.WriteString(strData + _T(" "));

			strData.Format(_T("%d"), pRGB[(y*nWidth*3)+x+1]);	//G
			stdfd.WriteString(strData + _T(" "));

			strData.Format(_T("%d"), pRGB[(y*nWidth*3)+x+0]);	//B
			stdfd.WriteString(strData + _T(" "));

			stdfd.WriteString(_T("  "));

		}
		stdfd.WriteString(_T("\r\n"));
	}

	delete pRGB;

	stdfd.Close();

	return true;
}

bool CFormatConvert::Save2PGM(LPCTSTR lpszPathName, CFormatBayer8& rBayer8, UINT nWidth, UINT nHeight)
{
	UINT x, y;
	PBYTE pBayer;
	CString strType;
	CString strWidth;
	CString strHeight;
	CString strSize;
	CString strData;

	CStdioFile		stdfd;

	if( !stdfd.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite, NULL ) )
	{
		AfxMessageBox(_T("Can not save Image."));
		return false;
	}

	pBayer		= rBayer8.GetBits();
	strType		= _T("P2");
	strSize		= _T("255");
	strWidth.Format(_T("%d"), nWidth);
	strHeight.Format(_T("%d"), nHeight);

	stdfd.WriteString(strType);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strWidth + _T(" ") + strHeight);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strSize);
	stdfd.WriteString(_T("\r\n"));

	for( y = 0; y < nHeight; y++)
	{
		for( x = 0; x < nWidth; x++)
		{
			strData.Format(_T("%d"), pBayer[(y*nWidth)+x]);
			stdfd.WriteString(strData + _T(" "));
		}
		stdfd.WriteString(_T("\r\n"));
	}

	delete pBayer;

	stdfd.Close();
	return true;
}

bool CFormatConvert::Save2PGM(LPCTSTR lpszPathName, CFormatBayer10& rBayer10, UINT nWidth, UINT nHeight)
{
	UINT i, x, y;
	PBYTE pBayer;

	CString strType;
	CString strWidth;
	CString strHeight;
	CString strSize;
	CString strData;

	CStdioFile		stdfd;

	if( !stdfd.Open(lpszPathName, CFile::modeCreate | CFile::modeWrite, NULL ) )
	{
		AfxMessageBox(_T("Can not save Image."));
		return false;
	}

	pBayer		= rBayer10.GetBits();
	strType		= _T("P2");
	strSize		= _T("1023");
	strWidth.Format(_T("%d"), nWidth);
	strHeight.Format(_T("%d"), nHeight);

	stdfd.WriteString(strType);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strWidth + _T(" ") + strHeight);
	stdfd.WriteString(_T("\r\n"));

	stdfd.WriteString(strSize);
	stdfd.WriteString(_T("\r\n"));

	for( y = 0; y < nHeight; y++)
	{
		for( x = 0; x < (nWidth*2); x+=2)
		{
			i = ((pBayer[(y*nWidth*2)+x+1]) << 2) | ((pBayer[(y*nWidth*2)+x+0]) >> 6);

			strData.Format(_T("%d"), i);
			stdfd.WriteString(strData + _T(" "));
		}
		stdfd.WriteString(_T("\r\n"));
	}

	delete pBayer;

	stdfd.Close();
	return true;
}

bool CFormatConvert::CreatePalette(BOOL mode)
{
	int r, g, b;

	if(m_cPalette)
		delete m_cPalette;
	if(m_lpLogPalette)
		delete m_lpLogPalette;

	m_cPalette		= NULL;
	m_lpLogPalette	= NULL;

	m_lpLogPalette = (LPLOGPALETTE) new char[sizeof(LOGPALETTE) + sizeof(PALETTEENTRY)*m_nColor];
	m_cPalette = new CPalette;

	if(m_lpLogPalette == NULL|| m_cPalette==NULL)
		return false;

	m_lpLogPalette->palVersion		= PALVERSION;
	m_lpLogPalette->palNumEntries	= m_nColor;

	if(mode)
	{
		for(int i=0;i<m_nColor;i++)
		{
			m_lpLogPalette->palPalEntry[i].peRed	= m_pBitmapInfo->bmiColors[i].rgbRed;
			m_lpLogPalette->palPalEntry[i].peGreen	= m_pBitmapInfo->bmiColors[i].rgbGreen;
			m_lpLogPalette->palPalEntry[i].peBlue	= m_pBitmapInfo->bmiColors[i].rgbBlue;
		}
	}
	else
	{
		int i=0;
		for(r=0;r<256;r+=51)
		{
			for(g=0;g<256;g+=51)
			{
				for(b=0;b<256;b+=51)
				{
					m_lpLogPalette->palPalEntry[i].peRed=r;
					m_pBitmapInfo->bmiColors[i].rgbRed=r;
					m_lpLogPalette->palPalEntry[i].peGreen=g;
					m_pBitmapInfo->bmiColors[i].rgbGreen=g;
					m_lpLogPalette->palPalEntry[i].peBlue=b;
					m_pBitmapInfo->bmiColors[i].rgbBlue=b;
					i++;
					if(i>m_nColor)
						return true;
				}
			}
		}
	}
	m_cPalette->CreatePalette(m_lpLogPalette);
	return true;
}

SIZE CFormatConvert::GetSize()
{
	SIZE size;
	size.cx = m_pBitmapInfo->bmiHeader.biWidth;
	size.cy = m_pBitmapInfo->bmiHeader.biHeight;
	return size;
}