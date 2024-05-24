#include "stdafx.h"
#include <algorithm>


// algorithm ���̺귯���� heap�� ǥ���� �� �ִ� �Լ��� ����


int main()
{
	vector<int> heap = { 30,10,20,5,15,60,6,2 };

	//make_heap�� ����Ͽ� �� ���� 
	make_heap(heap.begin(), heap.end());
	cout << "After maake_heap : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	//push_heap�� ����Ͽ� ��� �߰�
	heap.push_back(25);
	push_heap(heap.begin(), heap.end());
	cout << "After push_heap(25) : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	// pop_heap �� ����Ͽ� ��� ����
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



	// sort_heap�� ����Ͽ� ������
	sort_heap(heap.begin(), heap.end());
	cout << "After sort_heap : ";
	for (const int& elem : heap)
	{
		cout << elem << " ";
	}
	cout << endl;

	return 0;
}

