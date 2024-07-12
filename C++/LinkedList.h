#pragma once
typedef struct _tagNode
{
	int					iData;
	struct _tagNode*	pNextNode;
	
}tNode;


typedef struct _tagList
{
	tNode*  pHeadNode;
	int		iCount;
}tLinkedList;

// 리스트는 동적배열에 비해서 찾는데 시간이 오래걸린다.
// 연결형 리스트
void InitList(tLinkedList* List);

void PushBack(tLinkedList* List, int Data);

void ReleaseList(tLinkedList* List);

void ReleaseList1(tLinkedList* List);

void PushFront(tLinkedList* List, int Data);