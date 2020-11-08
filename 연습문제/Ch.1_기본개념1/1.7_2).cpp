#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int a[10] = { 3,4,6,5,2,1,7,9,8,11 };


	do {

	} while (next_permutation(a, a + 10));//오름차순 정렬
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;


	do {

	} while (prev_permutation(a, a + 10));//내림차순 정렬
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}




	return 0;

}