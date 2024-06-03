#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;


// ���Ѵ� �� ����
const int INF = numeric_limits<int>::max();

// �׷����� ���� : ���� ����Ʈ ���
typedef pair<int, int> Edge;  // (����, ����ġ)
typedef vector<vector<Edge>> Graph;

// ����ũ��Ʈ�� �˰���
vector<int> dijkstra(const Graph& graph, int start) {
	int n = graph.size();
	vector<int> dist(n, INF);  // �Ÿ� �迭�� ���Ѵ�� �ʱ�ȭ
	dist[start] = 0;  // ���� ������ �Ÿ��� 0

	              //priority_queue : �켱���� ť
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.push({ 0, start });  // (�Ÿ�, ����) // (�Ÿ�,����)

	while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // �̹� ó���� ������ ����
        if (current_dist > dist[u]) {
            continue;
        }

        // ���� �������� Ž��
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            // �ִ� ��θ� �߰��ϸ� ������Ʈ
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
	// ������ ������ ������ ���� �Է�
	int V, E;
	cout << "������ ������ ������ ������ �Է��ϼ���";
	cin >> V >> E;

	Graph graph(V);

	cout << "������ �Է��ϼ��� (��� ����, ���� ����, ����ġ):" << endl;
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);  // ������ �׷����� ��� �ּ� ����
	}

	int start;
	cout << "���� ������ �Է��ϼ��� : ";
	cin >> start;

	vector<int> distances = dijkstra(graph, start);

	cout << "����" << start << "�κ����� �ִ� �Ÿ� : " << endl;
	for (int i = 0; i < distances.size(); ++i)
	{
		if (distances[i] == INF)
		{
			cout << "���� " << i << ": INF" << endl;
		}
		else
		{
			cout << "����" << i << " : " << distances[i] << endl;
		}
			
	}
	return 0;
}





