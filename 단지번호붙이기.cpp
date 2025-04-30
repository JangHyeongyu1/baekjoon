#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> house;
vector<vector<bool>> visited;
vector<int> result;
int N;
int streetnum = 1;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

int DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			if (!visited[nx][ny] && house[nx][ny]) {
				DFS(nx, ny);
				result[streetnum]++;
			}
			else if (!visited[nx][ny] && !house[nx][ny]) {
				DFS(nx, ny);
				streetnum++;
			}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < N; j++) {
			house[i][j] = line[j] - '0';
		}
	}
	DFS(0, 0);

	cout << streetnum << endl;;
	for (int i = 1; i <= streetnum; i++) {
		cout << result[streetnum] << endl;
	}

	return 0;
}
