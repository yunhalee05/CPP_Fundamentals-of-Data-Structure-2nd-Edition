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
	ChainNode* Insert(ChainNode* x, int y)//���x ������ y���� �����ض�
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
	int length()//ü���� ���̸� ��ȯ�ض�
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
	void Delete(ChainNode* x)//y�� x���� ����̴�. x�� ü���� ���� ����̴�.
	{
		if (x == first)//���� x�� First��� y�� ����
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

			temp->link = x->link;//y�� ����Ű�� ���� x������Ű�� ���̵ȴ�.
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

	while (y.first != NULL || x_temp != NULL)//���� ���̰� ª�� ���� ���������� �����Ƽ� �ִ´�.
	{
		z_temp = z.Insert(z_temp, x.Data());
		x.Delete(x.First());
		z_temp = z.Insert(z_temp, y.Data());
		y.Delete(y.First());
	}
	if (x.length() > y.length())//�������� �ִ´�. 
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
