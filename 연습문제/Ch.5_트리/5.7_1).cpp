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
	virtual pair<K, E>* Get(const K&) const = 0;//������ Ű ���� ���� ������ ������ ��ȯ, ������ 0
	virtual void Insert(const pair<K, E>&) = 0;//���� �����Ҷ� �ߺ��Ǹ� ���ÿ��� ����
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
	//��ȯ�� Ž��
	pair<K, E>* Get(const K& k)  //kŰ�� ���� ���� �̿�Ʈ������ Ž���Ѵ�.(*this)�� �߰��ϸ� ������ ��ȯ, �ƴϸ� 0��ȯ.
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
	//�ݺ��� Ž��
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
		return 0//���� ���� ���
	}
	pair<K, E>* Insert(const pair<K, E>& thePair)//����
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
	pair<K, E>* Delete(const K& k)//����
	{
		TreeNode<pair<K, E>>* p = root, * pp = 0;//k�� ���� ��带 ã�Ƽ� �̵�����. 
		while (p)
		{
			pp = p;
			if (k < p->data.first) p = p->leftChild;
			else if (k > p->data.first)p = p->rightChild;
			else {
				break;
			}
		}
		//p�� ������ �� ���� ������ �Ǿ���. 
		if (p = NULL) throw "Enter the right key number"//�������� ��尡 ����.
		else
		{
			if (p->rightChild == NULL && p->leftChild == Null)//�ڽ��� �ϳ��� ���� ���
			{
				delete p;
				p = NULL;
			}
			else if (p->leftChild == NULL)//�ڽ��� ������ �ϳ��� �ִ� ���(�����ʰ� �÷��� �Ű��ָ� �ȴ�)
			{
				TreeNode<pair<K, E>>* temp = p;//������ �� ���� �ӽ÷� ���,
				p = p->rightChild;//�����ʰ� �Ű��ְ�,
				delete temp;//�ӽ� �����ش�
			}
			else if (p->leftChild == NULL)//�ڽ��� ���ʸ� �ִ� ��쵵 ��������
			{
				TreeNode<pair<K, E>>* temp = p;
				p = p->leftChild;
				delete temp;
			}
			else//�ڽ��� �Ѵ� �ִ� ���(������ ���� ū���� �� ã�Ƽ� �Ű��ְų�, ������ �ڽ��� ���� ���� ���� ã�Ƽ� �÷��ش�.)
			{
				TreeNode<pair<K, E>>* temp = p->rightChild;
				//1. �������� �������� �� ã�Ƽ� ����� ���
				while (temp->leftChild != NULL)
				{
					temp = temp->leftChild;
				}
				p->data = temp->data;
				delete temp;
				//2.���� �� ���� ū ���� ã�Ƽ� ����� ���
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
