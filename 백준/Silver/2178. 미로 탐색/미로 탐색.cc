#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[101][101];
int visit[101][101];
int dist[101][101];
int dx[4] = { -1, 0, 1,0 };
int dy[4] = { 0, -1, 0, 1 };
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	dist[x][y]++;
	visit[x][y] = 1;

	while (!q.empty()) {
		int new_x = q.front().first;
		int new_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = new_x + dx[i];
			int ny = new_y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (map[nx][ny] == 1 && visit[nx][ny] == 0) {
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[new_x][new_y] + 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j] - '0';
		}
	}
	bfs(0, 0);
	cout << dist[n - 1][m - 1];
}