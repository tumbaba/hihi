#include <iostream>
#include <string>
#include <vector>


using namespace std;

//선형 스캔 알고리즘

int LInearSearch(const vector<int>& arr, int target)
{
	for(size_t i = 0; i<arr.size(); i++)   //size_t : unsigned integer타입  배열의 인덱스를 나타낼 때, 메모리의 크기를 나타낼 때, 반복문에서 배열의 크기와 관련된변수로 사용
		if (arr[i] == target)
		{
			return i;    // 값이 존재하면 인덱스를 반환		
		}
	return -1;    // 값이 존재하지 않으면 -1반환
}

int main()
{
	vector<int> arr = { 3,5,2,4,6,7 };
	int target = 6;

	int result = LInearSearch(arr, target);

	if (result != -1)
	{
		cout << "값" << target << "이(가) 인덱스" << result << "에서 발견되었습니다" << endl;

	}
	else cout << "값" << target << "을(를) 배열에서 찾을 수 없습니다." << endl;
	

	

	
		

	
	



	return 0;
}