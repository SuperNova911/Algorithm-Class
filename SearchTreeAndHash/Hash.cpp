#include <iostream>

using namespace std;

int TableSize;

int getHashValue(int value)
{
	return value % TableSize;
}

bool isPrime(int value)
{
	if (value < 1)
	{
		return false;
	}

	for (int i = 2; i < value / 2; i++)
	{
		if ((value % i) == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{

	int n, userInput, hashValue;
	int collisionTime = 0;

	cin >> n;

	TableSize = n * 2;
	while (isPrime(TableSize) == false)
	{
		TableSize++;
	}

	int* hashTable = new int[TableSize];
	for (int index = 0; index < TableSize; index++)
	{
		hashTable[index] = 0;
	}

	for (int index = 0; index < n; index++)
	{
		cin >> userInput;
		hashValue = getHashValue(userInput);

		while (hashTable[hashValue] != 0)
		{
			hashValue++;
			collisionTime++;

			hashValue = hashValue % TableSize;
		}

		hashTable[hashValue] = userInput;
	}

	cout << collisionTime << endl;

	delete[] hashTable;
	return 0;
}