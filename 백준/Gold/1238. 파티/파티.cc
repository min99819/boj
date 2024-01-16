#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 999999999
using namespace std;
int n, m, x;
vector<pair<int, int> > v[1001];
int shortest_dist[1001];
void initialize() {
    for(int i=0; i<1001; i++) {
        shortest_dist[i] = INF;
    }
}
int dijkstra(int st, int dest) {
    initialize();
    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; 
    pq.push(make_pair(0, st));
    shortest_dist[st] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(now == dest) {
            return shortest_dist[now];
        }
        for(int i=0; i<v[now].size(); i++) {
            int nx = v[now][i].first;
            int next_dist = v[now][i].second + d;
            if(shortest_dist[nx] > next_dist) {
                shortest_dist[nx] = next_dist;
                pq.push(make_pair(next_dist, nx));
            }
        }
    }
    return INF;
}
int main() {
    cin >> n >> m >> x;
    for(int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back(make_pair(b,t));
    }
    int dist_temp;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        dist_temp = dijkstra(i, x) + dijkstra(x, i);
        ans = max(ans, dist_temp);
    }
    cout << ans;
}
