#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int ExtractMin(bool visited[], unsigned int distance[], int size)
{
	int minIndex = 0;
	int minValue = INT_MAX;

	for (int index = 0; index < size; index++)
	{
		if (visited[index] == true)
		{
			continue;
		}

		if (distance[index] < (unsigned int)minValue)
		{
			minValue = distance[index];
			minIndex = index;
		}
	}

	return minIndex;
}

int main()
{
	int n, m;
	int x, y, w;
	int r, t;

	cin >> n >> m;

	int** graph = new int* [n];
	unsigned int* distance = new unsigned int[n];
	bool* visited = new bool[n];
	int visitedNode = 0;
	int* prev = new int[n];

	for (int index = 0; index < n; index++)
	{
		graph[index] = new int[n];
		memset(graph[index], 0, sizeof(int) * n);

		distance[index] = INT_MAX;
		visited[index] = false;
		prev[index] = -1;
	}

	for (int index = 0; index < m; index++)
	{
		cin >> x >> y >> w;

		graph[x - 1][y - 1] = w;
	}

	cin >> r >> t;

	distance[r - 1] = 0;

	int u;
	while (visitedNode <= n)
	{
		u = ExtractMin(visited, distance, n);
		visited[u] = true;
		visitedNode++;

		for (int v = 0; v < n; v++)
		{
			if (graph[u][v] == 0)
			{
				continue;
			}

			if (distance[u] + graph[u][v] < distance[v])
			{
				distance[v] = distance[u] + graph[u][v];
				prev[v] = u;
			}
		}
	}

	for (int index = 0; index < n; index++)
	{
		printf("%d ", prev[index] + 1);
	}

	if (distance[t - 1] == INT_MAX)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << distance[t - 1] << endl;
	}

	return 0;
}