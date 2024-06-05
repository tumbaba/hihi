#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// 프림 알고리즘은 하나의 정점에서 시작하여 인접한 정점으로 나아가면서 최소 비용의 간선을 선택해
// MST를 확장합니다. 우선순위 큐를 사용하영 구현할 수 있다.

typedef pair<int, int> iPair;


class Graph
{
public:
	int V;                                       // 그래프의 정점 수
	vector<vector<iPair>> adj;                   // 인접 리스트로 그래프 표현
	Graph(int V);                                // 생성자
	void addEdge(int u, int v, int w);           // 간선을 추가하는 함수
	void PrimMST();                              // 프림 알고리즘을 수행하는 함수
};

Graph::Graph(int V)
{
	this->V = V;                                  // 정점 수 초기화
	adj.resize(V);                                // 인접 리스트 크기 조정
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));           // 정점 u 에서 v로 가는 가중치 w의 간선추가
	adj[v].push_back(make_pair(u, w));           // 무방향 그래프이므로 정점 v에서 u로 가는 간선도 추가
}

void Graph::PrimMST()
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // 최소 힙을 위한 우선순위 큐
	int src = 0;                               // 시작 정정(보통 0번 정점에서 시작)
	vector<int> key(V, INT_MAX);               // 모든 정점의 키 값을 무한대로 초기화
	vector<int> parent(V, -1);                 // MST를 저장할 부모 배열
	vector<bool> inMST(V, false);              // 정점이 MST에 포함되었는지 여부를 나타내는 배열
	
	pq.push(make_pair(0, src));                // 시작 정점의 키 값은  0, 우선순위 큐에 삽입
	key[src] = 0;                              // 시작 정점의 키밧을 0으로 설정

	while (!pq.empty())                        // 우선순위 큐가 빌 때 까지 반복
	{                                      
		int u = pq.top().second;               // 키 값이 가장 작은 정점을 선택
		pq.pop();                              // 선택된 정점을 큐에서 제거
		inMST[u] = true;                       // 선택된 정점을 MST에 포함
		for (auto x : adj[u])
		{                                      // 선택된 정점의 모든 인접 정점들을 검사
			int v = x.first;                   // 인접 정점
			int weight = x.second;             // 인접 정점과의 간선 가중치

			// 인접 정점이 MST에 포함되지 않고, 간선 가중치가 현재 키 값보다 작다면
			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;  // 키값을 갱신
				pq.push(make_pair(key[v], v));; // 갱신된 키 값으로 우선순위 큐에 삽입
				parent[v] = u;  // 부모 정점을 갱신
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


// kruskal's 알고리즘 은 간선을 정렬하고 Union-find자료구조를 사용하는 반면 Prim's 알고리즘은 
// 우선순위 큐를 사용하여 구현된다.