#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
vector<pair<int, int>> graph[1001];
int dist[1001];
int n, m;
int start, arrive;
void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < distance) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = distance + graph[now][i].second;
			if (cost < dist[graph[now][i].first]) {
				dist[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}
	fill(dist, dist + 1001, INF);
	cin >> start >> arrive;
	dijkstra(start);
	cout << dist[arrive];
}
