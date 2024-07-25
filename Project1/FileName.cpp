#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


/*

*/


void temp(string* a, string* b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}



int main()
{

	string A;
	cin >> A;
	string B = {};
	
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] < 96)
		{
			B.push_back(A[i] - 65);
		}
		else
		{
			B.push_back(A[i] - 97);
		}
	}

	for (int i = 0; i < B.length(); i++)
	{
		cout << (int)B[i];
	}

	return 0;
}