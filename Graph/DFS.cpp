#include <iostream>
#include <string.h>

using namespace std;

int** Graph;
bool* Visited;
int N;

void DFS(int nodeIndex)
{
	Visited[nodeIndex] = true;
	cout << nodeIndex + 1 << " ";

	for (int index = 0; index < N; index++)
	{
		if (Graph[nodeIndex][index] == 0)
		{
			continue;
		}

		if (Visited[index] == false)
		{
			DFS(index);
		}
	}
}

int main()
{
	int m;
	int x, y;
	int s;

	cin >> N >> m;

	Graph = new int* [N];
	for (int index = 0; index < N; index++)
	{
		Graph[index] = new int[N];
		memset(Graph[index], 0, sizeof(int) * N);
	}

	for (int index = 0; index < m; index++)
	{
		cin >> x >> y;
		Graph[x - 1][y - 1] = 1;
		Graph[y - 1][x - 1] = 1;
	}

	cin >> s;

	Visited = new bool[N];
	memset(Visited, 0, sizeof(bool) * N);

	DFS(s - 1);
	cout << endl;

	return 0;
}