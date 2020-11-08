#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int a[10] = { 1,3,6,5,2,7,3,1,8,1 };

	cout << count(a, a + 10, a[0]);
	return 0;

}