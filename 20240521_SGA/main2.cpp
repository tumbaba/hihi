#include "stdafx.h"


/*
list
���� : ���� ���� ����Ʈ ���� , c++ ǥ�� ���̺귯�� �����̳�
 ����� ���԰� ������ �������� ���� ������ ���� Ư¡�̴�.

  ���� ,  �ʱ�ȭ

  list
*/
// ���� �迭�� �ƴ϶� ���� ����Ʈ(Linked List)�Դϴ�. 
// ���� ����Ʈ�� ���� �޸� �Ҵ��� ����Ͽ� �����͸� �����ϸ�,
// �� ���� �����Ϳ� ���� ��带 ����Ű�� �����ͷ� �����˴ϴ�.

list<string> myStringList;
//list<int> myList;  // ������ 0
list<int> myList(5);  // �ʱ�ȭ ������ 5
list<int> myIntList = { 1,2,3,4,5,6 };   // �ʱ�ȭ ������ 6


// ����Ʈ ���� ����
// ����Ʈ�� ���� �Լ� �̿� 30�� ������  ���� ���� ����  (������)
// ¦���� �����ϰ� ����Ʈ�� Ȧ���� �����

list<int> practiceList;


int main()
{
	myList.push_back(7);
	myList.push_front(8);
	auto it = myList.begin();
	advance(it, 4);
	myList.insert(it, 40);

	/*for (auto it = myList.begin(); it != myList.end(); it++)
	{
		cout << *it << endl;
	}*/

	cout << endl;

	myList.pop_back();

	//myList.remove(0);
	/*auto it2 = myList.begin();
	advance(it2, 2);
	myList.erase(it2);
	for (auto it = myList.begin(); it != myList.end(); it++)
	{
		cout << *it << endl;
	}*/


	for (int i = 0; i < 30; i++)
	{

		int j = rand() % 100;
		practiceList.push_front(j);

	}

	for (auto it = practiceList.begin(); it != practiceList.end(); it++)
	{
		cout << *it << endl;
	}
	

	cout << "--------------Ȧ����-----------" << endl;
	for (int i = 0; i < 50; i++)
	{
		
		practiceList.remove(i*2);
	}

	for (auto it = practiceList.begin(); it != practiceList.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}

