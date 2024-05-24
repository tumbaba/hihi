#include "stdafx.h"

struct Node
{
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {}
};

// ť Ŭ���� ����

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}
	

	// ť�� ����ִ��� Ȯ��

	bool isEmpty()
	{
		return front == nullptr;
	}

	// ť�� ��Ҹ� �߰��ϴ� �Լ�

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
		// ť�� ��Ҹ� �����ϴ� �Լ�
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
// ť�� ���� �տ� �ִ� ��Ҹ� ��ȯ�ϴ� �Լ�
int frontElement()
{
	if (isEmpty())
	{
		cout << "Quere is empty" << endl;
		return -1; // ������ ��Ÿ���� ���� ��
	}
	return front->data;
}

// ť�� ����ϴ� �Լ�
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

// ť �Ҹ���: �޸� ������ �����ϱ� ���� ��� ��带 �����մϴ�.
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