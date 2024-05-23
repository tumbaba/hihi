#include "stdafx.h"


const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;

	TrieNode()
	{
		isEndOfWord = false;
		for (int i = 0; i < ALPHABET_SIZE; ++i)
		{
			children[i] = nullptr;
		}
	}
};

class Trie
{
public:
	TrieNode* root;

	Trie() 
	{
		root = new TrieNode();
	}
	// ���ڿ��� Ʈ���̿� �����ϴ��Լ�
	void insert(string word)
	{
		TrieNode* curr = root;
		for (char c : word)
		{
			int index = c - 'a';
			if (curr->children[index] == nullptr)
			{
				curr->children[index] = new TrieNode();
			}
			curr = curr->children[index];
		}
		curr->isEndOfWord = true;
	}
	// ���ڿ��� Ʈ���̿� �����ϴ��� �˻��ϴ� �Լ�

	bool search(string word)
	{
		TrieNode* curr = root;
		for (char c : word)
		{
			int index = c - 'a';
			if (curr->children[index] == nullptr)
			{
				return false;
			}
			curr = curr->children[index];
		}
		return curr != nullptr && curr->isEndOfWord;
	}

	// Ʈ���̿��� ���ڿ��� �����ϴ� �Լ�

	void remove(string word)
	{
		removeHelper(root, word, 0);
	}

	// Ʈ���̿� ����� ���ڿ��� ����ϴ� �Լ�

	void printAllStrings(TrieNode* node, string prefix = " ")
	{
		if (node->isEndOfWord)
		{
			cout << prefix << endl;
		}
		for (int i = 0; i < ALPHABET_SIZE; ++i)
		{
			if (node->children[i] != nullptr)
			{
				printAllStrings(node->children[i], prefix + char('a' + i));
			}
		}
	}

	void printPrefixStrings(string prefix)
	{
		TrieNode* curr = root;
		for (char c : prefix)
		{
			int index = c - 'a';
			if (curr->children[index] == nullptr)
			{
				cout << "No string with prtfix \"" << prefix << "\"" << endl;
				return;
			}
			curr = curr->children[index];
		}
		printAllStrings(curr, prefix);
	}




private:
	// ��������� ���ڿ��� �����ϴ� ����� �Լ�

	bool removeHelper(TrieNode* node, string word, int depth)
	{
		if (depth == word.length())
		{
			if (!node->isEndOfWord)
			{
				return false;  // �ش� ���ڿ��� Ʈ���̿� ����
			}
			return isLeafNode(node);
		}
		int index = word[depth] - 'a';
		if (node->children[index] == nullptr)
		{
			return false;  // ���� ���ڿ����� Ʈ���̿� ����
		}
		// ��������� ���� ���� �̵��ϰ�, �ش� ��带 ������ �� �ִ��� Ȯ��
		bool shouldDeleteCurrentNode = removeHelper(node->children[index], word, depth + 1);
		// ������ �� �ְ�, ���� ��尡 �ܾ��� ���̸� �ش� ��带 ����
		if (shouldDeleteCurrentNode && !node->isEndOfWord)
		{
			delete node->children[index];
			node->children[index] = nullptr;
			// �ڽ� ��尡 ������ ���� ��带 ����
			return isLeafNode(node);
		}
		return false;
	}
	// ���� ��尡 �ܸ� ������� Ȯ���ϴ� �Լ�
	bool isLeafNode(TrieNode* node)
	{
		for (int i = 0; i < ALPHABET_SIZE; ++i)
		{
			if (node->children[i] != nullptr)
			{
				return false;
			}
		}
		return true;
	}


};





int main()
{
	Trie trie;
	trie.insert("apple");
	trie.insert("banana");
	trie.insert("app");
	trie.insert("bat");


	std::cout << "All strings in the trie:" << std::endl;
	trie.printAllStrings(trie.root);

	std::cout << "\nStrings with prefix \"app\":" << std::endl;
	trie.printPrefixStrings("app");


	std::cout << "Before removal:" << std::endl;
	std::cout << "Search for \"apple\": " << (trie.search("apple") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"banana\": " << (trie.search("banana") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"app\": " << (trie.search("app") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"bat\": " << (trie.search("bat") ? "Found" : "Not found") << std::endl; // Found

	// ���ڿ� "apple" ����
	trie.remove("apple");

	std::cout << "\nAfter removal:" << std::endl;
	std::cout << "Search for \"apple\": " << (trie.search("apple") ? "Found" : "Not found") << std::endl; // Not found
	std::cout << "Search for \"banana\": " << (trie.search("banana") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"app\": " << (trie.search("app") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"bat\": " << (trie.search("bat") ? "Found" : "Not found") << std::endl; // Found




	return 0;
}