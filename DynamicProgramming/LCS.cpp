#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int** resultTable = new int* [a.length() + 1];
	for (int index = 0; index < a.length() + 1; index++)
	{
		resultTable[index] = new int[b.length() + 1];
	}

	for (int index = 0; index <= a.length(); index++)
	{
		resultTable[index][0] = 0;
	}

	for (int index = 0; index <= b.length(); index++)
	{
		resultTable[0][index] = 0;
	}

	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				resultTable[i][j] = resultTable[i - 1][j - 1] + 1;
			}
			else
			{
				resultTable[i][j] = resultTable[i - 1][j] > resultTable[i][j - 1] ? resultTable[i - 1][j] : resultTable[i][j - 1];
			}
		}
	}

	cout << resultTable[a.length()][b.length()] << endl;

	return 0;
}