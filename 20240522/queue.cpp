#include "stdafx.h"

struct Node
{
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {}
};

// 큐 클래스 정의

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}
	

	// 큐가 비어있는지 확인

	bool isEmpty()
	{
		return front == nullptr;
	}

	// 큐에 요소를 추가하는 함수

	void enqueue(int data)
	{
		Node* newNode = new Node(data);
		if (rear != nullptr)
		{
			rear->next = newNode;
		}
		rear = newNode;
		if (front == nullptr)
		{
			front = newNode;
		}

	}
		// 큐의 요소를 제거하는 함수
	void dequeue()
	{
	if (isEmpty())
	{
		cout << "Queue is empty. Cannot dequeue." << endl;
		return;
	}
	Node* temp = front;
	front = front->next;
	if (front == nullptr)
	{
		rear = nullptr;
	}
	delete temp;
}
// 큐의 가장 앞에 있는 요소를 반환하는 함수
int frontElement()
{
	if (isEmpty())
	{
		cout << "Quere is empty" << endl;
		return -1; // 에러를 나타내기 위한 값
	}
	return front->data;
}

// 큐를 출력하는 함수
void display()
{
	if (isEmpty())
	{
		cout << "Queue is empty" << endl;
		return;
	}
	Node* temp = front;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// 큐 소멸자: 메모리 누수를 방지하기 위해 모든 노드를 삭제합니다.
~Queue() {
	while (!isEmpty())
	{
		dequeue();
	}
}


};


int main()
{

	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);


	cout << "Front element" << q.frontElement() << endl;
	q.display();

	q.dequeue();
	cout << "Front element after deaueue : " << q.frontElement() << endl;
	q.display();

	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.display();

	return 0;
}