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
	friend class Chain;

};
class Chain
{
private:
	ChainNode* first;
public:
	void Insert(ChainNode* x, int y)//노드x 다음에 y값을 삽입해라
	{
		if (first)
		{
			x->link = new ChainNode(y, x->link);

		}
		else
		{
			first = new ChainNode(y);
		}
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
};