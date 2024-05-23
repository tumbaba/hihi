#include "stdafx.h"
//set의 특징

// 1. 중복을 허용안함
// 2. 정렬 자동정렬, 내림차순
// 3. 검색, 삽입, 삭제가 빠르다.



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