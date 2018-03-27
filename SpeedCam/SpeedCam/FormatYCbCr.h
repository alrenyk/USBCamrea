#ifndef _YCBCR_H_
#define _YCBCR_H_
#pragma once

class CFormatYCbCr
{
public:
	CFormatYCbCr(int nWidth, int nHeight);
	virtual ~CFormatYCbCr();

	bool IsValid()					{return (NULL != m_pBits) ? true : false;	}
	int GetWidth()					{return m_nWidth;							}
	int GetHeight()					{return m_nHeight;							}
	int GetBufferSize()				{return ((m_nHeight * m_nWidth * 2)/16384);			}
	PBYTE GetBits()					{return m_pBits;							}
	void SetWidth(int nWidth);
	void SetHeight(int nHeight);
	bool SetBuffer(void);
	bool DestroyBuffer(void);

	PBYTE m_pBits;

private:
	int m_nWidth;
	int m_nHeight;
};
#endif
