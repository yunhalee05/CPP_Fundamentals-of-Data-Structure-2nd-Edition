#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	char str[] = "SKY";


	do {
		cout << str << endl; //정렬하는 동안 이루어지는 과정 출력
	} while (next_permutation(str, str + 3)); //오름차순 정렬



	cout << str;//최종 값 출력



	return 0;

}