#pragma once

#include "cNode.h"
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class cBinarySearchTree
{
	friend class cNode<T>;

public:
	cBinarySearchTree();
	~cBinarySearchTree();
	void treeInsert(T x);
	void treeDelete(T x);
	void treePrint();

private:
	cNode<T>* treeInsert(cNode<T>* t, T x);
	void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);
	cNode<T>* deleteNode(cNode<T>* r);
	void treePrint(cNode<T>* t, int step);

	cNode<T>* root;
};

template<typename T>
inline cBinarySearchTree<T>::cBinarySearchTree()
{
	root = NULL;
}

template<typename T>
inline cBinarySearchTree<T>::~cBinarySearchTree()
{
	while (root != NULL)
	{
		treeDelete(root->key);
	}
}

template<typename T>
inline void cBinarySearchTree<T>::treeInsert(T x)
{
	root = treeInsert(root, x);
}

template<typename T>
inline void cBinarySearchTree<T>::treeDelete(T x)
{
	cNode<T>* r = root;
	cNode<T>* p = 0;

	while (true)
	{
		if (r == NULL)
		{
			cout << "삭제하려는 값이 이진트리에 없습니다, value: " << x << endl;
			return;
		}

		if (r->key == x)
		{
			break;
		}

		p = r;
		if (r->key > x)
		{
			r = r->left;
		}
		else
		{
			r = r->right;
		}
	}

	if (r != NULL)
	{
		treeDelete(root, r, p);
	}
}

template<typename T>
inline void cBinarySearchTree<T>::treePrint()
{
	if (root == NULL)
	{
		return;
	}

	treePrint(root, 0);
}

template<typename T>
inline cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* t, T x)
{
	if (t == NULL)
	{
		t = new cNode<T>(x);
		return t;
	}

	if (t->key > x)
	{
		t->left = treeInsert(t->left, x);
		return t;
	}
	else
	{
		t->right = treeInsert(t->right, x);
		return t;
	}
}

template<typename T>
inline void cBinarySearchTree<T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p)
{
	if (t == r)
	{
		root = deleteNode(t);
	}
	else if (r == p->left)
	{
		p->left = deleteNode(r);
	}
	else
	{
		p->right = deleteNode(r);
	}
}

template<typename T>
inline cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r)
{
	if (r->left == NULL && r->right == NULL)
	{
		delete r;
		return NULL;
	}
	else if (r->left == NULL && r->right != NULL)
	{
		cNode<T>* tempNode = r->right;
		r->right = NULL;
		delete r;
		return tempNode;
	}
	else if (r->left != NULL && r->right == NULL)
	{
		cNode<T>* tempNode = r->left;
		r->left = NULL;
		delete r;
		return tempNode;
	}
	else
	{
		cNode<T>* searchNode = r->right;
		cNode<T>* parentNode = NULL;

		while (searchNode->left != NULL)
		{
			parentNode = searchNode;
			searchNode = searchNode->left;
		}

		r->key = searchNode->key;

		if (searchNode == r->right)
		{
			r->right = searchNode->right;
		}
		else
		{
			parentNode->left = searchNode->right;
		}

		return r;
	}
}

template<typename T>
inline void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step)
{
	const char* BLANK = "    ";

	for (int index = 0; index < step; index++)
	{
		cout << BLANK;
	}

	cout << t->key << endl;

	if (t->left != NULL)
	{
		step++;
		treePrint(t->left, step);
		step--;
	}

	if (t->right != NULL)
	{
		step++;
		treePrint(t->right, step);
		step--;
	}

	return;
}
