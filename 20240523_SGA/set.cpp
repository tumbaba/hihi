#include "stdafx.h"

// iterator (นÝบน)






int main()
{

	vector<int> vec = { 1,2,3,4,5 }; //size 0
	typedef vector<int>::iterator  It_INT;
	//It_INT it =  vec.begin();  // 1
	//It_INT it =  vec.end();    // 2

	/*for (It_INT it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}*/

	for (auto it_start = vec.begin(); it_start != vec.end(); it_start++)
	{

		//int num = *it_start;
		//(*it_start)  *= 2;
		cout << *it_start << " ";
	}

	return 0;
}

