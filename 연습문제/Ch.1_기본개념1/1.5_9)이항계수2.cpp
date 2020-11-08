#include <iostream>

using namespace std;

int cnt = 1;
void Recursive(int n, int m)
{

	if (m == 0 || n == m)
	{
		return 1;
	}

	if (m > n / 2)
	{
		m = n - m;
	}
	return (n / m) * Recursive[n - 1, m - 1];
}
int main()
{
	int n, m;
	cin >> n >> m;
	int numerator;
	int denominator;
	if (m == n || m == 0)
	{
		return 1;
	}
	if (m > n / 2)
	{
		m = n - m;
	}

	for (int i = 1; i <= m; i++)
	{
		numerator *= (n - i + 1);
		denominator *= i;
	}
	return numerator / denominator;
}