#include "StdAfx.h"
#include "FormatYCbCr.h"

CFormatYCbCr::CFormatYCbCr(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pBits = NULL;
	//m_pBits = new BYTE[m_nWidth * m_nHeight * 2];
}

CFormatYCbCr::~CFormatYCbCr()
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	} // if
}

void CFormatYCbCr::SetWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void CFormatYCbCr::SetHeight(int nHeight)
{
	m_nHeight = nHeight;
}

bool CFormatYCbCr::SetBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}
	double size =   ((m_nHeight * m_nWidth * 2)/16384.0);
	size = size + 0.9;
	//같이 고처줘야함.
	int nsize = (int)size * 16384;
	nsize = 16384;
	m_pBits = new BYTE[nsize];

	return true;
}

bool CFormatYCbCr::DestroyBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}

	return true;
}