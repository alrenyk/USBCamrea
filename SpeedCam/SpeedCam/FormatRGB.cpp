#include "StdAfx.h"
#include "FormatRGB.h"

CFormatRGB::CFormatRGB(int nWidth, int nHeight, int nColorDepth)
{
	m_nWidth		= nWidth;
	m_nHeight		= nHeight;
	m_nColorDepth	= nColorDepth;

	m_pBits = NULL;

	m_nSize = m_nWidth * m_nHeight * 3;
	//m_pBits = new BYTE[m_nWidth * m_nHeight * 3];
}

CFormatRGB::~CFormatRGB()
{
	if(NULL != m_pBits)
	{
		delete m_pBits;
		m_pBits = NULL;
	} // if
}

void CFormatRGB::SetWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void CFormatRGB::SetHeight(int nHeight)
{
	m_nHeight = nHeight;
}

bool CFormatRGB::SetBuffer(void)
{
	if(NULL != m_pBits)
	{
		delete m_pBits;
		m_pBits = NULL;
	}
#if 0
	double size =   ((m_nHeight * m_nWidth * 2)/16384.0);
	size = size + 0.9;
	//같이 고처줘야함.
	int nsize = (int)size * 16384;
#else
	int nsize = m_nHeight * m_nWidth;
#endif
	m_pBits = new BYTE[GetBufferSize()];

	return true;
}

bool CFormatRGB::SetBuffer(DWORD size)
{
	if(NULL != m_pBits)
	{
		delete m_pBits;
		m_pBits = NULL;
	}

	m_pBits = new BYTE[size];

	return true;
}

bool CFormatRGB::DestroyBuffer(void)
{
	if(NULL != m_pBits)
	{
		delete m_pBits;
		m_pBits = NULL;
	}

	return true;
}