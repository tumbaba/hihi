#include <iostream>

using namespace std;

struct Node
{
	int Data;

	Node* Next;
};

Node* Create(int data)
{
	Node* node = new Node();

	node->Data = data;
	node->Next = NULL;

	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

void Push(Node** head, Node* node)
{
	if ((*head) == NULL)
	{
		*head = new Node();
	}
	else
	{
		Node* tail = (*head);

		while (tail->Next != NULL)
			tail = tail->Next;

		tail->Next = node;
	}
}

Node* GetNode(Node* head, int location)
{
	Node* current = head;

	while (current != NULL && --location >= 0)
		current = current->Next;

	return current;
}

int GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->Next;

		count++;
	}

	return count;
}

int main()
{
	Node* list = NULL;
	for (int i = 0; i < 5; i++)
	{
		Node* node = Create(i);
		Push(&list, node);
	}

	int count = GetNodeCount(list);
	for (int i = 0; i < count; i++)
	{
		Node* currnet = GetNode(list, i);

		cout << "List" << i << " : " << currnet->Data << endl;
	}
	cout << endl;

	return 0;
}






