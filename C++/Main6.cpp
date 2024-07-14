#include <iostream>
#include <locale>
#include <map>  //red - black 
#include <set>  //red - black 
#include <string>

#include "CBST.h"

using std::wcout;
using std::endl;


using std::map;
using std::make_pair;
using std::set;

using std::wstring;



enum  class MY_TYPE   
{
	TYPE_1, //0
	TYPE_2, //1       
	TYPE_3, //2
	TYPE_4, //3
	TYPE_5 = 100, 
	TYPE_6, // 101
};

enum class OTHERE
{
	TYPE_1,
};





// inline 은 짫은함수위주로 사용된다. 함수가 해당 위치에 복사된다.
// 트리
// 그래프 
// self balansed
//AVL , red-black

#define MAN		1   //  #define 은 전처리기에서 시작
#define WOMAN	2

struct tStdInfo
{
	int a = (int)MY_TYPE::TYPE_1;

	OTHERE::TYPE_1;


	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{
	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender  )
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}

};






int main()
{
	setlocale(LC_ALL, "");
	// 이진탐색
	// 1. 정렬되어있는 데이터에 적용가능


	// 이진탐색트리
	// 1. 이진탐색을 사용 할 수 있게 고안된 이진트리
	// 2. 데이터 입력 시 log(N)효율
	// 3. 탐색효율은 O(lig N)
	//
	// 4. 트리의 모양이 밸러스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다/
	//  - 자가균형 기능 필요 (AVL , Red/Black)



	set<int> setInt;

	setInt.insert(100); 
	setInt.insert(10);
	setInt.insert(200);

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 19, WOMAN);

	mapData.insert( make_pair(L"홍길동", info)  );
	mapData.insert( make_pair(L"이지혜", info2) );

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"홍길동");

	// 찾지 못했다
	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName<< endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}



	(*mapiter).first;
	(*mapiter).second;

	mapiter->first;
	mapiter->second;


	map<wstring, tStdInfo> mpaStdInfo;

	wstring str;
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	CBST<int, int> bstint;

	tPair<int, int> pair;

	pair.first = 100;
	bstint.insert(pair);

	pair.first = 150;
	bstint.insert(pair);

	pair.first = 50;
	bstint.insert(pair);

	return 0;
}