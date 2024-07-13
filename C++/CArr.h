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
	T* data() { return m_Data; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator [] (int idx);


	void clear() { m_iCount = 0; }
	
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

public:
	CArr();
	~CArr();
// inner Ŭ������ �����ϰ� �ִ� Ŭ������ private���ٰ���
	class iterator
	{
	public:
		CArr*	m_pArr;    // iterator �� ����ų �����͸� �����ϴ� �����迭�ּ�
		T*		m_pData;   // �����͵��� ���� �ּ�
		int		m_iIdx;    // ����Ű�� �������� �ε���
		bool    m_bValid;  // iterator �� ��ȿ�� üũ
		


	public:
		T& operator *()
		{
			// itorator �� �˰��ִ� �ּҿ� �����迭�� �˰� �ִ� �ְ� �޶��� ���(���� Ȯ������  �ּҰ� �޶��� ���)
			if (m_pArr->m_Data != m_pData || -1 == m_iIdx || m_bValid == false)
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// ����
		iterator& operator ++()
		{
			
			

			// 2. end iterator�� ���
			// 3. �ּҰ� ����� ���
			if (m_pArr->m_Data != m_pData || -1 == m_iIdx)
				assert(nullptr);

			// 1. iterator �� ������ �����͸� ����Ű�� �ִ°��
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}
			
			return *this;
		}

		//++ ���� ������
		iterator operator ++(int)
		{
			// fake
			iterator copy_iter = *this;

			++(*this);

			return  copy_iter;
		}




		iterator& operator --()
		{
			return this;
		}
		bool operator ==(const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}

		/*bool operator !=(const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIndx == _otheriter.m_iIndx)
			{
				return false;
			}
			return true;
		}*/
		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
				
		
		}



	public:
		iterator() 
			:m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{}
		iterator(CArr* _m_pArr, T* _m_pData, int _m_iIdx) 
			:m_pArr(_m_pArr)
			, m_pData(_m_pData)
			, m_iIdx(_m_iIdx)
			, m_bValid(false)
		{
			if(nullptr != _m_pArr && 0<= _m_iIdx)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}


		friend class CArr; //private ���� ����
	};



};

template<typename T>
CArr<T>::CArr()
	: m_Data(nullptr), m_iCount(0), m_iMaxCount(1)
{
	//m_pInt = malloc(8)
	m_Data = new int[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_Data;

}
template<typename T>
void CArr<T>::PushBack(const T& _Data)
{


	if (m_iCount >= m_iMaxCount)
	{
		resize(m_iMaxCount * 2);

	}

	m_Data[m_iCount++] = _Data;
}
template<typename T>
void CArr<T>::resize(int _iDataCount)
{
	// �ִ� ���뷮���� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iDataCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* NewArr = new T[_iDataCount];


	for (int i = 0; i < m_iCount; ++i)
	{
		NewArr[i] = m_Data[i];
	}
	delete[] m_Data;
	m_Data = NewArr;
	m_iMaxCount = _iDataCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_Data[idx];  // (m_pInt + idx)
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// ������ ����Ű��  iteraror�� ���� ��ȯ����
	//iterator iter(m_Data,0);
	/*iter.m_pData = this->m_Data;
	iter.m_iIdx = 0;*/
	
	if( 0 == m_iCount)
		return iterator(this, m_Data, -1);  // �����Ͱ� ���� ��� , begin() == end()
	else
		return iterator(this, m_Data, 0);
}


template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_Data, -1);  // �����Ͱ� ���� ��� , begin() == end()
}



template<typename T>
typename CArr<T>::iterator CArr<T>::erase( iterator & _iter)
{
	// itorator �� �ٸ� Arr�� ��ҷ� ����Ű�� ���
	// itorator �� end itorator �� ���
	if (_iter.m_pArr != this || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}
	// itorator�� ����Ű�� �����͸� �迭 ������ �����Ѵ�.
	int iLoopCOunt = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCOunt; ++i)
	{
		m_Data[i + _iter.m_iIdx] = m_Data[i + _iter.m_iIdx + 1];
	}

	_iter.m_bValid = false;

	// ī��Ʈ ����
	--m_iCount;

	return iterator(this, m_Data,_iter.m_iIdx);
}

