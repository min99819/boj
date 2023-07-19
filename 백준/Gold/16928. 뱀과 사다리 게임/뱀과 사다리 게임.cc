#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
map<int, int> moving;
int n, m;
queue<pair<int, int>> q;
int cmp[101];
void bfs() {
	q.push({ 1,0 });
	cmp[1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100) continue;
			else {
				if (moving[nx] != 0) {
					nx = moving[nx];
				}
				if (cmp[nx] > cnt) {
					cmp[nx] = cnt;
					q.push({ nx, cnt+1 });
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < n + m; i++) {
		cin >> u >> v;
		moving[u] = v;
	}
	for (int i = 1; i <= 100; i++) {
		cmp[i] = 100;
	}
	bfs();
	cout << cmp[100] + 1;
}
