#include <iostream>
#include <string>
#include <vector>

using namespace std;


// �������� �Լ��� �ۼ��ϴ� ��� c++���ø�(Template)
// ���� => �͸��Լ��� �����ϰ� �����ϴµ� ���ȴ� �Լ��� ���α׷��� ����
// �����ϰ� ǥ���ϰ� �ڵ带 ��ȣȭ�Ѵ�

// ������ ������ ���ϴ� ���� �Լ� ����
//[&], [=] ĸó ǥ����
//[&] �ܺκ����� �����Լ� ������ ������ ĸó�Ѵ�.
//��: [=] �� ��� �ܺ� ������ ����� ĸó, [&]�� ��� �ܺ� ������ ������ ĸó/
//Ư�� ������ ĸó�� ���� �ֽ��ϴ� : [x, &y] �� x�� �����, y�� ������ ĸó//

//[capture](parameters) -> return_type {
//	// function body
//	};






template <typename T>
T Add(T a,T b)
{
	return a + b;
}
template <typename T2>
class Point
{
private:
	T2 xpos, ypos;

public:
	Point(T2 x, T2 y)
		: xpos(x), ypos(y) {}
	void ShowData()
	{
		cout << xpos << ", " << ypos << endl;
	}
};


template <class T1 , class T2>
void ShowData(double num)
{
	cout << (T1)num << ", "<<(T2)num << endl;
}

template <typename T>
class BoundCheckArray
{
private :
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr);
public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	int GetArrLen() const;
	~BoundCheckArray();
};





int main()
{
	Point<int>  pos(1,2);
	pos.ShowData();
	
	cout << Add<int>(1, 3) << endl;

	Point<unsigned> pos1(-1, 8);
	pos1.ShowData();


	ShowData<char, int>(65);




	int c = 5;
	auto add = [c](int x, int y)mutable -> int {
		c++;   //6
		x += c;
		 return x + y;
	};


	int result = add(3, 10);
	cout << c << endl;
	cout << result << endl;




	return 0;
}












template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
	
}


template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}
