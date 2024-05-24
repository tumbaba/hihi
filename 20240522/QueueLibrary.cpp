#include "stdafx.h"
#include <Queue>

queue<int>  q;


int main()
{
	for (int i = 0; i < 10; i++)
	{
		q.push((i+1) * 10);
	}

	cout << "front : " << q.front() << endl;
	cout << "back : " << q.back() << endl;

	q.pop();
	q.pop();
	q.pop();

	cout << "front : " << q.front() << endl;
	cout << "back : " << q.back() << endl;

	cout << (q.empty() ? "yes" : "no") << endl;


	cout << "size : " << q.size() << endl;

	return 0;
}