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

// ����Ʈ�� �����迭�� ���ؼ� ã�µ� �ð��� �����ɸ���.
// ������ ����Ʈ
void InitList(tLinkedList* List);

void PushBack(tLinkedList* List, int Data);

void ReleaseList(tLinkedList* List);

void ReleaseList1(tLinkedList* List);

void PushFront(tLinkedList* List, int Data);