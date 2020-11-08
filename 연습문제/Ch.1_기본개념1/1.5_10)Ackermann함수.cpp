#include <iostream>

using namespace std;

//Recursive 
void Recursive(int m, int n)
{
	if (m == 0)
	{
		return n + 1;
	}
	if (n == 0)
	{
		return Recursive(m - 1, 1);
	}
	else
	{
		return Recursive(m - 1, Recursive(m, n - 1));
	}

}
//Iterative
int main()
{
	int a[100][100];
	int n, m;
	cin >> m >> n;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (i == 0)
			{
				a[i][j] = j + 1;
			}
			else if (j == 0)
			{
				a[i][j] = a[i - 1][1];
			}
			else
			{
				a[i][j] = a[i - 1][a[i][j - 1]];
			}
		}
	}
	return a[m][n];
}