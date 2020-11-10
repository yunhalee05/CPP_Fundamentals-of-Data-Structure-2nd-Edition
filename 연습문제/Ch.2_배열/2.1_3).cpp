#include <iostream>
#include <algorithm>

using namespace std;


class currency
{
private:
	int dollar;
	int cents;
public:
	currency(int d = 0, int c = 0) : dollar(d), cents(c)
	{
	}
	~currency()
	{
	}
	currency operator +(const currency& r)//+연산자 
	{
		int newdollar = dollar + r.dollar;
		int newcents = cents + r.cents;
		if (newcents > 99)
		{
			newdollar++;
			newcents = newcents - 100;
		}
		return currency(newdollar, newcents);//각 데이터 멤버를 설정하여 반환
	}
	currency operator - (const currency& r)//-연산자
	{
		int newdollar = dollar - r.dollar;
		int newcents = cents - r.cents;
		if (newcents < 0)
		{
			if (newdollar <= 0)
			{
				cout << "broken" << endl;

			}
			else
			{
				newdollar--;
				newcents = newcents + 100;
			}
		}
		return currency(newdollar, newcents);
	}
	currency operator * (const currency& r)//*연산자
	{
		int newdollar = dollar * r.dollar;
		int newcents = cents * r.cents;
		while (newcents >= 100)
		{
			newdollar++;
			newcents = newcents - 100;
		}
		return currency(newdollar, newcents);
	}
	friend ostream& operator <<(ostream& os, currency& r);
	friend istream& operator >>(istream& is, currency& r);
};

ostream& operator <<(ostream& os, currency& r)//<<연산자 다중화
{
	os << "Dollar :" << r.dollar << endl;
	os << "Cents :" << r.cents << endl;

	return os;
}
istream& operator >>(istream& is, currency& r)//>>연산자 다중화
{
	cout << "New Dollar is :";
	is >> r.dollar;
	cout << "New Cents is :";
	is >> r.cents;

	return is;
}

int main()
{
	currency c1;
	cout << "Now" << endl;
	cin >> c1;

	currency c2(1, 50);
	cout << "New" << endl;
	cout << c2;

	currency c3 = c1 + c2;
	cout << "Add" << endl;
	cout << c3;

	currency c4 = c1 - c2;
	cout << "Subtract" << endl;
	cout << c4;

	currency c5 = c1 * c2;
	cout << "Multiply" << endl;
	cout << c5;

}
