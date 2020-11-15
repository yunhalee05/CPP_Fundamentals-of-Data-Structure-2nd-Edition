#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int node, int parent[])//부모찾기
{
	if (parent[node] == node)
	{
		return node;
	}
	else parent[node] = getParent(parent[node], parent);
}
int UnionParent(int a, int b, int parent[])//부모병합
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
int Find(int parent[], int a, int b)//같은 부모 가지는지 확인하기
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

	int node[2];//서로다른 두개의 노드정보가 담길 것이다
	int distance;//가중치

	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;

	}
	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;//거리가 작은 것이 리턴되도록 해준다.
	}

};
int main()
{
	int n; // 노드입력받는다.
	int m;//간선 입력받는다.

	vector<Edge> v;
	v.push_back(Edge(출발점, 도착점, 가중치));//계속해서 입력해준다.
	//...

	sort(v.begin(), v.end());//가중치 기준으로 정렬한다. 
	//각정점이 포함된 그래프가 어디인지 저장하자.
	int parent[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i; //기본적으로 자신이 자신의 부모라고 저장해놓는다. 
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)//모든 간선에 대해서 사이클이 발생하지 않는 경우 그래프에 포함.
	{
		if (!Find(parent, v[i].node[0] - 1, v[i].node[1] - 1))//간선에서의 첫번째 노드와 두번째 노드가 연결이 안되어 있는 상태, 즉 사이클이 발생하지 않는 경우
		{
			sum += v[i].distance;//합산에 추가하고 
			UnionParent(v[i].node[0] - 1, v[i].node[1] - 1, parent);//두개의 노드를 연결해준다. 

		}
	}

}