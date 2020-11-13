#include<iostream>
#include <stack>

using namespace std;

template<class T>
class InorderIterator
{
private:
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode;

public:
	InorderIterator()
	{
		currentNode = root;
	}
	T* Next()
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->leftchild;
		}
		if (s.IsEmpty()) return;
		currentNode = s.top();
		s.pop();
		T& temp = currentNode->data;
		currentNode = currentNode->rightchild;
		return &temp;
	}
};