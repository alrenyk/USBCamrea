#include "StdAfx.h"
#include "FormatBayer8.h"

CFormatBayer8::CFormatBayer8(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pBits = NULL;
	//m_pBits = new BYTE[m_nWidth * m_nHeight * 2];
}

CFormatBayer8::~CFormatBayer8()
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	} // if
}

void CFormatBayer8::SetWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void CFormatBayer8::SetHeight(int nHeight)
{
	m_nHeight = nHeight;
}

bool CFormatBayer8::SetBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}
	//test code
#if 0
	int nSize = 1280 * 1024;
	m_pBits = new BYTE[nSize];
#else
	int nSize = GetBufferSize();
	m_pBits = new BYTE[GetBufferSize()];
#endif

	return true;
}

bool CFormatBayer8::DestroyBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}

	return true;
}