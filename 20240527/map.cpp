#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int key;
	string value;
	Node* left;
	Node* right;
	Node(int k, const string& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class Map
{
private:
	Node* root;

	Node* insert(Node* node, int key, const string& value)
	{
		if (node == nullptr)
		{
			return new Node(key, value);
		}
		if (key < node->key)
		{
			node->left = insert(node->left, key, value);
		}
		else if (key > node->key)
		{
			node->right = insert(node->right, key, value);
 		}
		else
		{
			node->value = value;  // key already exists, update the value
		}
		return node;
	}

	Node* find(Node* node, int key) const
	{
		if (node == nullptr || node->key == key)
		{
			return node;
		}
		if (key < node->key)
		{
			return find(node->left, key);
		}
		else
		{
			return find(node->right, key);
		}
	}
	// helper function to delete a node
	Node* remove(Node* node, int key)
	{
		if (node == nullptr) return node;

		if (key < node->key)
		{
			node->left = remove(node->left, key);
		}
		else if (key > node->key)
		{
			node->right = remove(node->right, key);
		}
		else
		{
			if (node->left == nullptr)
			{
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}
			Node* temp = minValueNode(node->right);
			node->key = temp->key;
			node->value = temp->value;
			node->right = remove(node->right, temp->key);
		}
		return node;
	}

	// Helper function to find the node with the minimun key value
	Node* minValueNode(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	// Helpre function to print thr map (in-order traversal)
	void inorderPrint(Node* node) const
	{
		if (node != nullptr)
		{
			inorderPrint(node->left);
			cout << node->key << ": " << node->value << endl;
			inorderPrint(node->right);
		}
	}

public:
	Map(): root(nullptr) {}

	// Insert a key-value pair
	void insert(int key, const string& value)
	{
		root = insert(root, key, value);
	}

	// Find a value by key
	string find(int key) const
	{
		Node* node = find(root, key);
		if (node == nullptr)
		{
			return "Key not found";
		}
		else
		{
			return node->value;
		}
		
	}
	// Remove a key-value pair
	void remove(int key)
	{
		root = remove(root, key);
	}
	// Print the map
	void print() const
	{
		inorderPrint(root);
	}


};

int main()
{
	Map my_map;

	my_map.insert(10, "ten");
	my_map.insert(20, "twenty");
	my_map.insert(30, "thirty");
	my_map.insert(15, "fifteen");
	my_map.insert(25, "ten");

	cout << "Map contenets : " << endl;
	my_map.print();

	cout << "Value for key 20 : " << my_map.find(20) << endl;

	my_map.remove(20);
	cout << "Map contents after removing key 20 : " << endl;
	my_map.print();

	return 0;
}









