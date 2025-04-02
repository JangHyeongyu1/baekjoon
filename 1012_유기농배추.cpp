#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> cabbage;
vector<vector<bool>> visited;
//vector<vector<int>> worm;
int T, M, N, K;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void DFS(int x,int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			if (!visited[nx][ny] && cabbage[nx][ny]) {
				DFS(nx, ny);
			}
	}
	
}

int main() {

	cin >> T;
	vector<int> ans(T, 0);
	int ans_index = 0;

	while (T--) {
		cin >> M >> N >> K;
		cabbage.assign(M, vector<bool>(N, 0));
		visited.assign(M, vector<bool>(N, false));  
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			cabbage[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && cabbage[i][j]) {
					DFS(i, j);
					ans[ans_index]++;
				}
			}
		}
		ans_index++;
	}

	for (int i = 0; i < ans_index; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}