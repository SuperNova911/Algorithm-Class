#include "cBinarySearchTree.h"
#include <iostream>

using namespace std;

int main()
{
	char cmd;
	int n, x;
	cBinarySearchTree<int> tree;

	cin >> n;
	for (int index = 0; index < n; index++)
	{
		cin >> cmd >> x;

		switch (cmd)
		{
		case 'I':
			tree.treeInsert(x);
			break;

		case 'D':
			tree.treeDelete(x);
			break;
		}
	}
	tree.treePrint();

	return 0;
}