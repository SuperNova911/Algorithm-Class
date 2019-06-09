#include <iostream>

using namespace std;

int NativeMatching(string a, string b);
bool IsMatching(string a, string b, int startIndex);

int CompareCount = 0;

int main()
{
	string a, b;
	cin >> a >> b;

	int patternNumber = NativeMatching(a, b);

	cout << CompareCount << " " << patternNumber << endl;

	return 0;
}

int NativeMatching(string a, string b)
{
	int n = a.length();
	int m = b.length();
	int matchPatternNumber = 0;

	for (int index = 0; index < n - m + 1; index++)
	{
		if (IsMatching(a, b, index))
		{
			matchPatternNumber++;
		}
	}

	return matchPatternNumber;
}

bool IsMatching(string a, string b, int startIndex)
{
	for (int index = 0; (unsigned int)index < b.length(); index++)
	{
		CompareCount++;
		if (a[startIndex + index] != b[index])
		{
			return false;
		}
	}

	return true;
}