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
		int mid = low + (high - low) / 2;   // 인덱스 중간값

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

	// 정렬된 예제 배열과 목표 값
	vector<int> arr{ 10,20,30,40,50,60,70,80,90,100,110 };

	int target = 80;
	int result = BinarySearch(arr, target);

	if (result != -1)
	{
		cout << "값" << target << "이(가) 인덱스" << result << "에서 발견되었습니다" << endl;
	}
	else cout << "값" << target << "을(를) 배열에서 찾을 수 없습니다." << endl;



	return 0;
}