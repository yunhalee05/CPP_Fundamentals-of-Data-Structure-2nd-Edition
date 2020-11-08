#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int a[10] = { 3,4,6,5,2,1,7,9,8,11 };

	sort(a, a + 10);//a의 첫번째(0번)부터 a의 10번째(9번)까지 오름차순으로 정렬

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}



	return 0;

}