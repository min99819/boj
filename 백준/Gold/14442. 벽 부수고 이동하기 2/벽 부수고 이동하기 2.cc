#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[1001][1001];
int dist[1001][1001][11];
int bfs(int x, int y) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{0,0},0});
    dist[x][y][0] = 1;

    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int flag = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >=0 && nx < n && ny >= 0 && ny < m) {
                if(map[nx][ny] == 1 && flag < k && !dist[nx][ny][flag+1]) {
                    q.push({{nx, ny}, flag+1});
                    dist[nx][ny][flag+1] = dist[cx][cy][flag] + 1;
                }
                else if(map[nx][ny] == 0 && !dist[nx][ny][flag]) {
                    q.push({{nx, ny}, flag});
                    dist[nx][ny][flag] = dist[cx][cy][flag] + 1;
                }
            }
        }
    }
    int ans = 10000000;
    for(int i=0; i<=k; i++) {
        if(dist[n-1][m-1][i] != 0) {
            ans = min(ans, dist[n-1][m-1][i]);
        }
    }
    return (ans == 10000000) ? -1 : ans;
}
int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    cout << bfs(0, 0);
}