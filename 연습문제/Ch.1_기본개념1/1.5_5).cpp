#include <iostream>

using namespace std;


int main()
{
	int n, x;
	cin >> n >> x;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int lt = 0;
	int rt = n - 1;
	while (lt <= rt)
	{
		int mid = (lt + rt) / 2;
		if (x == a[mid])
		{
			if (mid == 0)
			{
				cout << a[0];
				return 0;
			}
			else if (mid != 0)
			{
				cout << a[mid - 1];
				return 0;
			}
		}
		else if (x < a[mid])
		{
			rt = mid - 1;
		}
		else
		{
			lt = mid + 1;
		}
	}

	cout << -1;
}