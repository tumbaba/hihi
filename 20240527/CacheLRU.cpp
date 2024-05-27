#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


// ���� ���� ����Ʈ�� ��� ����
struct Node
{
	int key;
	int value;
	Node* prev;
	Node* next;

	Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};


class LRUCache
{
private:
	int capacity;
	unordered_map<int, Node*> cache;
	Node* head;
	Node* tail;

	// �� ��带 �Ǿտ� �߰�
	void addNode(Node* node)
	{
		node -> next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
	}

	// ���� ��带 ���� ����
	void removeNode(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	//�ش� ��带 �� ������ �̵�
	void moveToHead(Node* node)
	{
		removeNode(node);
		addNode(node);
	}


public:
	LRUCache(int capacity) : capacity(capacity)
	{
		head = new Node(-1, -1); // ������ ��� ��� ����
		tail = new Node(-1, -1); // ������ ���� ��� ����
		head->next = tail;
		tail->prev = head;
	}

	int get(int key)
	{
		if (cache.find(key) != cache.end())
		{
			Node* node = cache[key];
			moveToHead(node); // ���� �ֱٿ� ���� ���� �̵�
			return node->value;
		}
	}

	int put(int key, int value)
	{
		if (cache.find(key) != cache.end())
		{	// �̹� ĳ�ÿ� �ִ� ��� �ش� �� ������Ʈ�ϰ� ���� �ֱ����� �̵�
			Node* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
		else
		{
			//ĳ�ÿ� ���� ��� ���ο� ��� �߰�
			Node* newNode = new Node(key, value);
			cache[key] = newNode;
			addNode(newNode);
			// ĳ�� �뷮 �ʰ� �� , ���� ������ ��� ����
			if (cache.size() > capacity)
			{
				Node* oldest = tail->prev;
				removeNode(oldest);
				cache.erase(oldest->key);
				delete oldest;
			}
		}
	}

	~LRUCache()
	{
		// �޸� ���� ������ ���� �������� �Ҵ�� ��带 ����
		delete head;
		delete tail;
		for (auto it = cache.begin(); it != cache.end(); ++it)
		{
			delete it->second;
		}
	}
};

// ��� ����
int main()
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl; // ��� :  1
	cache.put(3, 3);
	cout << cache.get(2) << endl;  // ��� -1 
	cache.put(4, 4);
	cout << cache.get(1) << endl;  // -1
	cout << cache.get(3) << endl;  // 3
	cout << cache.get(4) << endl;  // 4
 

	return 0;
}



























