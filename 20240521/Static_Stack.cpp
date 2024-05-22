#include "stdafx.h"
#define MAX 5   // 배열의 크기가 5로 고정됨

//정적자료구조

class Stack
{
private:
	int arr[MAX];
	int top;

public:
	Stack() { top = -1; }

	void push(int x)
	{
		if (top >= MAX - 1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{
			arr[++top] = x;
		}
	}
	int pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow" << endl;
			return -1;
		}
		else
		{
			return arr[top--];
		}
	}
	int peek()
	{
		if (top < 0)
		{
			cout << "Stack is Empty" << endl;
			return -1;
		}
		else
		{
			return arr[top];
		}
	}
	bool isEmpty()
	{
		return (top < 0);
	}
	int size()
	{
		return top + 1;
	}
};


int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << "Top element : " << s.peek() << endl;
	s.pop();
	cout << "Top element after pop : " << s.peek() << endl;
	cout << "Stack size : " << s.size() << endl;
	cout << "Is stack empty?" << (s.isEmpty() ? "Yes" : "No") << endl;
	cout << s.isEmpty();

	return 0;
}