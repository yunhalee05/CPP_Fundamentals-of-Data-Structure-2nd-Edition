#include <iostream>


using namespace std;

template<typename T>
class ChainNode
{
private:
	T data;
	ChainNode<T>* link;


public:
	ChainNode(T element = 0, ChainNode* next = 0) : data(element), link(next)
	{

	}
	~ChainNode()
	{

	}
	T Data()
	{
		return data;
	}

	friend class Chain<T>;
	template<typename T>
	friend ostream& operator<<(ostream& os, Chain<T>& c);
};

template<typename T>
class Chain
{
private:
	ChainNode<T>* first;
public:
	Chain(ChainNode<T>* f = 0) : first(f)
	{

	}
	~Chain()
	{

	}
	class ChainIterator
	{
	private:
		ChainNode<T>* current;
	public:
		ChainIterator(ChainNode<T>* startNode = 0) :current(startNode)
		{
		}
		~ChainIterator()
		{
		}
		T Data()
		{
			return current->data;
		}
		T& operator*()const
		{
			return current->data;
		}
		T* operator->()const
		{
			return current->data;
		}
		ChainIterator begin()
		{
			return ChainIterator(first);
		}
		ChainIterator end()
		{
			return ChainIterator(0);
		}
		ChainIterator& operator++()
		{
			current = current->link;
			return *this;
		}
		ChainIterator operator++(int)
		{
			ChainIterator old = *this;
			current = current->link;
			return old;
		}
		bool operator!=(const ChainIterator right)const
		{
			return current != right.current;
		}
		bool opertator == (const ChainIterator right)const
		{
			return current == right.current;
		}

		template<typename T>
		friend ostream& operator<<(ostream& os, Chain<T>& c);

	};
	ChainIterator start()
	{
		return ChainIterator(first);
	}
	ChainIterator end()
	{
		return ChainIterator(0);
	}
	T Min()
	{
		Chain<T>::ChainIterator i = start();
		T min = i.Data();
		for (Chain<T>::ChainIterator i = start(); i != end(); i++)
		{
			if (min > i.Data())
			{
				min = i.Data();
			}
		}
		return min;
	}
	T Min()//¿Ã∞«∞°,?
	{

		T x = std::numeric_limits<T>::max();
		for (ChainIterator i = start(); i != end(); i++)
		{
			x = min(i.Data(), x);
		}

		return x;

	}
	template<class T>

	friend ostream& operator<<(ostream& os, Chain<T>& c);



};

template<typename T>
ostream& operator<<(ostream& os, Chain<T>& c)
{

	for (Chain<T>::ChainIterator i = c.start(); i != c.end(); i++)
	{
		os << i.Data() << " ";
	}
	os << i.Data() << endl;
	return os;
}