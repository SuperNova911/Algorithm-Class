#include <iostream>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	n++;
	m++;

	int** map = new int* [n];
	for (int index = 0; index < m; index++)
	{
		map[index] = new int[m];
	}

	for (int index = 0; index < n; index++)
	{
		map[index][0] = -1;
		map[0][index] = -1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (map[i - 1][j] == -1 && map[i][j - 1] == -1)
			{
				continue;
			}
			else if (map[i - 1][j] == -1)
			{
				map[i][j] += map[i][j - 1];
			}
			else if (map[i][j - 1] == -1)
			{
				map[i][j] += map[i - 1][j];
			}
			else
			{
				if (map[i - 1][j] < map[i][j - 1])
				{
					map[i][j] += map[i - 1][j];
				}
				else
				{
					map[i][j] += map[i][j - 1];
				}
			}
		}
	}

	cout << map[n - 1][m - 1] << endl;

	return 0;
}