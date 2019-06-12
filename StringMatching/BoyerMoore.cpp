#include <iostream>

using namespace std;

void BoyerMooreHorspool(string a, string p);
void ComputeJump(string p, int* jump);

int main()
{
	string a, p;
	cin >> a >> p;

	BoyerMooreHorspool(a, p);

	return 0;
}

void BoyerMooreHorspool(string a, string p)
{
	int n = a.length();
	int m = p.length();
	int count = 0;
	int matchCount = 0;

	int* jump = new int[128];
	ComputeJump(p, jump);

	int i = 1;
	int j;
	int k;

	while (i <= n - m + 1)
	{
		j = m;
		k = i + m - 1;
		
		while (j > 0 && p[j - 1] == a[k - 1])
		{
			count++;
			j--;
			k--;
		}

		if (j == 0)
		{
			matchCount++;
		}
		
		i = i + jump[a[i + m - 2]];
	}

	cout << count << " " << matchCount << endl;
}

void ComputeJump(string p, int* jump)
{
	for (int index = 0; index < 128; index++)
	{
		jump[index] = p.length();
	}

	for (int index = 0; index < (int)p.length() - 1; index++)
	{
		jump[p[index]] = p.length() - 1 - index;
	}
}