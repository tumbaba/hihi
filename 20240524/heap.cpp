#include "stdafx.h"


// ���� ���� ���� Ʈ��(complete binary tree)�̴�
// ���� ���� : Max Heap  �θ� ����� Ű ���� �ڽ� ����� Ű ������ ũ�ų� ���� ��
//             Min Heap  �θ� ����� Ű ���� �ڽ� ����� Ű ������ �۰ų� ���� ��

// �θ� ��� �ε��� : i
// ���� �ڽ� ��� �ε��� : 2*i +1
// ������ �ڽ� ��� �ε��� ; 2*i +2

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