#include <iostream>
#include <algorithm>

using namespace std;


class Complex
{
private:
	int real;
	int unreal;
public:
	Complex(int a = 0, int b = 0) :real(a), unreal(b)
	{
	}
	~Complex()
	{
	}
	Complex operator + (const Complex& r)
	{
		int newreal = real + r.real;
		int newunreal = unreal + r.unreal;
		return Complex(newreal, newunreal);
	}
	Complex operator * (const Complex& r)
	{
		int newreal = real * r.real - unreal * r.unreal;
		int newunreal = real * r.unreal + unreal * r.real;

		return Complex(newreal, newunreal);
	}
	friend ostream& operator <<(ostream& os, Complex& r);
	friend istream& operator >>(istream& is, Complex& r);

};

ostream& operator <<(ostream& os, Complex& r)
{
	cout << r.real << "+" << r.unreal << "i" << endl;
	return os;
}
istream& operator >>(istream& is, Complex& r)
{
	cin >> r.real;
	cout << "+";
	cin >> r.unreal;
	cout << "i" << endl;
	return is;
}


int main()
{
	Complex c1(3, 2);
	cout << "Now" << endl;
	cout << c1;

	Complex c2;
	cout << "New" << endl;
	cin >> c2;

	Complex c3 = c1 + c2;
	cout << "Add" << endl;
	cout << c3;

	Complex c4 = c1 * c2;
	cout << "Multiply" << endl;
	cout << c4;
}