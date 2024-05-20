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

	// �迭 ũ�� ���� �Լ�
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
	// �⺻ ������
	ArrayDouble() : arr(nullptr), size(0), capacity(0) {}
	// ũ�⸦ �����ϴ� ������
	ArrayDouble(size_t initial_capacity) : size(0), capacity(initial_capacity)
	{
		arr = new double[capacity];
	}
	//�Ҹ���
	~ArrayDouble()
	{
		delete[] arr;
	}
	// �迭 ũ�� ��ȯ
	size_t getSize() const
	{
		return size;
	}
	// �迭 �뷮 ��ȯ
	size_t getCapacity() const
	{
		return capacity;
	}
	// �迭 ��� ���� (�б�/����)
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

	// �迭�� �� �߰� �Լ�
	void add(double value)
	{
		if (size == capacity)
		{
			resize(capacity == 0 ? 1 : capacity * 2);
		}
		arr[size++] = value;
	}

	// �迭 �ʱ�ȭ �Լ�
	void initialize(double value)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = value;
		}
	}// �迭 ��� �Լ�
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
	ArrayDouble arr(2);    // ���Ͱ� �ƴ� ������ ���ʹ� �����̱� ���� �׷��� ������ �迭�� ���

	arr.add(1.1);
	arr.add(2.2);
	arr.print();

	arr.add(3.3);   // ũ�� ������
	arr.print();

	arr.add(4.4);
	arr.print();

	cout << "Array size : " << arr.getSize() << endl;
	cout << "Array capacity : " << arr.getCapacity() << endl;


	

	return 0;
}




//resize(capacity == 0 ? 1 : capacity * 2);
// ���� ������(ternary operator)
// 'capacity == 0' ������ ���̸� �迭�� ���ο� ũ�⸦ 1�� �����Ѵ�.  
// 'capacity == 0' ������ �����̸� �迩���� ���ο� ũ�⸦ ���� �뷮�� �ι�� �����Ѵ�.  
//���� �����ڴ� condition ? expression_if_true : expression_if_false �������� ���Դϴ�.
//������ ���̸� expression_if_true��, �����̸� expression_if_false�� ��ȯ�մϴ�.