#include <iostream>
#include <string>
#include <vector>


using namespace std;

//���� ��ĵ �˰���

int LInearSearch(const vector<int>& arr, int target)
{
	for(size_t i = 0; i<arr.size(); i++)   //size_t : unsigned integerŸ��  �迭�� �ε����� ��Ÿ�� ��, �޸��� ũ�⸦ ��Ÿ�� ��, �ݺ������� �迭�� ũ��� ���õȺ����� ���
		if (arr[i] == target)
		{
			return i;    // ���� �����ϸ� �ε����� ��ȯ		
		}
	return -1;    // ���� �������� ������ -1��ȯ
}

int main()
{
	vector<int> arr = { 3,5,2,4,6,7 };
	int target = 6;

	int result = LInearSearch(arr, target);

	if (result != -1)
	{
		cout << "��" << target << "��(��) �ε���" << result << "���� �߰ߵǾ����ϴ�" << endl;

	}
	else cout << "��" << target << "��(��) �迭���� ã�� �� �����ϴ�." << endl;
	

	

	
		

	
	



	return 0;
}