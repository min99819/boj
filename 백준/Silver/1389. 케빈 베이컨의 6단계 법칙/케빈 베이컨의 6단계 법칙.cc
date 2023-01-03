#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int n, m;
int relation[101][101] = { 0 };
int a[101] = { 0 };
int min_cnt = 10000;
void bfs(int start) {
	fill_n(a, 101, 0);
	q.push(start);
	a[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (relation[x][i] == 1 && a[i] == 0) {
				a[i] = a[x] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		relation[a][b] = 1;
		relation[b][a] = 1;
	}
	int ans;
	for (int i = 1; i <= n; i++) {
		bfs(i);
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) cnt += (a[j] - 1);
		}
		//cout << cnt << endl;
		if (cnt < min_cnt) {
			min_cnt = cnt;
			ans = i;
		}
	}
	cout << ans;
}