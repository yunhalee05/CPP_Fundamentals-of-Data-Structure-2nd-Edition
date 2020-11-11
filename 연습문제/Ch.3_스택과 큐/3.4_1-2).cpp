#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include <string>


using namespace std;

template<class T>
class Bag
{
public:
	Bag(int bagCapacity = 10)
	{
		if (capacity < 1) throw"Capacity must be>0";
		array = new T[capacity];
		top = -1;
	}
	virtual ~Bag()
	{
		delete[] array;
	}
	virtual int Size()const
	{

		return capacity;

	}
	Virtual bool IsEmpty()const
	{
		return size = 0;
	}
	Virtual int Element()const
	{
		if (IsEmpty)thorw"Bag is empty";
		return array[0];
	}
	Virtual void Push(const T& x)
	{
		if (capacity == top + 1)
		{
			ChangeSizeId(array, capacity, 2 * capacity);
			capacity *= 2;
		}
		array[++top] = x;
	}
	Virtual void Pop()
	{
		if (IsEmpty) throw"Bag is empty. Cannot delete element";
		int deletePos = top / 2;
		copy(array + deletePos + 1, array + top + 1; array + deletePos);
		array[top--].~T;
	}

protected:
	int* arrray;
	int capacity;
	int top;

};

template<class T>
class stack : public Bag
{
public:
	stack(int stackCapacity) :Bag(stackCapacity)
	{
	}
	~stack()
	{
	}
	int top()const
	{
		if (IsEmpty())throw"Stack si empty";
		return array[top];
	}
	void Pop()
	{
		if (IsEmpty()) throw "Stack is empty, cannot delete";
		top--;
	}
};

template<class T>
class queue :public Bag
{
private:
	T* queue;
	int front;
	int rear;
	string lastOp;
public:
	queue(int queuecapacity = 10) :Bag(queuecapacity), front(0), rear(0), lastOp("0")
	{
	}
	~queue()
	{
	}
	bool IsEmpty()
	{
		return front = rear;
	}
	void push(const T& x)
	{
		if (front == (rear + 1) % capacity) //만원이라면 용량 2배로 늘려준다.
		{
			T* newQueue = new T[capacity * 2];
			int start = (front + 1) % capacity;
			if (start < 2)//둘러쌀 필요 없다. 
			{
				copy(queue + start, queue + start + capacity - 1, newQueue);
			}
			else//둘러싸야 한다. 
			{
				copy(queue + start, queue + capacity, newQueue);
				copy(queue, queue + rear + 1, newQueue + capacity - start);
			}
			front = 2 * capacity - 1;
			rear = capacity - 2;
			capacity *= 2;
			delete[]queue;
			queue = newQueue;
		}

		rear = (rear + 1) % capacity;//만원이 아니라면
		queue[rear] = x;
		lastOp = "push";
	}
	void pop()
	{
		if (IsEmpty) throw"Queue is empty. Cannot delete element";
		front = (front + 1) % capacity;
		queue[front].~T();
		lastOp = "pop";
	}

	void m_number()
	{
		if (front <= rear)
		{
			return rear - front;
		}
		else
		{
			return (capacity - (front + 1) + rear + 1);
		}
	}

};