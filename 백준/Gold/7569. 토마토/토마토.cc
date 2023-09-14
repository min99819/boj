#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int map[101][101][101];
bool visit[101][101][101];
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
queue<tuple<int, int, int>> q;
int n, m, h;
void bfs() {
    while (!q.empty()) {
        int x = get<2>(q.front());
        int y = get<1>(q.front());
        int z = get<0>(q.front());
        visit[z][y][x] = true;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
            if (map[nz][ny][nx] != 0) continue;
            if (visit[nz][ny][nx] == true) continue;
            visit[nz][ny][nx] = true;
            map[nz][ny][nx] = map[z][y][x] + 1;
            q.push({ nz,ny,nx });
        }
    }
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                if (map[i][j][k] == 1) {
                    q.push({ i,j,k });
                }
            }
        }
    }
    bfs();
    int max = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }

                if (map[i][j][k] >= max) {
                    max = map[i][j][k];
                }
            }
        }
    }
    cout << max - 1;
}
