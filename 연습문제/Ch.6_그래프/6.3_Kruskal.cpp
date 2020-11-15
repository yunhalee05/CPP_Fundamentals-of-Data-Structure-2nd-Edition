#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int node, int parent[])//�θ�ã��
{
	if (parent[node] == node)
	{
		return node;
	}
	else parent[node] = getParent(parent[node], parent);
}
int UnionParent(int a, int b, int parent[])//�θ���
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}
int Find(int parent[], int a, int b)//���� �θ� �������� Ȯ���ϱ�
{
	a = getParent(a, parent);
	b = getParent(b, parent);
	if (a == b)
	{
		return 1;
	}
	else return 0;

}

class Edge
{
public:

	int node[2];//���δٸ� �ΰ��� ��������� ��� ���̴�
	int distance;//����ġ

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;

	}
	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;//�Ÿ��� ���� ���� ���ϵǵ��� ���ش�.
	}

};
int main()
{
	int n; // ����Է¹޴´�.
	int m;//���� �Է¹޴´�.

	vector<Edge> v;
	v.push_back(Edge(�����, ������, ����ġ));//����ؼ� �Է����ش�.
	//...

	sort(v.begin(), v.end());//����ġ �������� �����Ѵ�. 
	//�������� ���Ե� �׷����� ������� ��������.
	int parent[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i; //�⺻������ �ڽ��� �ڽ��� �θ��� �����س��´�. 
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)//��� ������ ���ؼ� ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����.
	{
		if (!Find(parent, v[i].node[0] - 1, v[i].node[1] - 1))//���������� ù��° ���� �ι�° ��尡 ������ �ȵǾ� �ִ� ����, �� ����Ŭ�� �߻����� �ʴ� ���
		{
			sum += v[i].distance;//�ջ꿡 �߰��ϰ� 
			UnionParent(v[i].node[0] - 1, v[i].node[1] - 1, parent);//�ΰ��� ��带 �������ش�. 

		}
	}

}