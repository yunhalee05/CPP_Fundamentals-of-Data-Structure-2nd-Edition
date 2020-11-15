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
	void BFS(int v)
	{
		fill(visited, visited + n, false);
		queue<int>q;
		q.push(v);
		visited[v] = true;
		while (!q.empty())
		{
			v = q.front();
			q.pop();
			vector<int>::const_iterator next;
			for (next = adj[v].begin(); next != adj[v].end(); next++)
			{
				if (visited[*next] == false)
				{
					q.push(*next);
					visited[*next] = true;
				}
			}
		}
		delete[]visited;
	}

};