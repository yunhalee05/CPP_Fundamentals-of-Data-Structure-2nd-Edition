15.2
#include <iostream>

using namespace std;

int a[100];

void number(int k, int m)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			if (a[i] == 0)
			{
				cout << "true" << " ";
			}
			else
			{
				cout << "false" << " ";
			}
		}
		cout << endl;
	}
	else
	{
		if (a[k] == 0)
		{
			a[k] = 1;
			number(k + 1, m);
			a[k] = 0;
			number(k + 1, m);

		}
	}
}

int main()
{
	int n;
	cin >> n;

	number(0, n);

	return 0;
}
