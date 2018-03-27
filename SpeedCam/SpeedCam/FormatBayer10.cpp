#include "StdAfx.h"
#include "FormatBayer10.h"
#include "math.h"
#include "USB3_DEV.h"
#include "MarblixUsb3.h"

CFormatBayer10::CFormatBayer10(int nWidth, int nHeight, BYTE SensorMode)
{
	//float DataFactor;

	m_nWidth = nWidth;
	m_nHeight = nHeight;

	m_pBits = NULL;
	//m_pBits = new BYTE[m_nWidth * m_nHeight * 2];
	//if (SensorMode == MX_SENSOR_MIPI) DataFactor = 1.25;
	//else							  DataFactor = 2.00;

	//m_nSize = (int)(ceil((m_nWidth * m_nHeight * DataFactor)/16384.0f)*16384);
}

CFormatBayer10::~CFormatBayer10()
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	} // if
}

void CFormatBayer10::SetWidth(int nWidth)
{
	m_nWidth = nWidth;
}

void CFormatBayer10::SetHeight(int nHeight)
{
	m_nHeight = nHeight;
}

bool CFormatBayer10::SetBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}

	m_pBits = new BYTE[GetBufferSize()];

	return true;
}

bool CFormatBayer10::DestroyBuffer(void)
{
	if(NULL != m_pBits)	{
		delete [] m_pBits;
		m_pBits = NULL;
	}

	return true;
}