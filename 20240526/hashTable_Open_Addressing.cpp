#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTableOpenAddressing
{
private:
	vector<pair<string, int>> table;
	vector<bool> occupied;
	int size;

	int hashFunction(const string& key)
	{
		int hash = 0;
		for (char ch : key)
		{
			hash = (hash * 31 + ch) % size;
		}
		return hash;
	}

public:
	HashTableOpenAddressing(int size) : size(size)
	{
		table.resize(size);
		occupied.resize(size, false);
	}

	void insert(const string& key, int value)
	{
		int index = hashFunction(key);
		int original_index = index;
		while (occupied[index])
		{
			if (table[index].first == key)
			{
				table[index].second = value;
				return;
			}
			index = (index + 1) % size;
			if (index == original_index)
			{
				throw overflow_error("Hash table is full");
			}
			
		}
		table[index] = { key, value };
		occupied[index] = true;
	}

	int search(const string& key)
	{
		int index = hashFunction(key);
		int original_index = index;
		while (occupied[index])
		{
			if (table[index].first == key)
			{
				return table[index].second;
			}
			index = (index + 1) % size;
			if (index == original_index)
			{
				break;
			}
		}
		return -1; // 키를 찾지 못한 경우
	}

	void remove(const string& key)
	{
		int index = hashFunction(key);
		int original_index = index;
		while (occupied[index])
		{
			if (table[index].first == key)
			{
				occupied[index] = false;
				return;
			}
			index = (index + 1) % size;
			if (index == original_index)
			{
				break;
			}
		}
	}



};

int main()
{
	HashTableOpenAddressing hashTable(10);
	hashTable.insert("apple", 1);
	hashTable.insert("banana", 2);

	cout << "apple : " << hashTable.search("apple") << endl; // 출력  : 1
	hashTable.remove("apple");
	cout << "apple : " << hashTable.search("apple") << endl; // 출력  : -1



	return 0;
}