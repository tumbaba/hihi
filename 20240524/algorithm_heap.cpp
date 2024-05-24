#include "stdafx.h"
#include <algorithm>


// algorithm 라이브러리에 heap을 표현할 수 있는 함수가 존재


int main()
{
	vector<int> heap = { 30,10,20,5,15,60,6,2 };

	//make_heap을 사용하여 힙 생성 
	make_heap(heap.begin(), heap.end());
	cout << "After maake_heap : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	//push_heap을 사용하여 요소 추가
	heap.push_back(25);
	push_heap(heap.begin(), heap.end());
	cout << "After push_heap(25) : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	// pop_heap 을 사용하여 요소 제거
	pop_heap(heap.begin(), heap.end());
	int maxElement = heap.back();
	heap.pop_back();
	cout << "After pop_heap() : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;
	
	cout << "Popped element : " << maxElement << endl;



	// sort_heap을 사용하여 힙정렬
	sort_heap(heap.begin(), heap.end());
	cout << "After sort_heap : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

