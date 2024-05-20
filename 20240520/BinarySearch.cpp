#include <iostream>
#include <string>
#include <vector>


using namespace std;









int BinarySearch(vector<int>& arr, int target)
{
	int low = 0;
	int high = arr.size() - 1;

	while (low<=high)
	{
		int mid = low + (high - low) / 2;   // �ε��� �߰���

		if (arr[mid] == target)
		{
			return mid;   
		}
		else if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}
		
	}
	return -1;
}





int main()
{

	// ���ĵ� ���� �迭�� ��ǥ ��
	vector<int> arr{ 10,20,30,40,50,60,70,80,90,100,110 };

	int target = 80;
	int result = BinarySearch(arr, target);

	if (result != -1)
	{
		cout << "��" << target << "��(��) �ε���" << result << "���� �߰ߵǾ����ϴ�" << endl;
	}
	else cout << "��" << target << "��(��) �迭���� ã�� �� �����ϴ�." << endl;



	return 0;
}