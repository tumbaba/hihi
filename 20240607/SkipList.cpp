#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;




 /*
    -- O(log n) : �˰����� �ð� ���⵵�� ��Ÿ���� ǥ��� �� �ϳ�
 skip list�� ��������� O(log n)�� �ð� ���⵵�� ���� �˻�, ����, ������ �����ϴ� Ȯ������ �ڷᱸ��
 ���� Ʈ���� ������ ȿ������ �����鼭�� ������ �����ϰ� ������ �����ϴ� Ư¡�� ������ �ִ�.

 ��ŵ ����Ʈ�� �� ��尡 ���� ���� ��ũ�� ���� �� �ִµ�, �� ��ũ���� 'skip' ��Ȱ�� �մϴ�
 �̷��� ��ũ���� ����(level)�̶�� �Ҹ���, �� ���� �پ��� ������ ��ũ�� ���� �� �ֽ��ϴ�.
 ���� ������ ��ũ�� �Ʒ��� ������ ������ �̵���  �� �ְ� �����ִ� ��Ȱ�� �մϴ�.

 ��ŵ ����Ʈ�� ������ Ȯ�������� �����Ǵµ�, ���� �����ϼ��� �ش� ���� �� ���� �ǳ� �ۼ� �ִ�.
 �̸� ���� �˻� ������ ��� �ð� ���⵵�� ���� �� �ִ�.

 ��ŵ����Ʈ�� �ܼ��� ���� ����Ʈ�� ������� �ϸ�, �� ���� Ű���� ������ �ֽ��ϴ�. ���� Ű���� ��������
 ������������ ���ĵǾ� �ֽ��ϴ�. ��ŵ����Ʈ�� Ư�� ��带 ã�� ������ �̷��� ��ũ�� ���� ������ �̵��ϸ鼭
 ã�����ϴ� Ű ���� ã�ư��� �����Դϴ�.

 */


 //memset??
 // csiring���� 
 // �޸� ����� Ư���� ������ �����ϴµ� ���






// ��� ���� 
struct Node
{
	int value;       // ��尡 �����ϴ� ��
	Node** forward;  // ���� ������ ��忡 ���� ������ �迭


	// ������
	Node(int level, int value)
	{
		this->value = value;
		forward = new Node * [level + 1];  // forward ������ �迭 ���� �Ҵ�
		memset(forward, 0, sizeof(Node*) * (level + 1));  // �ʱ�ȭ
	}

	~Node() 
	{
		delete[] forward;
	}
};

// ��ŵ ����Ʈ Ŭ���� ����
class SkipList
{
private:
	int MAX_LEVEL;   // �ִ� ����
	float P;         // Ȯ��
	int level;       // ���� ����
	Node* header;    // ��� ���

	// ���� ���� ���� �Լ�
	int randomLevel()
	{
		int lvl = 0;
		// Ȯ�� P�� ���� ������ �����ϰ� ����
		while ((rand() & 100) < (P * 100) && lvl < MAX_LEVEL)
		{
			lvl++;
		}
		return lvl;
	}
public:
	// ������ : �ִ� ������ Ȯ���� �޾Ƽ� �ʱ�ȭ
	SkipList(int maxLevel, float p) : MAX_LEVEL(maxLevel), P(p)
	{
		level = 0;
		header = new Node(MAX_LEVEL, -1); // -1�� ��� ����� ��
	}
	~SkipList()
	{
		Node* current = header->forward[0];
		while (current != nullptr)
		{
			Node* next = current->forward[0];
			delete current;
			current = next;
		}
		delete header;
	}

	// ���� �Լ�
	void insert(int value)
	{
		Node* current = header;
		Node** update = new Node*[MAX_LEVEL + 1];
		memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));

		// �� �������� ���� ��带 ������Ʈ�� ������ ã��
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] != nullptr && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
			update[i] = current;
		}

		//���� ����� ���� ��尡 nullptr�̰ų� �h�� ����� ���� �ٸ� ��쿡�� ����
		current = current->forward[0];
		if (current == nullptr || current->value != value)
		{	// ������ ���� ����
			int rlevel = randomLevel();
			// ���� ������ ���� �������� ũ�� ������Ʈ �迭 ����
			if (rlevel > level)
			{
				for (int i = level + 1; i <= rlevel; i++)
				{
					update[i] = header;
				}
				level = rlevel;
			}
			// �� ��� ����
			Node* n = new Node(rlevel, value);
			// ������Ʈ �� �迭�� ����Ͽ� �� ��带 ��ũ
			for (int i = 0; i <= rlevel; i++)
			{
				n->forward[i] = update[i]->forward[i];
				update[i]->forward[i] = n;
			}
			cout << "Succeefully inserted key" << value << endl;
		}

	}

	// �˻� �Լ�
	bool search(int value) const
	{
		Node* current = header;
		// �ֻ��� �������� �����Ͽ� �˻�
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
		}
		// �˻��� ����� ���� ��ȯ�ϰų� ������ false��ȯ
		current = current->forward[0];
		if (current && current->value == value)
		{
			cout << "Found key : " << value << endl;
			return true;
		}
		else
		{
			cout << "key not found : " << value << endl;
			return false;
		}
	}

	// ���� �Լ�
	void remove(int value)
	{
		Node* current = header;
		Node** update = new Node*[MAX_LEVEL + 1];
		memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));

		// �� �������� ������ ����� ���� ��带 ã��
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] != nullptr && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
			update[i] = current;
		}
		// ������ ��带 ã�� ��쿡�� ���� ����
		current = current->forward[0];
		if (current != nullptr && current->value == value)
		{
			// ������Ʈ�� �迭�� ����Ͽ� ���� ����
			for (int i = 0; i <= level; i++)
			{
				if (update[i]->forward[i] != current)
				{
					break;
				}
				update[i]->forward[i] = current->forward[i];
			}
		}
		delete current;

		// ���� ����
		while (level > 0 && header->forward[level] == nullptr)
		{
			level--;
		}
		cout << "Successfully deleted key " << value << endl;
	}

	//��� �Լ�
	void display() const
	{
		for (int i = 0; i <= level; i++)
		{	// �� �������� ��带 ���
			Node* node = header->forward[i];
			cout << "level" << i << " : ";
			while (node != nullptr)
			{
				cout << node->value << " ";
				node = node->forward[i];
			}
			cout << endl;
		}
	}
};


int main()
{



	srand((unsigned)time(0));

	SkipList list(3, 0.5);

	list.insert(3);
	list.insert(6);
	list.insert(7);
	list.insert(9);
	list.insert(12);
	list.insert(19);
	list.insert(17);
	list.insert(26);
	list.insert(21);
	list.insert(25);

	list.display();

	list.search(19);
	list.search(15);

	list.remove(19);
	list.remove(25);

	list.display();










	return 0;
}






















