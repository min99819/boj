#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
vector<int> graph[10002];
vector<int> res_d;
vector<int> res_b;
bool visit[1002];
void dfs(int n) {
	visit[n] = true;
	res_d.push_back(n);

	for (int i = 0; i < graph[n].size(); i++) {
		if (!visit[graph[n][i]]) {
			dfs(graph[n][i]);
		}
	}
}
void bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		res_b.push_back(x);

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visit[graph[x][i]]) {
				q.push(graph[x][i]);
				visit[graph[x][i]] = true;
			}
		}
	}
}
int main() {
	int n, m, v;
	cin >> n >> m >> v;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(v);
	memset(visit, false, sizeof(visit));
	bfs(v);
	for (int i = 0; i < res_d.size(); i++) {
		cout << res_d[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < res_b.size(); i++) {
		cout << res_b[i] << " ";
	}
}