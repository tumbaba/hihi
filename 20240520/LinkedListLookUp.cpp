#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


struct Node
{
	int data;  // ������
	Node* next;  // ���� ��带 ����Ű�� ������
};

class LinkedList
{
private:
	Node* head;
	
public:
	LinkedList() : head(nullptr) {}

	void insert(int newData)
	{
		Node* newNode = new Node;  // ���ο� ��� ����
		newNode->data = newData; //  ������ ����

		// ����Ʈ�� ����ִ°��
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next; // ������ ���� �̵�
			}
			current->next = newNode;   // ���ο� ��带 ������ ����� �������� ����
		}
	}
	void insertAtMiddle(int newData, int position)   // ���� ��� ��ġ�� ã�� ����� ���� ��ġ�� ��ġ�� �����Ѵ�.  ex ) position = 2 �� newData�� 3��ġ�� ����.
	{
		//���ο� ��� ����
		Node* newNode = new Node;
		newNode->data = newData;
		// position�� 0�� ���, ����Ʈ�� �� �տ� �����ϴ� �Ͱ� �����մϴ�.
		if (position == 0 || head == nullptr)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		// ���� ��带 ã�� ���� ������ �ʱ�ȭ
		Node* current = head;
		int currentPosition = 0;
		while (current != nullptr &&currentPosition < position - 1)
		{
			current = current->next;
			currentPosition++;
		}
		// ���� ��带 ã�� ���
		if (current != nullptr)
		{
			newNode->next = current->next;
			current->next = newNode;
		}
		else
		{
			cout << "position�� ����Ʈ�� ������ ������ϴ�." << endl;
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

		// ���Ҹ� ã�� ���
		if (current != nullptr)
		{
			// ù ���� ��带 �����ϴ� ���
			if (prev == nullptr)
			{
				head = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			
		}
		delete current; // ��� ����
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