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





// inline �� �J���Լ����ַ� ���ȴ�. �Լ��� �ش� ��ġ�� ����ȴ�.
// Ʈ��
// �׷��� 
// self balansed
//AVL , red-black

#define MAN		1   //  #define �� ��ó���⿡�� ����
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
	// ����Ž��
	// 1. ���ĵǾ��ִ� �����Ϳ� ���밡��


	// ����Ž��Ʈ��
	// 1. ����Ž���� ��� �� �� �ְ� ��ȵ� ����Ʈ��
	// 2. ������ �Է� �� log(N)ȿ��
	// 3. Ž��ȿ���� O(lig N)
	//
	// 4. Ʈ���� ����� �뷯���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�/
	//  - �ڰ����� ��� �ʿ� (AVL , Red/Black)



	set<int> setInt;

	setInt.insert(100); 
	setInt.insert(10);
	setInt.insert(200);

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 19, WOMAN);

	mapData.insert( make_pair(L"ȫ�浿", info)  );
	mapData.insert( make_pair(L"������", info2) );

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"ȫ�浿");

	// ã�� ���ߴ�
	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ã�� �� ����." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName<< endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		wcout << L"���� : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����" << endl;
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