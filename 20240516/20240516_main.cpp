#include "stdafx.h"



//���ӽ����̽�, ���� 
//���ӽ����̽���? �ڵ忡�� �̸��� �浹�ϴ°��� �����ϱ� ���� ���

//�����
//namespace �̸�{
// 
//  ���ӽ����̽� ��������
//}

namespace MyNameSpace
{
	int value = 4200;
	int ad(int a, int b)
	{
		return a + b;
	}
}


int main()
{
	int value = 42;
	
	

	cout << MyNameSpace::value << endl;

	return 0;
}