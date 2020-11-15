#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
	int n;//정점의 수
	vector<vector<int>> adj; //인접리스트
	bool* visited;//방문여부 저장
public:
	Graph(int N)
	{
		n = N;
		adj.resize(n);
		visited = new bool[n];
	}
	void InsertEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void DFS()
	{
		fill(visited, visited + n, false);
		DFS(0);
		delete[]visited;
	}
	void DFS(const int v)
	{
		visited[v] = true;
		vector<int>::const_iterator next;
		for (next = adj[v].begin(); next != adj[v].end(); next++)
		{
			if (visited[*next] == false)
			{
				DFS(*next);
			}
		}
	}

};