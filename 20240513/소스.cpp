#include "stdafx.h"

#include <vector>

template <typename T>
void maxInt(T t) {}

void maxInt(int x) {}
void maxInt(float x) {}  // �Լ� �������̵�

int main()
{
	//vector<int> myVector = { 1,2,3,1,2 };
	vector<int> myVector(5);  //��Ʈ������ �迭����, �����迭 // ������ ����


	myVector[0] = 1;
	myVector[1] = 10;
	myVector[2] = 100;
	myVector[3] = 1000;
	myVector[4] = 10000;
	//myVector[5] = 100000;  // �Ҵ� ����

	int vectorSize = myVector.size();

	myVector.push_back(50);

	for (int i = 0; i < myVector.size(); i++)
	{
		cout << "myVector[" << i << "]=" << myVector[i] << endl;
	}
	cout << "===================" << endl;

	myVector.pop_back();
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << "myVector[" << i << "]=" << myVector[i] << endl;
	}
	cout << "===================" << endl;
	// ������ ��Ұ��� ������ ��
	for (int i = 0; i < myVector.size(); i++)
	{
		myVector[i] = myVector[i] * 10;
		//int value = myVector[i];
		int value = myVector.at(i);    // at i��°�ִ� ���� �־��ش�. �迭���� �ε��� ���� �����°Ͱ� ������ ����� �����´�.
		cout << "myVector[" << i << "]=" << value << endl;
	}
	cout << "===================" << endl;
	int i = 0;
	for (int num : myVector)
	{
		
		cout << "myVector[" << i << "]=" << num << endl;
		i = i + 1;
		//cout << "myVector[" << i << "]=" << num << endl;
	}
	
	maxInt(10);
	maxInt(10.56f);  
	maxInt(10);



	return 0;
}