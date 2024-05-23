#include "stdafx.h"

// 1. a~z,A~Z 배열을 만듦
// 2. 램덤하게 문자들을 선택해서 최대 15글자로 문자열
// 3. 분자열을 2개 만듦
// 4. 문자열 2개를 

list<string> SList1;
list<string> SList2;
set<string> copyList;

std::string generateRandomString(int length) {
    std::random_device rd; // 무작위 시드 생성기
    std::mt19937 gen(rd()); // 메르센 트위스터 엔진

    // 생성할 문자열의 문자 범위
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // 문자열을 저장할 변수
    std::string randomString;

    // 지정된 길이만큼 반복하면서 무작위 문자를 선택하여 문자열에 추가
    for (int i = 0; i < length; ++i) {
        // 문자 범위에서 무작위로 문자 선택
        std::uniform_int_distribution<> distr(0, characters.size() - 1);
        randomString += characters[distr(gen)];
    }

    return randomString;
}
int main()
{
	srand(time(NULL));

	
	
    for (int i = 0; i < 30; i++)
    {
        SList1.push_back(generateRandomString(1));
    }

    for (int i = 0; i < 30; i++)
    {
        SList2.push_back(generateRandomString(1));
    }
    cout << "---------1번 리스트 ----------" << endl;
    for (auto list1 = SList1.begin(); list1 != SList1.end(); list1++)
    {
        cout << *list1 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "---------2번 리스트 ----------" << endl;
    for (auto list2 = SList2.begin(); list2 != SList2.end(); list2++)
    {
        cout << *list2 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
	
    for (auto list1 = SList1.begin(); list1 != SList1.end(); list1++)
    {
        for (auto list2 = SList2.begin(); list2 != SList2.end(); list2++)
        {
            if ( *list1 == *list2)  //list1 != list2&&
            {
                copyList.insert(*list1);

            }
        }
    }


    for (auto list : copyList)
    {
        SList1.remove(list);
    }

    for (auto list : copyList)
    {
        SList2.remove(list);
    }
    cout << "---------1번 리스트  중복 값 제거----------" << endl;
    for (auto list1 = SList1.begin(); list1 != SList1.end(); list1++)
    {
        cout << *list1 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "---------2번 리스트  중복 값 제거----------" << endl;
    for (auto list2 = SList2.begin(); list2 != SList2.end(); list2++)
    {
        cout << *list2 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "--------- 중복 값 ----------" << endl;
    for (auto copy = copyList.begin(); copy != copyList.end(); copy++)
    {
        cout << *copy << " ";
    }
    cout << endl;


	return 0;
}