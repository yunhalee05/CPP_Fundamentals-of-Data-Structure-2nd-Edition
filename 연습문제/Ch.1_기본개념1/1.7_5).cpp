#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int a[10] = { 1,3,6,5,2,7,3,1,8,1 };

	fill(a, a + 10, 0);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i] << " ";
	}
	return 0;

}