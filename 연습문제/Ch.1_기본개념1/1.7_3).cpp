#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	char str[] = "SKY";


	do {
		cout << str << endl; //�����ϴ� ���� �̷������ ���� ���
	} while (next_permutation(str, str + 3)); //�������� ����



	cout << str;//���� �� ���



	return 0;

}