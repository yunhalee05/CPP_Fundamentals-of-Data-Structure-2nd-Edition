#include <iostream>


using namespace std;

class ChainNode
{
private:
	int data;
	ChainNode* link;


public:
	ChainNode(int element = 0, ChainNode* next = 0) : data(element), link(next)
	{

	}
	~ChainNode()
	{

	}
	int Data()
	{
		return data;
	}

	friend class Chain;

};
class Chain
{
private:
	ChainNode* first;
public:
	ChainNode* Insert(ChainNode* x, int y)//노드x 다음에 y값을 삽입해라
	{
		if (first)
		{
			x->link = new ChainNode(y, x->link);
			return x->link;

		}
		else
		{
			first = new ChainNode(y);
			return first->link;
		}
	}
	int Data()
	{
		return first->data;
	}
	ChainNode* First()
	{
		return first;
	}
	int length()//체임의 길이를 반환해라
	{
		int len = 0;
		ChainNode* z = first;
		while (z != NULL)
		{
			z = z->link;
			len++;
		}
		return len;
	}
	void Delete(ChainNode* x)//y는 x앞의 노드이다. x는 체인의 임의 노드이다.
	{
		if (x == first)//만약 x가 First라면 y는 없다
		{
			first = first->link;

		}
		else
		{
			ChainNode* temp = first;
			while (temp->link != x)
			{
				temp = temp->link;
			}

			temp->link = x->link;//y가 가르키는 것이 x가가르키던 것이된다.
		}
		delete x;
	}
	void Deletestart()
	{
		ChainNode* temp = first;
		while (temp->link->link != NULL)
		{
			if (temp == first)
			{
				first = first->link;
				delete temp;
				temp = first->link;
			}
			else
			{
				ChainNode* y = temp->link;
				delete temp;
				temp = y->link;
			}
		}
		if (temp->link->link == NULL)
		{
			ChainNode* y = temp->link;
			delete temp;
		}

	}

	friend void Merge(Chain& x, Chain& y, Chain& z);


};
void Merge(Chain& x, Chain& y, Chain& z)
{
	ChainNode* x_temp = x.first;
	ChainNode* y_temp = y.first;
	ChainNode* z_temp = z.first;

	while (y.first != NULL || x_temp != NULL)//둘중 길이가 짧은 것이 끝날때가지 번갈아서 넣는다.
	{
		z_temp = z.Insert(z_temp, x.Data());
		x.Delete(x.First());
		z_temp = z.Insert(z_temp, y.Data());
		y.Delete(y.First());
	}
	if (x.length() > y.length())//남은것을 넣는다. 
	{
		while (x_temp != NULL)
		{
			z_temp = z.Insert(z_temp, x.Data());
			x.Delete(x.First());
		}
	}
	else if (x.length() < y.length())
	{
		while (x_temp != NULL)
		{
			z_temp = z.Insert(z_temp, y.Data());
			y.Delete(y.First());
		}
	}
}
