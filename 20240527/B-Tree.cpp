#include <iostream>
#include <vector>

using namespace std;


// B-Ʈ�� ����� ����

class BTreeNode
{
	vector<int> keys;    // ��忡 ����Ǵ� Ű��
	int t;  // �ּ� Ű�� ��

	vector<BTreeNode*> children;  // �ڽ� ����
	bool leaf; // ���� ��� ����

public:
	BTreeNode(int _t, bool _leaf); // ������

	void insertNonFull(int key); //  ��尡 ���� ���� ���� ��� ����
	void splitChild(int i, BTreeNode* y);  // �ڽ� ���� ���
	void traverse();  // Ʈ�� ��ȸ

	friend class BTree;
};

class BTree 
{
	BTreeNode* root;  // ��Ʈ ���
	int t; //�ּ� Ű�� ��

public:
	BTree(int _t) : root(nullptr), t(_t) {} // ������

	void travers() { if (root != nullptr) root->traverse(); }  // Ʈ�� ��ȸ
	void insert(int key);  // Ű ����
};


BTreeNode::BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf)
{
	keys.reserve(2 * t - 1);
	children.reserve(2 * t);
}


void BTreeNode::insertNonFull(int key)
{
	int i = keys.size() - 1;

	if (leaf)
	{
		keys.push_back(0); //���� Ȯ��
		while (i >= 0 && key < keys[i])
		{
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = key;
	}
	else
	{
		while (i >= 0 && key < keys[i])
			i--;
		if (children[i + 1]->keys.size() == 2 * t - 1)
		{
			splitChild(i + 1, children[i + 1]);
			if (key > keys[i + 1])
				i++;
		}
		children[i + 1]->insertNonFull(key);
	}
	

}

void BTreeNode::splitChild(int i, BTreeNode* y)
{
	BTreeNode* z = new BTreeNode(y->t, y->leaf);
	z->keys.resize(t - 1);

	for (int j = 0; j < t - 1; j++)
	
		z->keys[j] = y->keys[j + t];
	
	if (!y->leaf)
	{
		z->children.resize(t);
		for (int j = 0; j < t; j++)
		{
			z->children[j] = y->children[j + t];
		}
	}
	y->keys.resize(t - 1);

	children.insert(children.begin() + i + 1, z);
	keys.insert(keys.begin() + i, y->keys[t - 1]);

	y->keys.pop_back();  //���� :  y���� ���ŵ� Ű�� pop
}

void BTreeNode::traverse()
{
	int i;
	for (i = 0; i < keys.size(); i++)
	{
		if (!leaf)
		{
			children[i]->traverse();
			
		}
		cout << " " << keys[i];
	}

	if (!leaf)
	{
		children[i]->traverse();
	}
}

void BTree::insert(int key)
{
	if (root == nullptr)
	{
		root = new BTreeNode(t, true);
		root->keys.push_back(key);
	}
	else
	{
		if (root->keys.size() == 2 * t - 1)
		{
			BTreeNode* s = new BTreeNode(t, false);
			s->children.push_back(root);
			s->splitChild(0, root);
			int i = 0;
			if (s->keys[0] < key)
			{
				i++;
			}
			s->children[i]->insertNonFull(key);
			root = s;
		}
		else
		{
			root->insertNonFull(key);
		}
	}
}

int main()
{
	BTree t(3);

	t.insert(10);
	t.insert(20);
	t.insert(5);
	t.insert(6);
	t.insert(12);
	t.insert(30);
	t.insert(7);
	t.insert(17);
	t.insert(75);
	
	cout << "Ʈ�� ��ȸ ��� : ";

	t.travers();
	cout << endl;

	return 0;
}











