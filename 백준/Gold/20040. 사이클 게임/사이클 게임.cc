#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[500001];
int parent[500001];
int find_parent(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}
bool union_node(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);

    if(u == v) return false;
    else {
        parent[u] = v;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool flag = false;
    int ans;
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(!union_node(a, b)) {
            ans = i+1;
            flag = true;
            break;
        }
    }
    if(!flag) cout << 0;
    else cout << ans;
}