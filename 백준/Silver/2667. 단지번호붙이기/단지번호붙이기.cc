#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
queue<pair<int,int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n;
char map[26][26];
bool visit[26][26];
int cnt = 0;
vector<int> ans;
void bfs(int sx, int sy) {
	q.push({ sx, sy });
	visit[sx][sy] = true;
	cnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (map[nx][ny] == '1' && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	ans.push_back(cnt);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string house;
		cin >> house;
		for (int j = 0; j < n; j++) {
			map[i][j] = house[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visit[i][j] == false) {
				cnt = 0;
				bfs(i, j);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}