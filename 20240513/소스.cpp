#include "stdafx.h"

#include <vector>

template <typename T>
void maxInt(T t) {}

void maxInt(int x) {}
void maxInt(float x) {}  // 함수 오버라이딩

int main()
{
	//vector<int> myVector = { 1,2,3,1,2 };
	vector<int> myVector(5);  //인트형태의 배열만듬, 동적배열 // 사이즈 선언


	myVector[0] = 1;
	myVector[1] = 10;
	myVector[2] = 100;
	myVector[3] = 1000;
	myVector[4] = 10000;
	//myVector[5] = 100000;  // 할당 오버

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
	// 백터의 요소값을 변경할 때
	for (int i = 0; i < myVector.size(); i++)
	{
		myVector[i] = myVector[i] * 10;
		//int value = myVector[i];
		int value = myVector.at(i);    // at i번째있는 갑을 넣어준다. 배열에서 인덱스 값을 얻어오는것과 동일한 결과를 가져온다.
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