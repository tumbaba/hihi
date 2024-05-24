#include "stdafx.h"


// 힙은 완전 이진 트리(complete binary tree)이다
// 힙의 종류 : Max Heap  부모 노드의 키 갓이 자식 노드의 키 값보다 크거나 같은 힙
//             Min Heap  부모 노드의 키 밧이 자식 노드의 키 값보다 작거나 같은 힙

// 부모 노드 인덱스 : i
// 왼쪽 자식 노드 인덱스 : 2*i +1
// 오른쪽 자식 노드 인덱스 ; 2*i +2

class MaxHeap
{
private:
	vector<int> heap;

	void heapifyUp(int index)
	{
		int parentIndex = (index - 1) / 2;
		if (index > 0 && heap[index] > heap[parentIndex])
		{
			swap(heap[index], heap[parentIndex]);
			heapifyUp(parentIndex);
		}
	}

	void heapifyDown(int index)
	{
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;
		int largestIndex = index;

		if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex])
		{
			largestIndex = leftChildIndex;
		}
		if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex])
		{
			largestIndex = rightChildIndex;
		}

		if (largestIndex != index)
		{
			swap(heap[index], heap[largestIndex]);
			heapifyDown(largestIndex);
		}
	}

public:
	void insert(int elemet)
	{
		heap.push_back(elemet);
		heapifyUp(heap.size() - 1);
	}

	int deleteMax()
	{
		if (heap.size() == 0) return -1; // or throw an exception

		int maxValue = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
		return maxValue;
	}

	void printHeap()
	{
		for (int i = 0; i < heap.size(); i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}









};


int main()
{
	MaxHeap maxHeap;
	
	maxHeap.insert(50);
	maxHeap.insert(30);
	maxHeap.insert(20);
	maxHeap.insert(15);
	maxHeap.insert(10);
	maxHeap.insert(8);
	maxHeap.insert(16);


	cout << "Max Heap : ";
	maxHeap.printHeap();

	cout << "Deleted max : " << maxHeap.deleteMax() << endl;
	cout << "Max Heap after deletion : ";
	maxHeap.printHeap();



	return 0;
}