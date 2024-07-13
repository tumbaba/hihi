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
// inner 클래스를 포함하고 있는 클래스의 private접근가능
	class iterator
	{
	public:
		CArr*	m_pArr;    // iterator 가 가리킬 데이터를 관리하는 가변배열주소
		T*		m_pData;   // 데이터들의 시작 주소
		int		m_iIdx;    // 가리키는 데이터의 인덱스
		bool    m_bValid;  // iterator 의 유효성 체크
		


	public:
		T& operator *()
		{
			// itorator 가 알고있는 주소와 가변배열이 알고 있는 주고가 달라진 경우(공간 확장으로  주소가 달라진 경우)
			if (m_pArr->m_Data != m_pData || -1 == m_iIdx || m_bValid == false)
				assert(nullptr);

			return m_pData[m_iIdx];
		}

		// 전위
		iterator& operator ++()
		{
			
			

			// 2. end iterator인 경우
			// 3. 주소가 변경된 경우
			if (m_pArr->m_Data != m_pData || -1 == m_iIdx)
				assert(nullptr);

			// 1. iterator 가 마지막 데이터를 가리키고 있는경우
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

		//++ 후위 연산자
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


		friend class CArr; //private 공유 가능
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
	// 최대 수용량보다 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iDataCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
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
	// 시작을 가리키는  iteraror를 만들어서 반환해줌
	//iterator iter(m_Data,0);
	/*iter.m_pData = this->m_Data;
	iter.m_iIdx = 0;*/
	
	if( 0 == m_iCount)
		return iterator(this, m_Data, -1);  // 데이터가 없는 경우 , begin() == end()
	else
		return iterator(this, m_Data, 0);
}


template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_Data, -1);  // 데이터가 없는 경우 , begin() == end()
}



template<typename T>
typename CArr<T>::iterator CArr<T>::erase( iterator & _iter)
{
	// itorator 가 다른 Arr쪽 요소룰 가리키는 경우
	// itorator 가 end itorator 인 경우
	if (_iter.m_pArr != this || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}
	// itorator가 가리키는 데이터를 배열 내에서 제거한다.
	int iLoopCOunt = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCOunt; ++i)
	{
		m_Data[i + _iter.m_iIdx] = m_Data[i + _iter.m_iIdx + 1];
	}

	_iter.m_bValid = false;

	// 카운트 감소
	--m_iCount;

	return iterator(this, m_Data,_iter.m_iIdx);
}

