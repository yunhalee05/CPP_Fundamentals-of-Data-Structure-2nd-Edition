#include<iostream>
#include <stack>
#include <queue>

using namespace std;

template<class T>
class Tree
{
private:
	queue<TreeNode<T>*> q;
	TreeNode<T>* currentNode;

public:
	Tree()
	{
		currentNode = root;
	}
	void LevelOrder()
	{
		while (currentNode)
		{
			Visit(currentNode);
			if (currentNode->leftchild)q.push(currentNode->leftchild);
			if (currentNode->rightchild)q.push(currentNode->rightchild);
			if (q.isempty()) return;
			currentNode = q.front();
			q.pop();
		}

	}
};
