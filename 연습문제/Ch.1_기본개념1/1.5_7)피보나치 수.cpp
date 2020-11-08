#include <iostream>

using namespace std;


//Iterative Version
int main()
{
	int f[100];
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < 100; i++)
	{
		int tmp = i;
		f[tmp] = f[tmp - 1] + f[tmp - 2];
	}
	int i;
	cin >> i;
	cout << f[i];
	return 0;

}
//Recursive Version
void Recursive(int n)
{
	if (n <= 1)
	{
		return n;
	}

	else
	{
		return Recursive[n - 1] + Recursive[n - 2]
	}


}
