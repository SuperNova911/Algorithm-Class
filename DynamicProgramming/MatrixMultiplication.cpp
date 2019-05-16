#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
	int n;

	cin >> n;

	int* matrix = new int[n + 1];

	int** kappa = new int* [n + 1];
	for (int index = 0; index < n + 1; index++)
	{
		kappa[index] = new int[n + 1];
	}

	int row, col;
	for (int index = 0; index < n; index++)
	{
		cin >> row >> col;
		matrix[index] = row;
		matrix[index + 1] = col;
	}

	for (int i = 1; i <= n; i++)
	{
		kappa[i][i] = 0;
	}

	for (int r = 1; r < n; r++)
	{
		for (int i = 1; i <= n - r; i++)
		{
			int j = i + r;
			int min = INT_MAX;

			for (int k = i; k < j; k++)
			{
				min = kappa[i][k] + kappa[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j] < min ? kappa[i][k] + kappa[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j] : min;
			}

			kappa[i][j] = min;
		}
	}

	cout << kappa[1][n] << endl;

	return 0;
}