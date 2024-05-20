#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


class ArrayDouble
{
private:
	double* arr;
	size_t size;
	size_t capacity;

	// 배열 크기 조정 함수
	void resize(size_t new_capacity)
	{
		double* new_arr = new double[new_capacity];
		for (size_t i = 0; i < size; i++)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		capacity = new_capacity;
	}

public:
	// 기본 생성자
	ArrayDouble() : arr(nullptr), size(0), capacity(0) {}
	// 크기를 지정하는 생성자
	ArrayDouble(size_t initial_capacity) : size(0), capacity(initial_capacity)
	{
		arr = new double[capacity];
	}
	//소멸자
	~ArrayDouble()
	{
		delete[] arr;
	}
	// 배열 크기 반환
	size_t getSize() const
	{
		return size;
	}
	// 배열 용량 반환
	size_t getCapacity() const
	{
		return capacity;
	}
	// 배열 요소 접근 (읽기/쓰기)
	double& operator[](size_t index)
	{
		if (index >= size) throw std::out_of_range("Index out of range");
		return arr[index];
	}
	const double& operator[](size_t index) const
	{
		if (index >= size) throw std::out_of_range("Index out of range");
		return arr[index];
	}

	// 배열에 값 추가 함수
	void add(double value)
	{
		if (size == capacity)
		{
			resize(capacity == 0 ? 1 : capacity * 2);
		}
		arr[size++] = value;
	}

	// 배열 초기화 함수
	void initialize(double value)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}// 배열 출력 함수
	void print() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};



int main()
{
	ArrayDouble arr(2);    // 백터가 아닌 이유는 백터는 동적이기 떄문 그래서 정적인 배열을 사용

	arr.add(1.1);
	arr.add(2.2);
	arr.print();

	arr.add(3.3);   // 크기 제조정
	arr.print();

	arr.add(4.4);
	arr.print();

	cout << "Array size : " << arr.getSize() << endl;
	cout << "Array capacity : " << arr.getCapacity() << endl;


	

	return 0;
}




//resize(capacity == 0 ? 1 : capacity * 2);
// 삼항 연산자(ternary operator)
// 'capacity == 0' 조건이 참이면 배열의 새로운 크기를 1로 설정한다.  
// 'capacity == 0' 조건이 거짓이면 배여르이 새로운 크기를 현재 용량의 두배로 설정한다.  
//삼항 연산자는 condition ? expression_if_true : expression_if_false 형식으로 쓰입니다.
//조건이 참이면 expression_if_true를, 거짓이면 expression_if_false를 반환합니다.