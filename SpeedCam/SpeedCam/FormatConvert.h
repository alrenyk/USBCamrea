#ifndef _FORMATCONVERT_H_
#define _FORMATCONVERT_H_

#include "FormatRGB.h"
#include "FormatYCbCr.h"
#include "FormatBayer8.h"
#include "FormatBayer10.h"
#include "FormatConvert.h"
//#include "FormatRGB.h"

#pragma once

#define PALVERSION 0x300
#define DIB_HEADER_MARKER ((WORD)('M'<<8) | 'B')

//typedef struct tagYCbCr_TABLE
//{
//	int Cb2B[256];
//	int Cr2G[256];
//	int Cb2G[256];
//	int Cr2R[256];
//} YCbCr_TABLE, *pYCbCr_TABLE;

typedef struct tagYCbCr_TABLE
{
	//int Cb2R[256];
	//int Cb2G[256];
	//int Cb2B[256];

	//int Cr2R[256];
	//int Cr2G[256];
	//int Cr2B[256];

	BYTE V2R[256][256];
	BYTE UV2G[256][256][256];
	BYTE U2B[256][256];
} YCbCr_TABLE, *pYCbCr_TABLE;

class CFormatConvert
{
public:
	CFormatConvert();
	virtual ~CFormatConvert();

public:
	PBITMAPINFO GetBitmapInfo()	{	return &m_BitmapInfo;						}

	bool InitYCbCr2RGBTable();

	bool ConvYCbCr_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder=0, bool bFlip=false);
	bool ConvCCIR656N_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder=0, bool bFlip=false);
	bool ConvCCIR656P_RGB(CFormatYCbCr& rYCbCr, CFormatRGB& rRGB, BYTE nOrder=0, bool bFlip=false);
	bool ConvRGB_YCbCr(CFormatRGB& rRGB, CFormatYCbCr& rYCbCr, bool bFlip=false);
	bool ConvRGB_YUV(CFormatRGB& rRGB, CFormatYCbCr& rYCbCr, bool bFlip=false);
	bool ConvBayer8_Gray(CFormatBayer8& rBayer8, CFormatRGB& rRGB, bool bFlip=false);
	bool ConvBayer10_Gray(CFormatBayer10& rBayer10, CFormatRGB& rRGB, BYTE SensorMode, bool bFlip=false);
	bool ConvBayer10_Gray2Bin(CFormatBayer10& rBayer10, CFormatRGB& rRGB, bool bFlip=false);

	bool Save2BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB);
	bool Save2BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB, BITMAPINFO tagBitmapInfo);
	bool Load4BMP(LPCTSTR lpszPathName, CFormatRGB& rRGB);

	bool Save2PPM(LPCTSTR lpszPathName, CFormatRGB& rRGB, UINT nWidth, UINT nHeight);
	
	bool Save2PGM(LPCTSTR lpszPathName, CFormatBayer8& rBayer8, UINT nWidth, UINT nHeight);
	bool Save2PGM(LPCTSTR lpszPathName, CFormatBayer10& rBayer10, UINT nWidth, UINT nHeight);

	bool CreatePalette(BOOL mode);
	SIZE GetSize();

public:
	BITMAPFILEHEADER	m_bmpHeader;
	BITMAPINFO			m_BitmapInfo;
	LPBITMAPINFO		m_pBitmapInfo;
	LPLOGPALETTE		m_lpLogPalette;

	LPSTR				m_pstrDib;
	LPSTR				m_pstrTargetDib;
	int					m_nDumy;
	int					m_nColor;

	CPalette*			m_cPalette;
	pYCbCr_TABLE		m_pYCbCr2RGBTable;
};
#endif