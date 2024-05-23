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
	// 문자열을 트라이에 삽입하는함수
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
	// 문자열이 트라이에 존재하는지 검색하는 함수

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

	// 트라이에서 문자열을 제거하는 함수

	void remove(string word)
	{
		removeHelper(root, word, 0);
	}

	// 트라이에 저장된 문자열을 출력하는 함수

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
	// 재귀적으로 문자열을 제거하는 도우미 함수

	bool removeHelper(TrieNode* node, string word, int depth)
	{
		if (depth == word.length())
		{
			if (!node->isEndOfWord)
			{
				return false;  // 해당 문자열이 트라이에 없음
			}
			return isLeafNode(node);
		}
		int index = word[depth] - 'a';
		if (node->children[index] == nullptr)
		{
			return false;  // 해장 문자열에는 트라이에 없음
		}
		// 재귀적으로 다음 노드로 이동하고, 해당 노드를 삭제할 수 있는지 확인
		bool shouldDeleteCurrentNode = removeHelper(node->children[index], word, depth + 1);
		// 삭제할 수 있고, 현재 노드가 단어의 끝이면 해당 노드를 삭제
		if (shouldDeleteCurrentNode && !node->isEndOfWord)
		{
			delete node->children[index];
			node->children[index] = nullptr;
			// 자식 노드가 없으면 현재 노드를 삭제
			return isLeafNode(node);
		}
		return false;
	}
	// 현재 노드가 단말 노드인지 확인하는 함수
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

	// 문자열 "apple" 제거
	trie.remove("apple");

	std::cout << "\nAfter removal:" << std::endl;
	std::cout << "Search for \"apple\": " << (trie.search("apple") ? "Found" : "Not found") << std::endl; // Not found
	std::cout << "Search for \"banana\": " << (trie.search("banana") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"app\": " << (trie.search("app") ? "Found" : "Not found") << std::endl; // Found
	std::cout << "Search for \"bat\": " << (trie.search("bat") ? "Found" : "Not found") << std::endl; // Found




	return 0;
}