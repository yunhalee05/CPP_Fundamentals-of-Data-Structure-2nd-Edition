#include <iostream>


using namespace std;


void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
	{
		cout << "원판" << n << "을 " << from << "에서 " << to << "로 옮김" << endl;
	}
	else
	{
		hanoi(n - 1, from, to, by);
		cout << "원판" << n << "을 " << from << "에서 " << to << "로 옮김" << endl;
		hanoi(n - 1, by, from, to);

	}

}
int main()
{

	hanoi(3, 'A', 'B', 'C');
	return 0;

}
