#include <iostream>

using namespace std;

void KMP(string a, string p);
void PreProcessing(string p);

int* Helper;

int main()
{
	string a, p;

	cin >> a >> p;
	Helper = new int[p.length() + 1];

	KMP(a, p);

	return 0;
}

void KMP(string a, string p)
{
	PreProcessing(p);

	int i = 0;
	int j = 0;
	int compareCount = 0;
	bool found = false;

	while (i < a.length())
	{
		compareCount++;

		if (j == -1 || a[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = Helper[j];
		}

		if (j == p.length())
		{
			cout << compareCount << endl;
			j = Helper[j];
			found = true;
		}
	}

	if (found == false)
	{
		cout << "fail" << endl;
	}
}

void PreProcessing(string p)
{
	int j = 0;
	int k = -1;
	Helper[0] = -1;

	while (j < p.length())
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			Helper[j] = k;
		}
		else
		{
			k = Helper[k];
		}
	}
}