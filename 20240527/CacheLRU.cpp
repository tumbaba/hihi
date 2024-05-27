#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


// 이중 연결 리스트의 노드 정의
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

	// 새 노드를 맨앞에 추가
	void addNode(Node* node)
	{
		node -> next = head->next;
		node->prev = head;
		head->next->prev = node;
		head->next = node;
	}

	// 기존 노드를 연결 해제
	void removeNode(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}

	//해당 노드를 맨 앞으로 이동
	void moveToHead(Node* node)
	{
		removeNode(node);
		addNode(node);
	}


public:
	LRUCache(int capacity) : capacity(capacity)
	{
		head = new Node(-1, -1); // 가상의 헤드 노드 생성
		tail = new Node(-1, -1); // 가상의 테일 노드 생성
		head->next = tail;
		tail->prev = head;
	}

	int get(int key)
	{
		if (cache.find(key) != cache.end())
		{
			Node* node = cache[key];
			moveToHead(node); // 가장 최근에 사용된 노드로 이동
			return node->value;
		}
	}

	int put(int key, int value)
	{
		if (cache.find(key) != cache.end())
		{	// 이미 캐시에 있는 경우 해당 값 업데이트하고 가장 최근으로 이동
			Node* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
		else
		{
			//캐시에 없는 경우 새로운 노드 추가
			Node* newNode = new Node(key, value);
			cache[key] = newNode;
			addNode(newNode);
			// 캐시 용량 초과 시 , 가장 오래된 노드 제거
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
		// 메모리 누수 방지를 위해 동적으로 할당된 노드를 해제
		delete head;
		delete tail;
		for (auto it = cache.begin(); it != cache.end(); ++it)
		{
			delete it->second;
		}
	}
};

// 사용 예시
int main()
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl; // 출력 :  1
	cache.put(3, 3);
	cout << cache.get(2) << endl;  // 출력 -1 
	cache.put(4, 4);
	cout << cache.get(1) << endl;  // -1
	cout << cache.get(3) << endl;  // 3
	cout << cache.get(4) << endl;  // 4
 

	return 0;
}



























