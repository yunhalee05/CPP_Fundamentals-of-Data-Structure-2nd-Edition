#include<iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class Tree
{
private:
	stack<TreeNode<T>*> s;
	TreeNode<T>* currentNode;

public:
	Tree()
	{
		currentNode = root;
	}

	while (1)
	{
		while (currentNode)
		{
			s.push(currentNode);
			currentNode = currentNode->leftchild;

		}

		if (s.isempty())return;
		currentNode = s.top();
		s.pop();
		currentNode = currentNode->rightchild;
		Visit(currentNode);

	}
};