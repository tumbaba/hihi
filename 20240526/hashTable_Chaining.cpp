#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;


class HashTableChaining
{
private:
	vector < list < pair<string, int>>> table;
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
	HashTableChaining(int size) : size(size)
	{
		table.resize(size);
	}

	void insert(const string& key, int value)
	{
		int index = hashFunction(key);
		for (auto& kv : table[index])
		{
			if (kv.first == key)
			{
				kv.second = value;
				return;
			}
		}
		table[index].emplace_back(key, value);
	}

	int search(const string& key)
	{
		int index = hashFunction(key);
		for (const auto& kv : table[index])
		{
			if (kv.first == key)
			{
				return kv.second;
			}
		}
		return -1;  // 키를 찾지 못한 경우
	}

	void remove(const string& key)
	{
		int index = hashFunction(key);
		table[index].remove_if([&key](const pair<string, int>& kv)
			{
				return kv.first == key;
			});
	}
};


int main()
{
	HashTableChaining hashTable(10);
	hashTable.insert("apple", 1);
	hashTable.insert("banana", 2);

	cout << "apple : " << hashTable.search("apple") << endl; // 출력 : 1
	hashTable.remove("apple");
	cout << "apple : " << hashTable.search("apple") << endl; // 출력 : -1




	return 0;
}