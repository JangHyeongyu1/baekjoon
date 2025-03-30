#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int next : adj[v]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int next : adj[v]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	adj.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[u].push_back(v);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	fill(visited.begin(), visited.end(), false);
	DFS(V);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(V);

	return 0;
}