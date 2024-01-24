#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v, e;
int parent[10001];
bool flag = false;
vector<pair<int, pair<int, int>>> graph;
int find_parent(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}
void union_node(int x, int y) {
    flag = false;
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) {
        parent[x] = y;
        flag = true;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c,{a,b}});
    }
    sort(graph.begin(), graph.end());
    for(int i=1; i<=v; i++) {
        parent[i] = i;
    }
    for(int i=0; i<e; i++) {
        union_node(graph[i].second.first, graph[i].second.second);

        if(flag) {
            ans += graph[i].first;
        }
    }
    cout << ans;
}