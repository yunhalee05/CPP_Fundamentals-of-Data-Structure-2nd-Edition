#include <iostream>
#include <algorithm>
#include <vector>
#include<stack>


using namespace std;

template<class T>
class stack
{
private:
	T* stack;
	T* newstack;
	int top;
	int capacity;
	int newcapacity;
public:
	stack(int stackcapacity = 10) : capacity(stackcapacity)
	{
		if (capacity < 1) throw "stack capacity must be" > 0;
		if (newcapacity < 1) throw "newstack capacity must be" > 0;

		stack = new T[capacity];
		newstack = new T[newcapacity];
		top = -1;
	}
	~stack()
	{
		delete[]stack;
		delete[]newstack;

	}
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << stack[i];
		}
	}
	void devide()
	{
		newcapacity = capacity - capacity / 2;

		for (int i = 0; i < newcapacity; i++)
		{
			newstack[i] = stack[i + (capacity / 2)];
			stack[top--].~T();
		}
		ChangeSizeID(stack, capacity, capacity / 2);
		capacity /= 2;


	}
	void add(const T&* newstack)
	{
		ChangeSizeID(stack, capacity, 2 * capacity);
		capacity *= 2;
		for (int i = 0; i < newcapacity; i++)
		{
			stack[++top] = newstack[i];
		}

	}