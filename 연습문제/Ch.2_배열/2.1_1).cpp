#include <iostream>
#include <algorithm>

using namespace std;


class Rectangle
{
private:
	int xLow, yLow;
	int height, width;

public:
	Rectangle(int x = 0, int y = 0, int h = 0, int w = 0) : xLow(x), yLow(y), height(h), width(w)
	{

	}
	~Rectangle()
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
	bool operator <(const Rectangle& s)//r의 면적이 s보다 작으면 true
	{
		if (height * width < s.height * s.width) return 1;
		else return 0;
	}
	friend ostream& operator <<(ostream& os, Rectangle& r);//operator가 클래스 안의 데이터 멤버에 접근 가능하도록 friend 선언
};