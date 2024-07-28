#include <iostream>
using namespace std;



int main()
{

	int a[9];

	for (int i = 0; i < 9; i++)
	{
		int b;
		cin >> b;
		a[i] = b;
	}
	int min =1;
	int max =a[0];

	for (int i = 0; i < 9; i++)
	{
		
		if (max < a[i])
		{
			max = a[i];
			min = i+1;
		}
	}

	cout << max << endl;
	cout << min ;

	return 0;
}