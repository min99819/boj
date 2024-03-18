#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int n;
int dfs(int cur) {
    if(visited[cur]) return -999999;

    int len = 0;
    visited[cur] = true;

    for(int i=0; i<graph[cur].size(); i++) {
        len = max(len, graph[cur][i].second + dfs(graph[cur][i].first));
    }
    return len;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) visited[j] = false;
        ans = max(ans, dfs(i));
    }
    cout << ans;
}