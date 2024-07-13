#include <iostream>

//#include "CList.h"

//using namespace std;
#include "CList.h"
#include "CArr.h"
#include <vector>
#include <list>

using std::cout;
using std::wcout;
using std::endl;
using std::cin;
using std::vector;
using std::list;


class Test
{
public:
	int  m_i;

public:
	Test& operator =(const Test& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	// 복사 생성자 (자동으로 만들어줌) 이런거 한개라도 만들면 컴파일러는 해당 기본생성자를 만들어주지 않는다.
	Test(const Test& _other) : m_i(_other.m_i) {}
	Test() : m_i(0) {}
};


void MyEndL()
{
	wprintf(L"\n");
}

class CTest
{


public:

	// 객체 없이 호출 가능
	static void memberFunc()
	{

	}
};

namespace MYSPACE
{
	int g_int;
}

class CMyOstream
{
public:
	CMyOstream& operator <<(int data)
	{
		printf("%d", data);
		return *this;
	}
	CMyOstream& operator <<(const wchar_t* data)
	{
		wprintf(L"%s", data);
		return *this;
	}
	CMyOstream& operator <<(void(*pFunc)(void))
	{
		pFunc();
		return *this;
	}

	CMyOstream& operator >>(int& data)
	{
		scanf_s("%d", &data);
		return *this;
	}

};

CMyOstream mycout;



int main()
{



	/*CList<int> list;


	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}*/
	CTest::memberFunc();
	MYSPACE::g_int = 0;

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");


	/*wcout << L"안녕" << endl;
	mycout << 10 << 20 << 30;*/
	//mycout << L"안녕"<<MyEndL;


	int a = 0;
	


	/*vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vector<int>::iterator iiter = vecInt.begin();

	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i);
	}*/

	// *iiter; 동적 할당한 메모리가 부족할때 새로운 공간을 할당하여 공간을 늘리기 때문에
	// 공간을 늘리기전 메모리의 주소는 비어있게 되서 iiter의 값을 가져올 수 없다.


	/*vecInt[0] = 100;
	vecInt.at(0);
	vecInt.data();
	vecInt.size();
	vecInt.capacity();

	for (size_t i = 0; i< vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}
	vector<int>::iterator viter = vecInt.begin();*/

	/*list<int> listInt;

	listInt.push_back(10);
	listInt.emplace_front(100);*/


	// iterator(inner class)
	//list<int>::iterator iter = listInt.begin();
	//int iData = *iter;   // *iter포인터 아님, 연산자 오퍼레이터임
	//++iter;
	//iData = *iter;
	
	//for (iter = listInt.begin(); iter != listInt.end(); ++iter)  //  .end() 마지막보다 더마지막
	//{
	//	cout << *iter << endl;
	//}

	// 연산자들을 만들어야한다
	// 
	// *myiter;
	// ++(전위, 후위), --,==,!=

	CArr<int> myVector;

	myVector.PushBack(100);
	myVector.PushBack(200);
	myVector.PushBack(300);

	CArr<int>::iterator myiter = myVector.begin();
	myiter = myVector.erase(myiter);

	for (myiter = myVector.begin(); myiter != myVector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}
	


	/*for (; myiter != myVector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}*/
	Test t1;
	t1.m_i = 100;

	/*Test t2;
	t2 = t1;*/

	Test t2(t1);

	Test t3 = t1;  // Test t3(t1);   // 중요 복사생성자가 만들어진다. 면접에 나옴
	





	//vector::erase
	vector<int>  vecInt;

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);
	vecInt.push_back(500);

	vector<int>::iterator veciter = vecInt.begin();
	veciter = vecInt.erase(veciter);
	int i = *veciter;
	/*veciter = vecInt.begin();
	int i = *veciter;*/

	vecInt.clear();

	for (int i = 0; i < 11; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 짝수만 제거
	veciter = vecInt.begin();
	for (; veciter != vecInt.end(); )
	{
		if (*veciter % 2 == 0)
		{
			veciter = vecInt.erase(veciter);
		}
		else
		{
			++veciter;   // 면접에 나올수 있음

		}
	}
	for (int i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}



	// list itorator

	CList<int> mylist;

	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	CList<int>::iterator listiter = mylist.begin();
	int ii = *listiter;

	




	return 0;
}