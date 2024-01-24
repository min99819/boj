#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int cnt = 0;
int ans = 0;
int visited[100001];
bool finished[100001];
void dfs(vector<int> &v, int x) {
    visited[x] = ++cnt;
    if(visited[v[x]] == -1) {
        dfs(v, v[x]);
    }
    else if(!finished[v[x]]) {
        ans += visited[x] - visited[v[x]] + 1;
    }
    finished[x] = true;
}
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        cnt = 0;
        ans = 0;
        cin >> n;
        memset(visited, -1, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        vector<int> v(n + 1);
        for(int j=1; j<=n; j++) {
            int choice;
            cin >> choice;
            v[j] = choice;
        }
        for(int j=1; j<=n; j++) {
            if(!finished[j]) {
                dfs(v, j);
            }
        }
        cout << n-ans << '\n';
    }
}