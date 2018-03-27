#ifndef _RGB_H_
#define _RGB_H_
#pragma once

class CFormatRGB
{
public:
	CFormatRGB(int nWidth, int nHeight, int m_nColorDepth=3);
	virtual ~CFormatRGB();

	bool IsValid()		{	return (NULL != m_pBits) ? true : false;	}
	int GetWidth()		{	return m_nWidth;							}
	int GetHeight()		{	return m_nHeight;							}
	int GetColorDepth()	{	return m_nColorDepth;						}
	int GetBufferSize()	{	return m_nSize;								}
	PBYTE GetBits()		{	return m_pBits;								}

	void SetWidth(int nWidth);
	void SetHeight(int nHeight);
	void SetbPlanes(int nPlanes);

	bool SetBuffer(void);
	bool SetBuffer(DWORD size);
	bool DestroyBuffer(void);

private:
	int m_nWidth;
	int m_nHeight;
	int m_nColorDepth;
	int m_nSize;
	PBYTE m_pBits;
};
#endif