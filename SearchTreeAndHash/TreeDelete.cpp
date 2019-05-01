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
	enum SearchOrderType { PreOrder = 0, InOrder = 1, PostOrder = 2 };

	Tree();
	Node* treeInsert(Node*& node, int key);
	void treeDelete(Node*& node, int key);
	void treePrint(SearchOrderType orderType);

	Node* root;
	int insertCount;

private:
	Node* deleteNode(Node*& node);
	void treePrint(Node*& node, SearchOrderType orderType);
};

Tree::Tree()
{
	root = NULL;
	insertCount = 0;
}

Node* Tree::treeInsert(Node*& node, int key)
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

void Tree::treeDelete(Node*& node, int key)
{
	if (node->key == key)
	{
		node = deleteNode(node);
	}
	else if (node->key > key)
	{
		treeDelete(node->left, key);
	}
	else
	{
		treeDelete(node->right, key);
	}
}

void Tree::treePrint(SearchOrderType orderType)
{
	treePrint(root, orderType);
}

Node* Tree::deleteNode(Node*& node)
{
	if (node->left == NULL && node->right == NULL)
	{
		delete node;
		return NULL;
	}
	else if (node->left == NULL && node->right != NULL)
	{
		Node* temp = node->right;
		delete node;
		return temp;
	}
	else if (node->left != NULL && node->right == NULL)
	{
		Node* temp = node->left;
		delete node;
		return temp;
	}
	else
	{
		Node* searchNode = node->right;
		Node* parentNode = NULL;

		while (searchNode->left != NULL)
		{
			parentNode = searchNode;
			searchNode = searchNode->left;
		}

		node->key = searchNode->key;
		if (searchNode == node->right)
		{
			node->right = searchNode->right;
		}
		else
		{
			parentNode->left = searchNode->right;
		}

		return node;
	}
}

void Tree::treePrint(Node*& node, SearchOrderType orderType)
{
	switch (orderType)
	{
	case PreOrder:
		cout << node->key << " ";
		if (node->left != NULL)
		{
			treePrint(node->left, orderType);
		}
		if (node->right != NULL)
		{
			treePrint(node->right, orderType);
		}
		break;

	case InOrder:
		if (node->left != NULL)
		{
			treePrint(node->left, orderType);
		}
		cout << node->key << " ";
		if (node->right != NULL)
		{
			treePrint(node->right, orderType);
		}
		break;

	case PostOrder:
		if (node->left != NULL)
		{
			treePrint(node->left, orderType);
		}
		if (node->right != NULL)
		{
			treePrint(node->right, orderType);
		}
		cout << node->key << " ";

	default:
		break;
	}

	return;
}

int main()
{
	int n, insertElement;
	Tree tree = Tree();

	cin >> n;
	for (int index = 0; index < n; index++)
	{
		cin >> insertElement;
		tree.treeInsert(tree.root, insertElement);
	}

	int k, searchOrder, deleteElement;

	cin >> k;
	for (int index = 0; index < k; index++)
	{
		cin >> searchOrder;
		cin >> deleteElement;

		tree.treeDelete(tree.root, deleteElement);
		tree.treePrint((Tree::SearchOrderType)searchOrder);
		cout << endl;
	}

	return 0;
}
