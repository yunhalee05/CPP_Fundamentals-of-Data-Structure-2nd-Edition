#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


class Quadratic
{
private:
	int a;
	int b;
	int c;
public:
	Quadratic(int c2 = 0, int c1 = 0, int c0 = 0) :a(c2), b(c1), c(c0)
	{
	}
	~Quadratic()
	{
	}
	Quadratic operator + (const Quadratic& r)
	{
		int newa = a + r.a;
		int newb = b + r.b;
		int newc = c + r.c;
		return Quadratic(newa, newb, newc);
	}
	int Eval(int x)
	{
		int newa = a * x * x;
		int newb = b * x;

		return newa + newb + c;
	}
	void Answer(const Quadratic& r)
	{
		int x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		int x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "Answer is " << x1 << "and " << x2 << endl;
	}
	friend ostream& operator <<(ostream& os, Quadratic& r);
	friend istream& operator >>(istream& is, Quadratic& r);

};

ostream& operator <<(ostream& os, Quadratic& r)
{
	cout << r.a << "x^2" << "+" << r.b << "X" << "+" << r.c << endl;
	return os;
}
istream& operator >>(istream& is, Quadratic& r)
{
	cout << "x^2의 항";
	cin >> r.a;
	cout << "x의 항";
	cin >> r.b;
	cout << "상수항";
	cin >> r.c;
	return is;
}


int main()
{
	Quadratic r1;
	cin >> r1;
	cout << r1;
	cout << "r1의 근" << endl;
	r1.Answer(r1);
	cout << endl;

	cout << "x가 3이라면 " << r1.Eval(3) << endl;

	Quadratic r2;
	cin >> r2;
	cout << "r2의 근" << endl;
	r2.Answer(r2);

	Quadratic r3 = r1 + r2;
	cout << "Add" << endl;
	cout << r3;

}