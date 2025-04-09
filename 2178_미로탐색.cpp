#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void BFS(int start_x, int start_y) {
	visited[start_x][start_y] = true;
	q.push(make_pair(start_x, start_y)); //명시적 pair
	dist[start_x][start_y] = 1; // Start from 1 to count the starting point

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M) {
				if (maze[new_x][new_y] == 1 && !visited[new_x][new_y]) {
					visited[new_x][new_y] = true;
					q.push({ new_x, new_y }); //암시적 pair, 다음 방문할 노드
					dist[new_x][new_y] = dist[x][y] + 1; // Update distance
				}
			}
		}
	}
}

int main(){
	cin >> N >> M;
	
	maze.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M, false));
	dist.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			maze[i][j] = line[j] - '0'; // Convert character to integer
		}
	}
	BFS(0, 0);

	cout << dist[N - 1][M - 1]; // Output the distance to the bottom-right corner

	return 0;
}