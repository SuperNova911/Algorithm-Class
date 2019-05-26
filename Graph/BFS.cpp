#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	int x, y;
	int s;

	int** graph;

	cin >> n >> m;

	graph = new int* [n];
	for (int index = 0; index < n; index++)
	{
		graph[index] = new int[n];
		memset(graph[index], 0, sizeof(int) * n);
	}

	for (int index = 0; index < m; index++)
	{
		cin >> x >> y;
		graph[x - 1][y - 1] = 1;
		graph[y - 1][x - 1] = 1;
	}

	cin >> s;

	bool* visited = new bool[n];
	memset(visited, 0, sizeof(bool) * n);
	
	queue<int> bstQueue;

	visited[s - 1] = true;
	bstQueue.push(s - 1);

	int targetNode;
	while (bstQueue.empty() == false)
	{
		targetNode = bstQueue.front();
		bstQueue.pop();
		cout << targetNode + 1 << " ";

		for (int index = 0; index < n; index++)
		{
			if (graph[targetNode][index] == 0)
			{
				continue;
			}

			if (visited[index] == false)
			{
				visited[index] = true;
				bstQueue.push(index);
			}
		}
	}

	cout << endl;

	return 0;
}