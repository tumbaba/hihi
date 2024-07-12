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

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (List->pHeadNode == nullptr)
	{
		List->pHeadNode = NewNode;
	}
	else
	{
		// ���� ���� ������ ���� ã�Ƽ�
		// �ش� ����� NewwNode�� ������Ų ����� �ּҷ� ä��
		

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

	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* NewNode = (tNode*)malloc(sizeof(tNode));
	NewNode->iData = Data;
	NewNode->pNextNode = List->pHeadNode;

	// ����Ʈ�� ����� �����͸� �����Ѵ�.
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
