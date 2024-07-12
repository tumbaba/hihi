#include <iostream>
#include "Arr.h"


struct tMy
{

};


class CMy
{
	// 접근 제한 지정자
	// private, protected, public
private:
	int m_i;
	float m_f;

public:
	void SetInt(CMy* _this , int a)
	{
		_this->m_i = a;
		
;	}

	// 연산자 오버로딩
	const CMy& operator =(const CMy& _other)  //  CMy&
	{
		m_i = _other.m_i;
		m_f = _other.m_f;

		return *this;
	}


	// 초기화
	// 생성자
	// 이니셜라이저 (진정한 초기화)
	CMy() :m_i(100), m_f(3.4f) {}
	// 소멸자
	~CMy()
	{

	}
};



int main()
{
	// c++클래스 특징
	// 접근제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨
	
	// 생성자 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용함수
	// 헤당클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달된다.

	{

	
	// 레퍼헌스
	// 자료형 * 변수명;  포인터 변수 선언
	// *포인터변수;      포인터로 주소 역참조
	// &변수;;          변수의 주소값
	// 자료형& 변수명    레퍼런스 변수 선언
	// 
	//
	// c++에서 추가된 기능
	// 포인터와 유사
	// 원본을 참조한다.
	// 참조변수를 통해서 직접적으로 원본을 수정 할 수 있다.
	//

		int a = 10;

		int* const p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;

		const int* const p2 = &a;
		//p*2 = 100;

		const int& iRef2 = a;
		//iRef2 = 100;

	}

	return 0;
}