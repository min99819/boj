#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char map[600][600];
bool visit[600][600];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1,1 };
queue<pair<int, int>> q;
int cnt = 0;
int n, m;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == 'X') continue;
			if (visit[nx][ny] == true) continue;
			visit[nx][ny] = true;
			q.push({ nx,ny });
			if (map[nx][ny] == 'P') cnt++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				q.push({ i,j });
			}
		}
	}
	bfs();
	if (cnt == 0) {
		cout << "TT";
	}
	else cout << cnt;
}