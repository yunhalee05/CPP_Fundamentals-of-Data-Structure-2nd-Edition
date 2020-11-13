#include<iostream>
#include <stack>
#include <queue>

using namespace std;

template <class T>
class TreeNode
{

};
template<class K, class E>
class Dictionary
{
public:
	virtual ~Dictionary() {}
	virtual pair<K, E>* Get(const K&) const = 0;//지시한 키 값의 쌍이 있으면 포인터 반환, 없으면 0
	virtual void Insert(const pair<K, E>&) = 0;//쌍을 삽일할때 중복되면 관련원소 갱신
	virtual void Delete(const K&) = 0;

};
template<class T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
};

template<class K, class E>
class BST : public Dictionary <K, E>
{
private:
	TreeNode<pair <K, E>>* root;
public:
	BST()
	{
		root = 0;
	}
	//순환적 탐색
	pair<K, E>* Get(const K& k)  //k키를 가진 쌍을 이원트리에서 탐색한다.(*this)쌍 발견하면 포인터 반환, 아니면 0반환.
	{
		return Get(root, k)
	}
	pair<K, E>* Get(TreeNode<pair<K, E >>* p, const K& k)
	{
		if (!p) return 0;
		if (k < p->data.first)return Get(p->leftChild, k);
		if (k > p->data.first)return Get(p->rightChild, k);
		return &p->data;
	}
	//반복적 탐색
	pair<K, E>* Get(const K& k)
	{
		TreeNode<pair<K, E>>* currentNode = root;
		while (currentNode)
		{
			if (k < currentNode->data.first)
			{
				currentNode = currentNode->leftChild;
			}
			else if (k > currentNode->data.first)
			{
				currentNode = currentNode->rightChild;
			}
			else return &currentNode->data;
		}
		return 0//쌍이 없는 경우
	}
	pair<K, E>* Insert(const pair<K, E>& thePair)//삽입
	{
		TreeNode<pair<K, E>>* p = root, * pp = 0;
		while (p)
		{
			pp = p;
			if (thePair.first < p->data.first) p = p->leftChild;
			else if (thePair.first > p->data.first)p = p->rightChild;
			else {
				p->data.second = thePair.second;
				return;
			}
		}
		p = new TreeNode<pair<K, E>>(thePair);
		if (root)
		{
			if (thePair.first < pp->data.first)pp->leftChild = p;
			else pp->rightChild = p;
		}
		else root = p;

	}
	pair<K, E>* Delete(const K& k)//삭제
	{
		TreeNode<pair<K, E>>* p = root, * pp = 0;//k를 가진 노드를 찾아서 이동하자. 
		while (p)
		{
			pp = p;
			if (k < p->data.first) p = p->leftChild;
			else if (k > p->data.first)p = p->rightChild;
			else {
				break;
			}
		}
		//p가 지워야 할 노드로 설정이 되었다. 
		if (p = NULL) throw "Enter the right key number"//지워야할 노드가 없다.
		else
		{
			if (p->rightChild == NULL && p->leftChild == Null)//자식이 하나도 없는 경우
			{
				delete p;
				p = NULL;
			}
			else if (p->leftChild == NULL)//자식이 오른쪽 하나만 있는 경우(오른쪽거 올려서 옮겨주면 된다)
			{
				TreeNode<pair<K, E>>* temp = p;//지워야 할 것을 임시로 담고,
				p = p->rightChild;//오른쪽거 옮겨주고,
				delete temp;//임시 지워준다
			}
			else if (p->leftChild == NULL)//자식이 왼쪽만 있는 경우도 마찬가지
			{
				TreeNode<pair<K, E>>* temp = p;
				p = p->leftChild;
				delete temp;
			}
			else//자식이 둘다 있는 경우(왼쪽중 가장 큰값을 를 찾아서 옮겨주거나, 오른쪽 자식중 가장 작은 값을 찾아서 올려준다.)
			{
				TreeNode<pair<K, E>>* temp = p->rightChild;
				//1. 오른쪽중 가장작은 값 찾아서 지우는 방법
				while (temp->leftChild != NULL)
				{
					temp = temp->leftChild;
				}
				p->data = temp->data;
				delete temp;
				//2.왼쪽 중 가장 큰 값을 찾아서 지우는 방법
				TreeNode<pair<K, E>>* temp = p->leftChild;
				while (temp->rightChild != NULL)
				{
					temp = temp->rightChild;
				}
				p->data = temp->data;
				delete temp;
			}
		}

	}

};
