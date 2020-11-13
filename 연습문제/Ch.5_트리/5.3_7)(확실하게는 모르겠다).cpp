#include<iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class PreorderIterator
{
private:
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode;

public:
	PreorderIterator()
	{
		currentNode = root;
	}

	T* Next()
	{
		while (currentNode)
		{
			T& temp = currentNode->data;
			s.push(currentNode);
			currentNode = currentNode->leftchild;
			return &temp;

		}

		if (s.isempty())return;
		currentNode = s.top();
		s.pop();
		currentNode = currentNode->rightchild;
	}
};
