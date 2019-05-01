#include <iostream>
using namespace std;

class Node
{
public:
	Node();

	Node* left;
	Node* right;
	int key;
};

Node::Node()
{
	left = NULL;
	right = NULL;
	key = -1;
}

class Tree
{
public:
	Tree();
	Node* treeInsert(Node*& node, int key);

	Node* root;
	int insertCount;
};

Tree::Tree()
{
	root = NULL;
	insertCount = 0;
}

Node* Tree::treeInsert(Node *&node, int key)
{
	insertCount++;

	if (node == NULL)
	{
		node = new Node();
		node->key = key;
		return node;
	}

	if (key < node->key)
	{
		node->left = treeInsert(node->left, key);
		return node;
	}
	else
	{
		node->right = treeInsert(node->right, key);
		return node;;
	}
}

int main()
{
	int n, userInput;
	cin >> n;

	Tree tree = Tree();
	for (int index = 0; index < n; index++)
	{
		cin >> userInput;
		tree.treeInsert(tree.root, userInput);
	}

	cout << tree.insertCount << endl;

	return 0;
}
