#include <iostream>
#include <queue>
using namespace std;
int map[1000][1000];
bool visit[1000][1000];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0 , 0, 1 , -1 };
queue<pair<int,int>> q;
int n, m;
void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        visit[x][y] = true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (map[nx][ny] != 0) continue;
            if (visit[nx][ny] == true) continue;
            visit[nx][ny] = true;
            map[nx][ny] = map[x][y] + 1;
            q.push({ nx,ny });
        }
    }
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                q.push({ i,j });
            }
        }
    }
    bfs();
    int max = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                cout << -1;
                return 0;
            }

            if (map[i][j] >= max) {
                max = map[i][j];
            }
        }
    }
    cout << max - 1;
}
