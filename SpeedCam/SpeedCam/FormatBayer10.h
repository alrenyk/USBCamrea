#ifndef _Bayer10_H_
#define _Bayer10_H_
#pragma once

class CFormatBayer10
{
public:
	CFormatBayer10(int nWidth, int nHeight, BYTE SensorMode);
	virtual ~CFormatBayer10();

	bool IsValid()					{return (NULL != m_pBits) ? true : false;	}
	int GetWidth()					{return m_nWidth;							}
	int GetHeight()					{return m_nHeight;							}
	int GetBufferSize()				{return m_nSize;							}
	PBYTE GetBits()					{return m_pBits;							}
	void SetWidth(int nWidth);
	void SetHeight(int nHeight);
	bool SetBuffer(void);
	bool DestroyBuffer(void);

	PBYTE m_pBits;

private:
	int m_nWidth;
	int m_nHeight;
	int m_nSize;
};
#endif
