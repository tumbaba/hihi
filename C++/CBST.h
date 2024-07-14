#pragma once


enum class NODE_TYPE
{
	PARENT, //0
	LCHILD, 
	RCHILD,
	END,
};




template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};




template<typename T1, typename T2>
struct tBSTNode
{
	//data
	tPair<T1,T2> pair;

	tBSTNode*  arrNode[(int)NODE_TYPE::END];

	//부모노드
	//tBSTNode pParent;
	//
	////자식노드
	//tBSTNode pLeftChild;
	//tBSTNode pRightChild;
	tBSTNode()
		: pair()
		, arrNode{}
	{}

	
	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent ,_pLChild ,_pRChild }
	{}
	
};


template <typename  T1 , typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>	 m_pRoot;
	int					m_iCount;
		
public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

public:
	bool insert(const tPair<T1, T2>& _pair);
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair,nullptr, nullptr);

	/*pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;*/


	//첫번쨰 데이터 라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE ndoe_type = NODE_TYPE::END;


		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				ndoe_type = NODE_TYPE::RCHILD;   // 6:32
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pRightChild;
				}
			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				return false;
			}
		}
	}


}
