#include "stdafx.h"

// Linked List를 활용한 동적stack

class Node
{
public:
	int data;
	Node* next;
	Node(int data) : data(data), next(nullptr) {}
};

class Stack
{
private:
	Node* top;
public:
	Stack() { top = nullptr; }

	void push(int x)
	{
		Node* newNode = new Node(x);
		newNode->next = top;
		top = newNode;
	}
	//int pop()
	//{
	//	if (!top)
	//	{
	//		cout << "Stack Underflow" << endl;
	//		return -1;  // stack data안에 -1이 있으면 잘못됨
	//	}
	//	else
	//	{
	//		Node* temp = top;
	//		top = top->next;
	//		int popped = temp->data;
	//		delete temp;
	//		return popped;
	//	}
	//}

	std::optional<int> pop()
	{
		if (!top)
		{
			cout << "Stakc Underflow" << endl;
			return nullopt;
		}
		else
		{
			Node* temp = top;
			top = top->next;
			int popped = temp->data;
			delete temp;
			return popped;
		}
	}

	/*int peek()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}
		else
		{
			return top->data;
		}
	}*/
	optional<int>peek()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return nullopt;
		}
		else
		{
			return top->data;
		}
	}
	bool isEmpty()
	{
		return top == nullptr;
	}

	int size()
	{
		int count = 0;
		Node* current = top;
		while (current)
		{
			count++;
			current = current->next;
		}
		return count;
	}

};

; int main()
{
	Stack s;
	cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
	auto topElement = s.peek();
	if(topElement)
	{
		cout << "Top element : " << *topElement << endl;
	}
	else
	{
		cout << "Stack Underflow" << endl;
	}
	auto poppedElement = s.pop();
	if (poppedElement)
	{
		cout << "popped element" << *poppedElement << endl;
	}
	else
	{
		cout << "stack Underfolw" << endl;
	}
	topElement = s.peek();
	if (topElement)
	{
		cout << "Top element : " << *topElement << endl;
	}
	else
	{
		cout << "Stack Underflow" << endl;

		cout << "Stack size : " << s.size() << endl;
	}
		// Empty the stack
	while (!s.isEmpty())
	{
		auto element = s.pop();
		if (element)
		{
			cout << "Popped element : " << *element << endl;
		}
		else
		{
			cout << "Stack Underflow" << endl;
		}
	}
	poppedElement = s.pop();
	if (poppedElement)
	{
		cout << "popped element" << *poppedElement << endl;
	}
	else
	{
		cout << "stack Underfolw" << endl;
	}










	return 0;
}
















