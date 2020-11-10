#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


class CppArray
{
private:
	int size;
	float* cpparr;
public:
	CppArray(int n = 10, float initvalue = 0.0) : size(n)
	{
		cpparr = new float[size];
		for (int i = 0; i < size; i++)
		{
			cpparr[i] = initvalue;
		}

	}
	CppArray(const CppArray& cp2)
	{
		size = cp2.size;
		cpparr = new float[size];
		for (int i = 0; i < size; i++)
		{
			cpparr[i] = cp2.cpparr[i];
		}
	}
	~CppArray()
	{
		delete[] cpparr;
	}
	CppArray& operator =(const CppArray& cp2)
	{
		if (this != &cp2)
		{
			delete[] cpparr;
			size = cp2.size;
			cpparr = new float[size];
			for (int i = 0; i < size; i++)
			{
				cpparr[i] = cp2.cpparr[i];
			}
		}
		return (*this);
	}
	float& operator [](int i)
	{
		if (i >= 0 && i < size)
		{
			return cpparr[i];
		}
		else
		{
			cout << "Error" << endl;
		}
	}
	int Getsize()
	{
		return size;
	}
	friend ostream& operator <<(ostream& os, CppArray& cp);
	friend istream& operator >>(istream& is, CppArray& cp);

};

ostream& operator <<(ostream& os, CppArray& cp)
{
	for (int i = 0; i < cp.size; i++)
	{
		os << cp.cpparr[i] << " ";
	}
	os << endl;
	return os;
}
istream& operator >>(istream& is, CppArray& cp)
{
	cout << "Please input array size" << endl;
	is >> cp.size;
	for (int i = 0; i < cp.size; i++)
	{
		is >> cp.cpparr[i];
	}
	return is;
}


int main()
{
	CppArray cp1;
	cin >> cp1;
	cout << cp1;

	cout << "Copy" << endl;
	CppArray cp2 = cp1;
	cout << cp2;

}