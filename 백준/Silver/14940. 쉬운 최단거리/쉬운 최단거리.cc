#include <iostream>
#include <queue>
using namespace std;
int map[1000][1000];
int dist[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0, 1 , -1 };
queue<pair<int,int>> q;
int n, m;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;
            if (map[nx][ny] == 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx,ny });
        }
    }
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                q.push({ i,j });
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << 0 << ' ';
            }
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
