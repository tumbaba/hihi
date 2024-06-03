#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;


// 무한대 값 정의
const int INF = numeric_limits<int>::max();

// 그래프의 정의 : 인접 리스트 사용
typedef pair<int, int> Edge;  // (정점, 가중치)
typedef vector<vector<Edge>> Graph;

// 데이크스트라 알고리즘
vector<int> dijkstra(const Graph& graph, int start) {
	int n = graph.size();
	vector<int> dist(n, INF);  // 거리 배열을 무한대로 초기화
	dist[start] = 0;  // 시작 정점의 거리는 0

	              //priority_queue : 우선순위 큐
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.push({ 0, start });  // (거리, 정점) // (거리,정점)

	while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 이미 처리된 정점은 무시
        if (current_dist > dist[u]) {
            continue;
        }

        // 인접 정점들을 탐색
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            // 최단 경로를 발견하면 업데이트
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}



int main()
{
	// 정점의 개수와 간선의 개수 입력
	int V, E;
	cout << "정점의 개수와 간선의 개수를 입력하세요";
	cin >> V >> E;

	Graph graph(V);

	cout << "간선을 입력하세요 (출발 정점, 도착 정점, 가중치):" << endl;
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);  // 무방향 그래프일 경우 주석 해제
	}

	int start;
	cout << "시작 정점을 입력하세요 : ";
	cin >> start;

	vector<int> distances = dijkstra(graph, start);

	cout << "정점" << start << "로부터의 최단 거리 : " << endl;
	for (int i = 0; i < distances.size(); ++i)
	{
		if (distances[i] == INF)
		{
			cout << "정점 " << i << ": INF" << endl;
		}
		else
		{
			cout << "정점" << i << " : " << distances[i] << endl;
		}
			
	}
	return 0;
}





