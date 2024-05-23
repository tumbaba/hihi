#include "stdafx.h"
#include "set"

set<int> a;

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
	TreeNode* root;

	TreeNode* insertRecursive(TreeNode* node, int key)
	{	// ��尡 ��������� ���ο� ��带 �����Ͽ� ��ȯ
		if (node == nullptr)
		{
			return new TreeNode(key);
		}
		//Ű�� ���� ����� Ű���� ������ ���� ����Ʈ���� �̵��Ͽ� ����
		if (key < node->key)
		{
			node->left = insertRecursive(node->left, key);
		}
		// Ű�� ���� ����� Ű���� ũ�� ������ ����Ʈ���� �̵��Ͽ� ����
		if (key > node->key)
		{
			node->right = insertRecursive(node->right, key);
		}

		return node;
	}
	TreeNode* searchRecursive(TreeNode* node, int key) const
	{
		if (node == nullptr || node->key == key)
		{
			return node;
		}
		if (key < node->key)
		{
			return searchRecursive(node->left, key);
		}
		if (key > node->key)
		{
			return searchRecursive(node->right, key);
		}
	}
	// ����� ���� �Լ�
	TreeNode* deleteRecursive(TreeNode* node, int key)
	{
		if (node == nullptr) return node;

		if (key < node->key)
		{
			node->left = deleteRecursive(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = deleteRecursive(node->right, key);
		}
		else
		{
			// ��带 ã�����
			if (node->left == nullptr)
			{
				TreeNode* temp = node->right;
				delete node;
				return temp;  // ���� ��� ��ġ�� ���� ��ȯ
			}
			else if (node->right == nullptr)
			{
				TreeNode* temp = node->left;
				delete node;
				return temp;
			}
			TreeNode* temp = minValueNode(node->right);
			node->key = temp->key;
			node->right = deleteRecursive(node->right, temp->key);
		}
		return node;
	}
	// ���� ���� ���� ã�� �Լ�

	TreeNode* minValueNode(TreeNode* node)const
	{
		TreeNode* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	// ���� ���� ���� ã�� �Լ�
	TreeNode* maxValueNode(TreeNode* node)const
	{
		TreeNode* current = node;
		while (current && current->right != nullptr)
		{
			current = current->right;
		}
		return current;
	}
	// ����� ���� ��� �Լ�
	int heightRecursive(TreeNode* node) const
	{
		if (node == nullptr) return -1;
		int leftHeight = heightRecursive(node->left);
		int rightHeight = heightRecursive(node->right);
		return 1 + max(leftHeight, rightHeight);
	}
	// ���� ��ȸ(inorder traversal)
	void inorderTraversal(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inorderTraversal(node->left);
		cout << node->key << " ";
		inorderTraversal(node->right);
	}
	// ���� ��ȸ(preorder traversal)
	void preorderTraversal(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		cout << node->key << " ";
		inorderTraversal(node->left);
		inorderTraversal(node->right);
	}
	// ���� ��ȸ(postorder traversal)
	void postorderTraversal(TreeNode* node)
	{
		if (node == nullptr)
		{
			return;
		}
		inorderTraversal(node->left);
		inorderTraversal(node->right);
		cout << node->key << " ";
	}

public:
	BinarySearchTree(): root(nullptr) {}

	// ���� ����
	void insert(int key)
	{
		root = insertRecursive(root,key);
	}
	// Ž�� ����
	void search(int key)
	{
		root = searchRecursive(root, key);
	}
	//���� ����
	void remove(int key)
	{
		root = deleteRecursive(root, key);
	}
	// �ּҰ� ã��
	int findMin() const
	{
		TreeNode* node = minValueNode(root);
		if (node) return node->key;
		throw runtime_error("Tree is empty");

	}
	int findMax()const
	{
		TreeNode* node = maxValueNode(root);
		if (node) return node->key;
		throw runtime_error("Tree is empty");
	}
	// Ʈ���� ���� ���
	int heigth() const
	{
		return heightRecursive(root);
	}
	// ���� ��ȸ
	void inorderTraversal() 
	{
		inorderTraversal(root);
		cout << endl;
	}
	// ���� ��ȸ
	void preorderTraversal()
	{
		preorderTraversal(root);
		cout << endl;
	}
	// ���� ��ȸ
	void postorderTraversal()
	{
		postorderTraversal(root);
		cout << endl;
	}

	TreeNode* getRoot()
	{
		return root;
	}
};




int main()
{
	BinarySearchTree bst;
	// ���� Ž�� Ʈ���� ��� ����
	bst.insert(20);
	bst.insert(30);
	bst.insert(10);
	bst.insert(90);
	bst.insert(70);
	bst.insert(64);
	bst.insert(88);
	bst.insert(15);
	bst.insert(27);
	bst.insert(96);
	bst.insert(96);

	cout << "Inorder traversal : ";
	bst.inorderTraversal();
	
	cout << "Preorder traversal : " ;
	bst.preorderTraversal();

	cout << "postorder tarversal : ";
	bst.postorderTraversal();
	
	cout << "Height of the tree : " << bst.heigth() << endl;

	cout << "Minimum value : " << bst.findMin() << endl;
	cout << "Maximum value : " << bst.findMax() << endl;

	bst.remove(50);
	cout << "Inorder traversal after removing 50: ";
	bst.inorderTraversal();

	


	return 0;
}