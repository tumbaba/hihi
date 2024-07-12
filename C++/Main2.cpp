#include <iostream>
#include "LinkedList.h"


int main()
{
	tLinkedList list;
	InitList(&list);

	
	PushBack(&list, 200);
	PushBack(&list, 300);
	PushBack(&list, 400);
	PushBack(&list, 500);
	PushBack(&list, 100);

	ReleaseList1(&list);
		



	return 0;
}