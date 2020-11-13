#include<iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class MinPQ
{
public:
	virtual ~MinPQ() {}
	virtual bool IsEmpty() const = 0;
	virtual const T& Top() const = 0;
	virtual void Push(const T&) = 0;
	virtual void Pop() = 0;
};
template<class T>
class MinHeap : public MinPQ<T>
{
	T* heap;
	int capacity;
	int heapSize;

public:
	MinHeap<T>(int theCapacity = 10) : capacity(theCapacity)
	{
		if (theCapacity < 1)throw "Capacity must be >=1";
		heapSize = 0;
		heap = new T[capacity + 1];//heap[0]�� ������ ����.
	}
	void Push(const T& e)//����
	{
		if (heapSize == capacity)//�ڸ��� ������ �뷮 �÷��ش�.
		{
			ChangeSizeID(heap, capacity, 2 * capacity);
			capacity *= 2;
		}
		int currentNode = ++heapSize;
		while (currentNode != 1 && heap[currentNode / 2] > e)//�����Ϸ��°� �θ��庸�� �� ���� ����� �Ʒ����� ���� �ö󰡴� ����, ��ġ �ٲ��ش�.
		{
			heap[currentNode] = heap[currentNode / 2];//�θ���� �̵�
			currentNode /= 2;
		}
		heap[currentNode] = e;//�ڱ⺸�� ���� ���� �θ� ���� ������ �ö󰡼� �־��ش�.
	}
	void Pop()
	{
		if (IsEmpty())throw"Heap is empty. Cannot delete";//���� ��������� ������ �� ����.

		heap[1].~T;//�ּ� ���� ����
		T lastE = heap[heapSize--];//���������� ����

		int currentNode = 1;//������ ���ؼ��� ������ �Ʒ��� �������� ����
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] > heap[child + 1]) child++;//�� ������ ���� ���� ������ ���� ��������. 
			if (lastE <= heap[child])break; //�´� ��带 ã���� �ƿ�

			//�ƴ϶�� ���
			heap[currentNode] = heap[child];//�ڽ����� �̵�
			currentNode = child;
			child *= 2;//�ѷ��� ��������.
		}
		heap[currentNode] = lastE;//�´� �ڸ��� ���������� �̵�.

	}
};
