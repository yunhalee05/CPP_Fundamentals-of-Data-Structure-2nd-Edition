#include <iostream>
#include <algorithm>

using namespace std;


class MyRectangle
{
private:
	int xLow, yLow;
	int height, width;
	char* color;

public:
	MyRectangle(int x = 0, int y = 0, int h = 0, int w = 0) : xLow(x), yLow(y), height(h), width(w)
	{

	}
	~MyRectangle()
	{

	}
	int GetHeight()
	{
		return height;
	}
	int GetWidth()
	{
		return width;
	}
	int Perimeter()
	{
		return 2 * height + 2 * width;
	}
	int Area()
	{
		return height * width;
	}
	bool operator <(const MyRectangle& s)//r의 면적이 s보다 작으면 true
	{
		if (height * width < s.height * s.width) return 1;
		else return 0;
	}
	friend ostream& operator <<(ostream& os, MyRectangle& r);//operator가 클래스 안의 데이터 멤버에 접근 가능하도록 friend 선언
	friend istream& operator >>(istream& os, MyRectangle& r);
};

ostream& operator <<(ostream& os, MyRectangle& r)//출력연산자 << 다중화
{
	os << "Position is:" << r.xLow << "";
	os << r.yLow << endl;
	os << "Height is:" << r.GetHeight() << endl;
	os << "Width is:" << r.GetWidth() << endl;
	os << "Color is:" << r.color << endl;
	os << "Perimeter is:" << r.Perimeter() << endl;
	os << "Area is:" << r.Area() << endl;

	return os;
}
istream& operator >>(istream& is, MyRectangle& r)
{
	cout << "New position is:";
	is >> r.xLow >> r.yLow;
	cout << "New Height is:";
	is >> r.height;
	cout << "New Width is:";
	is >> r.width;
	cout << "New Color is:";
	is >> r.color;

	return is;
}


int main()
{
	MyRectangle r = (1, 3, 6, 6, "Red");
	MyRectangle s = (0, 0, 3, 6, "Yellow");

	cout << "Current R Rectangle" << endl;
	cout << r << endl;
	cout << "Current S Rectangle" << endl;
	cout << s << endl;
	cout << "Relocate R Rectangle" << endl;
	cin >> r;
	cout << "Relocate S Rectangle" << endl;
	cin >> s;
	cout << "Relocated R Rectanle" << endl;
	cout << r;
	cout << "Relocated S Rectangle" << endl;
	cout << s;


	return 0;


}