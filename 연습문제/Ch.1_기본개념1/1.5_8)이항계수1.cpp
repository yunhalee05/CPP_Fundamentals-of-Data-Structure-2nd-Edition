#include <iostream>

using namespace std;

//Recursive 
void Recursive(int n, int m)
{
	if (m > n / 2)
	{
		m = n - m;
	}
	if (m == 0 || n == m)
	{
		return 1;
	}

	else
	{
		return Recursive[n - 1, m - 1] + Recursive[n - 1, m];
	}
}
//Iterative
int main()
{
	int n, m;
	cin >> n >> m;
	int a[10][10];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= minimum(i, k); j++)
		{
			if (i == j || j == 0)
			{
				return 1;
			}
			else
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
}
