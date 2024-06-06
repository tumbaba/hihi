#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// 위상 정렬 함수
vector<int> topologicalSort(int n, vector<vector<int>>& adj)
{
	vector<int> inDegree(n, 0);  // 각 노드의 진입차수
	vector<int> result;

	// 각 노드의 진입 차수를 계산
	for (int i = 0; i < n; ++i)
	{
		for (int j : adj[i])
		{
			inDegree[j]++;
		}
	}

	// 진입 차수가 0인 노드를 큐에 삽입
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	// 위상 정렬 수행
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		result.push_back(node);

		// 해당 노드와 연결된 노드들의 진입 차수를 감수
		for (int neighbor : adj[node])
		{
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0)
			{
				q.push(neighbor);
			}
		}
	}

	// 위상 정렬 결과의 크기가 n과 다르면 그래프에 사이클이 있는것
	if (result.size() != n)
	{
		return {}; // 사이클이 존재하면 빈 벡터 반환
	}

	return result;
}


int main()
{
	int n = 6; // 노드의 개수
	vector<vector<int>> adj(n);

	// 그래프의 간선을 추가
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	vector<int> result = topologicalSort(n, adj);

	if (result.empty())
	{
		cout << "그래프에 사이클이 존재합니다." << endl;
	}
	else
	{
		cout << "위상 정렬 결과 : ";
		for (int node : result)
		{
			cout << node << " ";
		}
		cout << endl;
	}

	return 0;
}


















