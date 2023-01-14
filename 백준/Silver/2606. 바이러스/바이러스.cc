#include <iostream>
using namespace std;
int virus[101][101];
int visit[101];
int n;
int cnt = 0;
void dfs(int x) {
	cnt++;
	visit[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (virus[x][i] && !visit[i]) dfs(i);
	}
}
int main() {
	int m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		virus[a][b] = 1;
		virus[b][a] = 1;
	}
	dfs(1);
	cout << cnt-1;
}