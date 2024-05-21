#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


struct Node
{
	int data;  // 데이터
	Node* next;  // 다음 노드를 가리키는 포인터
};

class LinkedList
{
private:
	Node* head;
	
public:
	LinkedList() : head(nullptr) {}

	void insert(int newData)
	{
		Node* newNode = new Node;  // 새로운 노드 생성
		newNode->data = newData; //  데이터 설정

		// 리스트가 비어있는경우
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next; // 마지막 노드로 이동
			}
			current->next = newNode;   // 새로운 노드를 마지막 노드의 다음으로 연결
		}
	}
	void insertAtMiddle(int newData, int position)   // 이전 노드 위치를 찾고 노드의 다음 위치에 위치를 자정한다.  ex ) position = 2 면 newData는 3위치에 들어간다.
	{
		//새로운 노드 생성
		Node* newNode = new Node;
		newNode->data = newData;
		// position이 0인 경우, 리스트의 맨 앞에 삽입하는 것과 동일합니다.
		if (position == 0 || head == nullptr)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		// 이전 노드를 찾기 위한 변수들 초기화
		Node* current = head;
		int currentPosition = 0;
		while (current != nullptr &&currentPosition < position - 1)
		{
			current = current->next;
			currentPosition++;
		}
		// 이전 노드를 찾은 경우
		if (current != nullptr)
		{
			newNode->next = current->next;
			current->next = newNode;
		}
		else
		{
			cout << "position이 리스트의 범위를 벗어났습니다." << endl;
		}
	}


	void remove(int targetData)
	{
		Node* current = head;
		Node* prev = nullptr;

		while (current != nullptr && current->data != targetData)
		{
			prev = current;
			current = current->next;
		}

		// 원소를 찾은 경우
		if (current != nullptr)
		{
			// 첫 번쨰 노드를 삭제하는 경우
			if (prev == nullptr)
			{
				head = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			
		}
		delete current; // 노드 삭제
	}

	bool search(int searchData)
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data == searchData)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}
};



int main()
{
	



	return 0;
}