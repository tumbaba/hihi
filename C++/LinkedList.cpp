#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* List)
{
	List->pHeadNode = nullptr;
	List->iCount = 0;

}

void PushBack(tLinkedList* List, int Data)
{
	tNode* NewNode = (tNode*)malloc(sizeof(tNode));

	NewNode->iData = Data;
	NewNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지
	if (List->pHeadNode == nullptr)
	{
		List->pHeadNode = NewNode;
	}
	else
	{
		// 현재 가장 마지막 노드로 찾아서
		// 해당 노드의 NewwNode를 생성시킨 노드의 주소로 채움
		

		tNode* CurrNode = List->pHeadNode;
		while (true)
		{
			if (CurrNode->pNextNode == nullptr)
			{
				break;
			}
			else
			{
				CurrNode = CurrNode->pNextNode;
			}
		}
		CurrNode->pNextNode = NewNode;
	}
	++List->iCount;
}

void Release(tNode* List)
{
	if (nullptr == List)
		return;

	Release(List->pNextNode);

	free(List);


	/*tNode* ereasList = List->pNextNode;
	if (ereasList->pNextNode != nullptr)
	{
		ereasList = ereasList->pNextNode;
		ReleaseList(ereasList);
	}
	else
	{
		free(ereasList->pNextNode);
	}
	*/
}
void ReleaseList(tLinkedList* List)
{
	Release(List->pHeadNode);

}

void ReleaseList1(tLinkedList* List)
{
	tNode* DeletNode = List->pHeadNode;

	while (DeletNode)
	{
		tNode* Next = DeletNode->pNextNode;
		free(DeletNode);
		DeletNode = Next;
	}

}

void PushFront(tLinkedList* List, int Data)
{

	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* NewNode = (tNode*)malloc(sizeof(tNode));
	NewNode->iData = Data;
	NewNode->pNextNode = List->pHeadNode;

	// 리스트의 헤드노드 포인터를 갱신한다.
	List->pHeadNode = NewNode;
	++List->iCount;
	

	/*while (serch)
	{
		tNode* Next = serch->pNextNode;
		serch = Next;
		
	}*/
	/*serch->iData = Data;
	serch->pNextNode = nullptr;
	++List->iCount;*/
}
