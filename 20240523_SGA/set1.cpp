#include "stdafx.h"
//set�� Ư¡

// 1. �ߺ��� ������
// 2. ���� �ڵ�����, ��������
// 3. �˻�, ����, ������ ������.



int main()
{
	set<int> mySet; //size 0

	if (mySet.empty())
	{
		mySet.insert(5);
		mySet.insert(4);
		mySet.insert(10);
		mySet.insert(90);
		mySet.insert(23);

	}
	mySet.insert(23);

	for (int value : mySet)
	{
		cout << value << " ";
	}
	cout << endl;
	cout << mySet.size();


	return 0;
}