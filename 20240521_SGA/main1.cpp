#include "stdafx.h"


/*
 ���̹� ��Ģ�� ���ѻ���

1. �ĺ��ڶ� 
 ����, �Լ� ,Ŭ����, ���ӽ����̽�

 2. ���̹� ��Ģ
   1. ����Ҽ� �ִ� ����
     - ���ĺ�: �ҹ���, �빮��
	 -���� , ����
   2. ù���� ��Ģ
     - ���ĺ�, ���ٷ� �����ؾ� �Ѵ�.
	 - ���ڸ� ����� �� ����.

   3. ��ҹ��� ����
	 - int Value, value�� ���� �ٸ� ������ �νĵ�
   4. ���� ����
    -���� ������ ����
   5. ����� ����
    - c++ �����(Ű����) ����ϸ� �ȵ�
	��) int, class,  return ���

3. ���� = �ڵ��� ������, ��������
  1. ���� �� �Լ�
    - myValueAdd, calcullateSum    // camel case
	- my_value_add, calculate_sum  // snake case
	- Cmyclass, m_value, p_value   
  2. Ŭ����
   - �ܾ�� �빮�ڷ� ����ϴ� ��찡 ����
   ex) MyClass, EmptryData

  3.���ӽ����̽�
  - �ҹ��ڸ� �ۼ��� ���� �Ѵ�.
  - using namespace std;
  - namespace std{}
  4. ���
  - ���� �빮�ڷ� �ۼ�
  - #define PI 3,14, MAX_SIZE , DEFAULT_VALUSE

4. ���̹� ���� ����
   -�ǹ� �ִ� �̸� ��� : �̸��� ���� ��Ȱ�� �� �� �ֵ��� �̸��� ���´�.
   - ȥ�� ���ϱ� : ���� O(���� �빮��), 0, o, 1,l I
   - ���� ���� : �ʹ� ª�� ���� ����� �ǹ� ������ �̷Ʊ� ������ �����ؾ� �Ѵ�.
   
5. ���ӽ����̽� ���
   - �̸� �浹�� ���ϰ�, �ڵ带 ����ȭ �� �� �ִ�.


*/
/* 
�Լ���?
- Ư�� �۾��� �����ϴ� �ڵ� ���̴�.

1. �Լ��� ����
  - return [��] ; ��ȯ��, void : ��ȯ���� ���� �� ����
  - �Լ� �̸�
  - �Ű� ���� parameter, 0 ~ ���Ѿ���.
  - �Լ� ��ü : { } �Լ� ���� ���ָ� ��
  
-�Լ� ����
 ��)   int add(int a, int b);
     
 - �Լ� ����
 int add(int a, int b)
  {
	   int c = a+b;
	       return c;
		}
-�Լ� ���
  int result = add(10,10);


  // ��� �Լ�

  int factorial(int n)
  {
    if(n<= 1 ) return1;
	else 
	   return n*factorial(n-1);
  }




 
*/


void printMesssage()
{
	cout << "Hello ,  ����Ʈ �Լ��Դϴ�. " << endl;
}


int main()
{
	int �ȳ��ϼ��� = 10;
	

	cout << �ȳ��ϼ��� << endl;


	// ����Ʈ �Լ� ����

	void (*funcPtr)() = &printMesssage;

	funcPtr();




	return 0;
}