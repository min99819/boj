#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000002];
int find_parent(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}
void union_node(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);

    parent[u] = v;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    bool flag = false;
    for(int i=0; i<=n; i++) {
        parent[i] = i;
    }
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(!a) {
            union_node(b, c);
        }
        else {
            b = find_parent(b);
            c = find_parent(c);

            if(b == c) cout << "YES" << '\n';
            else cout << "NO" << '\n'; 
        }
    }
}