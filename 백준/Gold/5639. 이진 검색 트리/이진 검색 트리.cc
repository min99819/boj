#include <iostream>
using namespace std;
int graph[10001];
void solve(int st, int ed) {
    if(st >= ed) {
        return; 
    }
    int root = graph[st];
    int left_node_idx = st + 1;
    
    while(left_node_idx < ed) {
        if(root < graph[left_node_idx]) break;

        left_node_idx++;
    }
    solve(st+1, left_node_idx);
    solve(left_node_idx, ed);
    cout << root << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int i=0;
    while(cin >> n) {
        graph[i++] = n;
    }
    solve(0, i);
}