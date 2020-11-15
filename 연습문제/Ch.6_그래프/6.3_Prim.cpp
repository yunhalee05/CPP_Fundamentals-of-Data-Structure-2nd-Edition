#include <vector>
#include <algorithm>//잘 모르겠다

using namespace std;

class Prim
{
private:
	int* visited;
	int node[2];
	int distance;
	int vertexes;
	int edges;
	int sum;
	int now;

public:
	Prim(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	void PrimMST()
	{
		int sum = 0;
		int now = 0;
		visited[0] = true;
		int vertexes;

	}
};
