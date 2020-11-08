#include <iostream>

using namespace std;

int ch[10];
char s[10];

void powerset(int n, int k)
{
	if (k == n)
	{
		cout << "(";
		for (int i = 0; i < n; i++)
		{
			if (ch[i] == 1)
			{
				cout << s[i];
			}
		}
		cout << ")" << endl;
	}
	else
	{
		if (ch[k] == 0)
		{
			ch[k] == 1;
			powerset(n, k + 1);
			ch[k] == 0;
			powerset(n, k + 1);

		}
	}

}
int main()
{
	int n;
	cin >> n;
	powerset(n, 0);

	return 0;

}