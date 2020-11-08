#include <iostream>

using namespace std;


//Iterative Version
int main()
{
	int n, result;
	cin >> n;

	if (n <= 1)
	{
		result = 1;
	}
	else {
		for (int i = n; i > 0; i--)
		{
			int tmp = i;
			result *= tmp;
		}
	}
	cout << result;
	return 0;
}

//Recursive Version
void Recursive(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return  n * Recursive(n - 1);
	}
}