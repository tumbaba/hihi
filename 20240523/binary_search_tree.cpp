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
	{	// 노드가 비어있으면 새로운 노드를 생성하여 반환
		if (node == nullptr)
		{
			return new TreeNode(key);
		}
		//키가 현재 노드의 키보다 작으면 왼쪽 서브트리로 이동하여 삽입
		if (key < node->key)
		{
			node->left = insertRecursive(node->left, key);
		}
		// 키가 현재 노드의 키보다 크면 오른쪽 서브트리로 이동하여 삽입
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
	// 재귀적 삭제 함수
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
			// 노드를 찾은경우
			if (node->left == nullptr)
			{
				TreeNode* temp = node->right;
				delete node;
				return temp;  // 현제 노드 위치에 값을 반환
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
	// 가장 작은 값을 찾는 함수

	TreeNode* minValueNode(TreeNode* node)const
	{
		TreeNode* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	// 가장 높은 값을 찾는 함수
	TreeNode* maxValueNode(TreeNode* node)const
	{
		TreeNode* current = node;
		while (current && current->right != nullptr)
		{
			current = current->right;
		}
		return current;
	}
	// 재귀적 높이 계산 함수
	int heightRecursive(TreeNode* node) const
	{
		if (node == nullptr) return -1;
		int leftHeight = heightRecursive(node->left);
		int rightHeight = heightRecursive(node->right);
		return 1 + max(leftHeight, rightHeight);
	}
	// 중위 순회(inorder traversal)
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
	// 전위 순회(preorder traversal)
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
	// 후위 순회(postorder traversal)
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

	// 삽입 연산
	void insert(int key)
	{
		root = insertRecursive(root,key);
	}
	// 탐색 연산
	void search(int key)
	{
		root = searchRecursive(root, key);
	}
	//삭제 연산
	void remove(int key)
	{
		root = deleteRecursive(root, key);
	}
	// 최소값 찾기
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
	// 트리의 높이 계산
	int heigth() const
	{
		return heightRecursive(root);
	}
	// 중위 순회
	void inorderTraversal() 
	{
		inorderTraversal(root);
		cout << endl;
	}
	// 전위 순회
	void preorderTraversal()
	{
		preorderTraversal(root);
		cout << endl;
	}
	// 후위 순회
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
	// 이진 탐색 트리에 요소 삽입
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