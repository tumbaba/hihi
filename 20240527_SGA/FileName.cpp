#include <iostream>
#include <string>
#include <map>

using namespace std;


// map < key, value>
map<string, int> myMap;



int main()
{
	map<int, int> mapInt = { {1,2},{2,10},{10,1000} };
	map<int, string> mapString = { {10,"hi"},{20,"hello"}};

	mapString[10] = "Hello World";

	string str = mapString[10];
	mapInt.insert(4, 5);
	// (key값)    요소가 삭제   
	mapInt.erase(1);

	cout << mapInt.size();









	return 0;
}