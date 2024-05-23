#include "stdafx.h"

// 1. a~z,A~Z �迭�� ����
// 2. �����ϰ� ���ڵ��� �����ؼ� �ִ� 15���ڷ� ���ڿ�
// 3. ���ڿ��� 2�� ����
// 4. ���ڿ� 2���� 

list<string> SList1;
list<string> SList2;
set<string> copyList;

std::string generateRandomString(int length) {
    std::random_device rd; // ������ �õ� ������
    std::mt19937 gen(rd()); // �޸��� Ʈ������ ����

    // ������ ���ڿ��� ���� ����
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // ���ڿ��� ������ ����
    std::string randomString;

    // ������ ���̸�ŭ �ݺ��ϸ鼭 ������ ���ڸ� �����Ͽ� ���ڿ��� �߰�
    for (int i = 0; i < length; ++i) {
        // ���� �������� �������� ���� ����
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
    cout << "---------1�� ����Ʈ ----------" << endl;
    for (auto list1 = SList1.begin(); list1 != SList1.end(); list1++)
    {
        cout << *list1 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "---------2�� ����Ʈ ----------" << endl;
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
    cout << "---------1�� ����Ʈ  �ߺ� �� ����----------" << endl;
    for (auto list1 = SList1.begin(); list1 != SList1.end(); list1++)
    {
        cout << *list1 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "---------2�� ����Ʈ  �ߺ� �� ����----------" << endl;
    for (auto list2 = SList2.begin(); list2 != SList2.end(); list2++)
    {
        cout << *list2 << " ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "--------- �ߺ� �� ----------" << endl;
    for (auto copy = copyList.begin(); copy != copyList.end(); copy++)
    {
        cout << *copy << " ";
    }
    cout << endl;


	return 0;
}