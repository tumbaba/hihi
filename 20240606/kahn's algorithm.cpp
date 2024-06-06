#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// ���� ���� �Լ�
vector<int> topologicalSort(int n, vector<vector<int>>& adj)
{
	vector<int> inDegree(n, 0);  // �� ����� ��������
	vector<int> result;

	// �� ����� ���� ������ ���
	for (int i = 0; i < n; ++i)
	{
		for (int j : adj[i])
		{
			inDegree[j]++;
		}
	}

	// ���� ������ 0�� ��带 ť�� ����
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}

	// ���� ���� ����
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		result.push_back(node);

		// �ش� ���� ����� ������ ���� ������ ����
		for (int neighbor : adj[node])
		{
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0)
			{
				q.push(neighbor);
			}
		}
	}

	// ���� ���� ����� ũ�Ⱑ n�� �ٸ��� �׷����� ����Ŭ�� �ִ°�
	if (result.size() != n)
	{
		return {}; // ����Ŭ�� �����ϸ� �� ���� ��ȯ
	}

	return result;
}


int main()
{
	int n = 6; // ����� ����
	vector<vector<int>> adj(n);

	// �׷����� ������ �߰�
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);

	vector<int> result = topologicalSort(n, adj);

	if (result.empty())
	{
		cout << "�׷����� ����Ŭ�� �����մϴ�." << endl;
	}
	else
	{
		cout << "���� ���� ��� : ";
		for (int node : result)
		{
			cout << node << " ";
		}
		cout << endl;
	}

	return 0;
}


















