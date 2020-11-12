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
	int Data()
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
		void Data()
		{
			return current->data;
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
	template<class T>

	friend ostream& operator<<(ostream& os, Chain<T>& c);



};

template<typename T>
ostream& operator<<(ostream& os, Chain<T>& c)
{
	for (Chain<T>::ChainIterator i = c.start; i != c.end; i++)
	{
		os << i.Data() << " ";
	}
	os << i.Data() << endl;
	return os;
}