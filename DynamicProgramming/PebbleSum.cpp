#include <iostream>

using namespace std;

enum PebblePattern { OXX, XOX, XXO, OXO };

const int MAP_ROW = 3;
const int PATTERN_NUMBER = 4;

int** Map;
int** ResultTable;

int patternValue(int targetColumn, PebblePattern pattern)
{
	int result = 0;

	switch (pattern)
	{
	case OXX:
		result += Map[0][targetColumn];
		break;

	case XOX:
		result += Map[1][targetColumn];
		break;

	case XXO:
		result += Map[2][targetColumn];
		break;

	case OXO:
		result += Map[0][targetColumn];
		result += Map[2][targetColumn];
		break;

	default:
		break;
	}

	return result;
}

int maxMatchPatternValue(int targetRow, PebblePattern pattern)
{
	int max = 0;
	int prevColumn = targetRow - 1;

	switch (pattern)
	{
	case OXX:
		max = ResultTable[prevColumn][XOX] > ResultTable[prevColumn][XXO] ? ResultTable[prevColumn][XOX] : ResultTable[prevColumn][XXO];
		break;

	case XOX:
		max = ResultTable[prevColumn][OXX] > ResultTable[prevColumn][XXO] ? ResultTable[prevColumn][OXX] : ResultTable[prevColumn][XXO];
		if (ResultTable[prevColumn][OXO] > max)
		{
			max = ResultTable[prevColumn][OXO];
		}

		break;

	case XXO:
		max = ResultTable[prevColumn][OXX] > ResultTable[prevColumn][XOX] ? ResultTable[prevColumn][OXX] : ResultTable[prevColumn][XOX];
		break;

	case OXO:
		max = ResultTable[prevColumn][XOX];
		break;

	default:
		break;
	}

	return max;
}

int main()
{
	int m;
	
	cin >> m;

	Map = new int* [MAP_ROW];
	for (int index = 0; index < MAP_ROW; index++)
	{
		Map[index] = new int[m];
	}

	ResultTable = new int* [m];
	for (int index = 0; index < m; index++)
	{
		ResultTable[index] = new int[PATTERN_NUMBER];
	}

	for (int i = 0; i < MAP_ROW; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int pattern = 0; pattern < PATTERN_NUMBER; pattern++)
	{
		ResultTable[0][pattern] = patternValue(0, (PebblePattern)pattern);
	}

	for (int row = 1; row < m; row++)
	{
		for (int pattern = 0; pattern < PATTERN_NUMBER; pattern++)
		{
			ResultTable[row][pattern] = maxMatchPatternValue(row, (PebblePattern)pattern) + patternValue(row, (PebblePattern)pattern);
		}
	}

	int max = 0;
	for (int pattern = 0; pattern < PATTERN_NUMBER; pattern++)
	{
		if (ResultTable[m - 1][pattern] > max)
		{
			max = ResultTable[m - 1][pattern];
		}
	}

	cout << max << endl;

	return 0;
}