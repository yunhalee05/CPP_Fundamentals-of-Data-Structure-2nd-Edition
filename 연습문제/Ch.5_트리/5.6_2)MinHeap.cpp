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
		heap = new T[capacity + 1];//heap[0]은 사용되지 않음.
	}
	void Push(const T& e)//삽입
	{
		if (heapSize == capacity)//자리가 없으면 용량 늘려준다.
		{
			ChangeSizeID(heap, capacity, 2 * capacity);
			capacity *= 2;
		}
		int currentNode = ++heapSize;
		while (currentNode != 1 && heap[currentNode / 2] > e)//삽입하려는게 부모노드보다 더 작은 수라면 아래에서 위로 올라가는 구조, 위치 바꿔준다.
		{
			heap[currentNode] = heap[currentNode / 2];//부모노드로 이동
			currentNode /= 2;
		}
		heap[currentNode] = e;//자기보다 작지 않은 부모 있을 때까지 올라가서 넣어준다.
	}
	void Pop()
	{
		if (IsEmpty())throw"Heap is empty. Cannot delete";//힙이 비어있으면 제거할 수 없다.

		heap[1].~T;//최소 원소 삭제
		T lastE = heap[heapSize--];//마지막원소 삭제

		int currentNode = 1;//삭제를 위해서는 위에서 아래로 내려가는 구조
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] > heap[child + 1]) child++;//맨 위보다 작은 값이 있으면 점점 내려간다. 
			if (lastE <= heap[child])break; //맞는 노드를 찾으면 아웃

			//아니라면 계속
			heap[currentNode] = heap[child];//자식으로 이동
			currentNode = child;
			child *= 2;//한레벨 내려간다.
		}
		heap[currentNode] = lastE;//맞는 자리에 마지막원소 이동.

	}
};
