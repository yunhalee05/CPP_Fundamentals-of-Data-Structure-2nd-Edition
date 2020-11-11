#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include <string>


using namespace std;

template<class T>
class queue
{
private:
	T* queue;
	int front;
	int rear;
	int capacity;
	string lastOp;
public:
	queue(int queuecapacity = 10) :capacity(queuecapacity)
	{
		if (capacity < 1) throw "Queue capacity must be" > 0;
		queue = new T[capacity];
		front = rear = 0;
		lastOp = "0";
	}
	~queue()
	{
		delete[] queue;
	}
	bool IsEmpty()
	{
		return front = rear;
	}
	void push(const T& x)
	{
		if (front == (rear + 1) % capacity) //�����̶�� �뷮 2��� �÷��ش�.
		{
			T* newQueue = new T[capacity * 2];
			int start = (front + 1) % capacity;
			if (start < 2)//�ѷ��� �ʿ� ����. 
			{
				copy(queue + start, queue + start + capacity - 1, newQueue);
			}
			else//�ѷ��ξ� �Ѵ�. 
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

		rear = (rear + 1) % capacity;//������ �ƴ϶��
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

};