#pragma once

#include <assert.h>

template <typename T>
struct tListNode
{
	T			data;
	tListNode*  pNext;
	tListNode*  pPrev;
	
	tListNode() 
		:data(), pNext(nullptr), pPrev(nullptr)
	{}

	tListNode(const T& _data, tListNode<T>* _pNext, tListNode<T>* _pPrev) 
		: data(_data), pNext(_pNext), pPrev(_pPrev)
	{}

	//bool operator==(const tListNode& other) const {
	//	return data == other.data;
	//}

	//// Assignment operator
	//tListNode& operator=(const tListNode& other) {
	//	if (this != &other) {
	//		data = other.data;
	//		pNext = other.pNext;
	//		pPrev = other.pPrev;
	//	}
	//	return *this;
	//}

	//// Pointer access operator
	//tListNode* operator->() {
	//	return this;
	//}
};


template <typename T>
class CList
{
private:
	tListNode<T> m_Head;
	tListNode<T> m_Tail;
	int			 m_iCount;


public:
	void push_back(const T& data); 
	void push_front(const T& data);
	int size() { return m_iCount; }



public:
	CList();
	~CList();

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);


	class iterator
	{
	public:
		CList<T>*		 m_pList;
		tListNode<T>*	 m_pNode;   // null인 경우 iterator end 로 취급
		bool			 m_bValid;
		

	public:
		T& operator *()
		{
			return m_pNode->data;
		}
		

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{

			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			if (m_pNode == nullptr || !m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator operator ++(int)
		{
			iterator copyiter(*this);

			++(*this);

			return copyiter;
		}

		iterator& operator --()
		{
			if (m_pNode == nullptr || !m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pPrev;

			return *this;
		}

		iterator operator --(int)
		{
			iterator copyiter(*this);

			--(*this);

			return copyiter;
		}


	public:

		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)  
			, m_bValid(false)
		{}

		iterator(CList<T>* _pList , tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

		//friend class CList;

	};
};

template<typename T>
 void CList<T>::push_back(const T& data)
{
	// 입력된 데이터를 저장할 노드를 도적할당함
	tListNode<T>* NewNode = new tListNode<T>(data,nullptr,nullptr);

	
	if (  m_Head == nullptr)
	{
		// 처음 입력된 데이터라면
		m_Head = NewNode;
		m_Tail = NewNode;
	}
	else
	{
		// 데이터가 1개 이상인 경우
		// 현대 가장 마지막 데이터(tail) 를 저장하고 있는 노드와
		// 새로 생성된 노드가 서로 가리키게 한다
		m_Tail->pNext = NewNode;
		NewNode->pPver = m_Tail;

		// List가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다.
		m_Tail = NewNode;
	}

	++m_iCount;
}

template<typename T>
 void CList<T>::push_front(const T& data)
{
	 // 새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움
	tListNode<T>* NewNode = new tListNode<T>*(data, m_Head, nullptr);
	// 현재 해드노드의 이전 노드 주소값을 새로 생성된 노드의 주소 채움
	m_Head->pPrev = NewNode;
	// 리스트가 생로 생성된 노드의 주소를 새로운 헤드주소로 갱신한다.
	m_Head = NewNode;

	/*if (m_Head == nullptr)
	{
		m_Head = NewNode;
		m_Tail = NewNode;
	}
	else
	{
		m_Head->pPrev = NewNode;
		NewNode->pNext = m_Head;
		m_Head = NewNode;
	}*/
	++m_iCount;
}

template<typename T>
/*inline*/ CList<T>::CList()
	: m_Head(nullptr), m_Tail(nullptr), m_iCount(0)
{}

template<typename T>
/*inline*/ CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_Head;

	while (pDeletNode)
	{
		tListNode<T>* pNext = pDeletNode->pNext;
		delete(pDeletNode);
		pDeletNode = pNext;
	}
}

template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this,m_Head);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	return iterator();
}


template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter ,const T& _data)
{

	// 리스트에 추가되는 데이터를 저장할 node 생성
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	if (end() == _iter)
	{
		assert(nullptr);
	}

	// iteratir 가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator 가 가리키고 있는 노드의 이전으로 가서
		// 다음노드 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;


		// iterator 가 가리키고 있는 노드의 이전을 새로운 노드로 지정
		// 새로운 노드의 pNext를 iterator가 가리키고 있는 노드로 지정
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	


	return iterator(this, pNode );
}
