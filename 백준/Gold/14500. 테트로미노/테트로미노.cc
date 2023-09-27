#include <iostream>
#include <algorithm>
using namespace std;
int map[501][501];
bool visit[501][501];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int ans = 0;
void dfs(int x, int y, int depth, int num) {
	if (depth == 4) {
		if (ans <= num) ans = num;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visit[nx][ny]) continue;
		visit[nx][ny] = true;
		num += map[nx][ny];
		depth++;
		dfs(nx, ny, depth, num);
		depth--;
		num -= map[nx][ny];
		visit[nx][ny] = false;
	}
}
void solve(int x, int y) {
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < m) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]); // ㅗ
	}
	if (x + 1 < n && y - 1 >= 0 && y + 1 < m) {
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]); // ㅜ
	}
	if (x - 1 >= 0 && x + 1 < n && y - 1 >= 0) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]); // ㅓ
	}
	if (x - 1 >= 0 && x + 1 < n && y + 1 >= 0) {
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]); // ㅏ
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			dfs(i, j, 1, map[i][j]);
			solve(i, j);
			visit[i][j] = false;
		}
	}
	cout << ans;
}