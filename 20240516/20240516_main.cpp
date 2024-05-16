#include "stdafx.h"



//네임스페이스, 변수 
//네임스페이스란? 코드에서 이름이 충돌하는것을 방지하기 위해 사용

//선언부
//namespace 이름{
// 
//  네임스페이스 영역설정
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