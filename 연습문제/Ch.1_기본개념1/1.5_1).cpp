#include <iostream>

int main()
{
	int n, result =1;//1
	int* a = new int[n+1];//1
	cin >> n;//1
	for (int i = 0; i <= n; i++)//n+2
	{
		cin >> a[i];//n+1
	}
	for (int i = n; i <= 0; i--)//n+2
	{
		result = result * x +a[i];//n+1
	}
	cout << result;//1
	delete[] a;
}

