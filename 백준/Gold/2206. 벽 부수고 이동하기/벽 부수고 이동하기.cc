#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[1001][1001];
int dist[1001][1001][2];
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
                if(map[nx][ny] == 1 && !flag) {
                    q.push({{nx, ny}, 1});
                    dist[nx][ny][1] = dist[cx][cy][flag] + 1;
                }
                else if(map[nx][ny] == 0 && !dist[nx][ny][flag]) {
                    q.push({{nx, ny}, flag});
                    dist[nx][ny][flag] = dist[cx][cy][flag] + 1;
                }
            }
        }
    }
    if(dist[n-1][m-1][0] == 0 && dist[n-1][m-1][1] == 0) return -1;
    else if(dist[n-1][m-1][0] == 0) return dist[n-1][m-1][1];
    else if (dist[n-1][m-1][1] == 0) return dist[n-1][m-1][0];
    else return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    cout << bfs(0, 0);
}