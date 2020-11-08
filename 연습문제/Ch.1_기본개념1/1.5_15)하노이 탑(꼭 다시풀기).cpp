#include <iostream>


using namespace std;


void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		cout << "����" << n << "�� " << from << "���� " << to << "�� �ű�" << endl;
	}
	else
	{
		hanoi(n - 1, from, to, by);
		cout << "����" << n << "�� " << from << "���� " << to << "�� �ű�" << endl;
		hanoi(n - 1, by, from, to);

	}

}
int main()
{

	hanoi(3, 'A', 'B', 'C');
	return 0;

}
