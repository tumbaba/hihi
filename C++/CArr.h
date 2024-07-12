#pragma once


#include <assert.h>

template<typename T>
class CArr
{
private:

	T*	 m_Data;
	int  m_iCount;
	int  m_iMaxCount;

public:

	void PushBack(const T& Data);
	void resize(int _iDataCount);

	T& operator [] (int idx);

public:
	CArr();
	~CArr();
};

template<typename T>
CArr<T>::CArr()
	: m_Data(nullptr), m_iCount(0), m_iMaxCount(0)
{
	//m_pInt = malloc(8)
	m_Data = new int[2];
}

CArr::~CArr()
{
	delete[] m_Data;

}

void CArr::PushBack(const T&)
{


	if (this->m_iCount >= this->m_iMaxCount)
	{


	}

	this->m_Data[this->m_iCount++] = Data;
}

void CArr::resize(int _iDataCount)
{
	// �ִ� ���뷮���� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iDataCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	int* NewArr = new int[_iDataCount];


	for (int i = 0; i < m_iCount; ++i)
	{
		NewArr[i] = m_Data[i];
	}
	delete[] m_Data;
	m_Data = NewArr;
	m_iMaxCount = _iDataCount;
}

T& CArr::operator[](int idx)
{
	return m_Data[idx];  // (m_pInt + idx)
}


