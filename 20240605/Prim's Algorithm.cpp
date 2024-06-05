#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// ���� �˰����� �ϳ��� �������� �����Ͽ� ������ �������� ���ư��鼭 �ּ� ����� ������ ������
// MST�� Ȯ���մϴ�. �켱���� ť�� ����Ͽ� ������ �� �ִ�.

typedef pair<int, int> iPair;


class Graph
{
public:
	int V;                                       // �׷����� ���� ��
	vector<vector<iPair>> adj;                   // ���� ����Ʈ�� �׷��� ǥ��
	Graph(int V);                                // ������
	void addEdge(int u, int v, int w);           // ������ �߰��ϴ� �Լ�
	void PrimMST();                              // ���� �˰����� �����ϴ� �Լ�
};

Graph::Graph(int V)
{
	this->V = V;                                  // ���� �� �ʱ�ȭ
	adj.resize(V);                                // ���� ����Ʈ ũ�� ����
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));           // ���� u ���� v�� ���� ����ġ w�� �����߰�
	adj[v].push_back(make_pair(u, w));           // ������ �׷����̹Ƿ� ���� v���� u�� ���� ������ �߰�
}

void Graph::PrimMST()
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // �ּ� ���� ���� �켱���� ť
	int src = 0;                               // ���� ����(���� 0�� �������� ����)
	vector<int> key(V, INT_MAX);               // ��� ������ Ű ���� ���Ѵ�� �ʱ�ȭ
	vector<int> parent(V, -1);                 // MST�� ������ �θ� �迭
	vector<bool> inMST(V, false);              // ������ MST�� ���ԵǾ����� ���θ� ��Ÿ���� �迭
	
	pq.push(make_pair(0, src));                // ���� ������ Ű ����  0, �켱���� ť�� ����
	key[src] = 0;                              // ���� ������ Ű���� 0���� ����

	while (!pq.empty())                        // �켱���� ť�� �� �� ���� �ݺ�
	{                                      
		int u = pq.top().second;               // Ű ���� ���� ���� ������ ����
		pq.pop();                              // ���õ� ������ ť���� ����
		inMST[u] = true;                       // ���õ� ������ MST�� ����
		for (auto x : adj[u])
		{                                      // ���õ� ������ ��� ���� �������� �˻�
			int v = x.first;                   // ���� ����
			int weight = x.second;             // ���� �������� ���� ����ġ

			// ���� ������ MST�� ���Ե��� �ʰ�, ���� ����ġ�� ���� Ű ������ �۴ٸ�
			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;  // Ű���� ����
				pq.push(make_pair(key[v], v));; // ���ŵ� Ű ������ �켱���� ť�� ����
				parent[v] = u;  // �θ� ������ ����
			}
		}
	}
	cout << "Following are the edges in the constructed MST \n";
	for (int i = 1; i < V; ++i)
	{
		cout << parent[i] << " - " << i << "\t" << key[i] << " \n";
	}

}



int main()
{
	int V = 9;
	Graph g(V);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	g.PrimMST();


	return 0;
}


// kruskal's �˰��� �� ������ �����ϰ� Union-find�ڷᱸ���� ����ϴ� �ݸ� Prim's �˰����� 
// �켱���� ť�� ����Ͽ� �����ȴ�.