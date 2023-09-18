#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char map[101][101];
char RG_map[101][101];
bool visit[101][101];
bool RG_visit[101][101];
int n;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ans = 1, RG_ans = 1;
void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[x][y] != map[nx][ny]) continue;
			if (visit[nx][ny] == true) continue;
			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}
void RG_bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	RG_visit[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		RG_visit[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (RG_map[x][y] != RG_map[nx][ny]) continue;
			if (RG_visit[nx][ny] == true) continue;
			q.push({ nx,ny });
			RG_visit[nx][ny] = true;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
			if (s[j] == 'G') RG_map[i][j] = 'R';
			else RG_map[i][j] = s[j];
		}
	}
	bfs(0, 0);
	RG_bfs(0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				ans++;
				bfs(i, j);
			}
			if (RG_visit[i][j] == false) {
				RG_ans++;
				RG_bfs(i, j);
			}
		}
	}
	cout << ans << " " << RG_ans;
}