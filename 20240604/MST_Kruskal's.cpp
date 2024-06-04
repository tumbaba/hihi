#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Kruskal's Algorithm
// 간선을 비용에 따라 정렬한 후, 사이클을 만들지 않도록 간선을 추가해 나가는 방식
// 이를 위해 



class Edge
{
public:
	int src, dest, weight;
	Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph
{
public:
	int V, E;
	vector<Edge> edges;
	Graph(int V, int E) : V(V), E(E) {}
	void addEdge(int src, int dest, int weight)
	{
		edges.push_back(Edge(src, dest, weight));
	}
	int find(vector<int>& parent, int i);
	void Union(vector<int>& parent, vector<int>& rank, int x, int y);
	void KruskalMST();
};

int Graph::find(vector<int>& parent, int i)
{
	if (parent[i] != i)
	{
		parent[i] = find(parent, parent[i]);
	}
	return parent[i];
}
void Graph::Union(vector<int>& parent, vector<int>& rank, int x, int y)
{
	int xroot = find(parent, x);
	int yroot = find(parent, y);
	if (rank[xroot] < rank[yroot])
	{
		parent[xroot] = yroot;
	}
	else if (rank[xroot] > rank[yroot])
	{
		parent[yroot] = xroot;
	}
	else
	{
		parent[yroot] = xroot;
		rank[xroot]++;
	}
}

void Graph::KruskalMST()
{
	vector<Edge> result;
	int e = 0;
	int i = 0;
	sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
		return a.weight < b.weight;
		});
	vector<int> parent(V);
	vector<int> rank(V, 0);
	for (int v = 0; v < V; v++)
	{
		parent[v] = v;
	}
	while (e < V - 1 && i < E)
	{
		Edge next_edge = edges[i++];
		int x = find(parent, next_edge.src);
		int y = find(parent, next_edge.dest);
		if (x != y)
		{
			result.push_back(next_edge);
			Union(parent, rank, x, y);
			e++;
		}
	}
	cout << "Following are the edges in the constructed MST\n";
	for (auto edge : result)
		cout << edge.src << " -- " << edge.dest << " -- " << edge.weight << endl;
}


int main()
{
	int V = 4;
	int E = 5;
	Graph g(V, E);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 2, 6);
	g.addEdge(0, 3, 5);
	g.addEdge(1, 3, 15);
	g.addEdge(2, 3, 4);

	g.KruskalMST();




	return 0;
}