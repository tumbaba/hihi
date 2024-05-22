#include "stdafx.h"
#include <stack>
#include <vector>


// stack 라이브러리 멤버 함수 활용
int main()
{
	vector<int> ji;
	
	stack<int> hi;

	for (int i = 0; i < 10; i++)
	{
		hi.push(i);
	}
	cout << hi.size() << endl;
	cout << hi.top() << endl;
	for (int i = 0 ; i < 5; i++)
	{
		hi.pop();
	}
	cout << hi.size() << endl;

	stack<int>hihi;
	for (int i = 0; i < 10; i++)
	{
		hihi.push(i);
	}

	hi.swap(hihi);
	cout << hi.size() << endl;

	//emplace

	return 0;
}