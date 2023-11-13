#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21];
int n;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
int dist[21][21];
bool possible_eat = false;
queue<pair<int,int> > q;
int shark_size = 2;
int ans = 0;
int cnt = 0;
int min_dist;
void bfs(int sx, int sy) {
    min_dist = 1000000000;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] > shark_size || dist[nx][ny]) 
                continue;
            else if(map[nx][ny] == shark_size || map[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
            else if(map[nx][ny] < shark_size && map[nx][ny] != 0) {
                dist[nx][ny] = dist[x][y] + 1;
                if(map[nx][ny] > 0) {
                    map[nx][ny] *= -1;
                }
                if(min_dist > dist[nx][ny]) {
                    min_dist = dist[nx][ny];
                }
                possible_eat = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    cin >> n;
    int sx, sy;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                map[i][j] = 0;
                sx = i;
                sy = j;
            }
        }
    }
    int flag = 0;
    while(true) {
        bfs(sx, sy);
        if(!possible_eat) break;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][j] == min_dist && map[i][j] < 0) {
                    sx = i;
                    sy = j;

                    flag = 1;
                    map[i][j] = 0;
                    ans += min_dist;
                    cnt++;
                    if(cnt == shark_size) {
                        cnt = 0;
                        shark_size++;
                    }
                    break;
                }
            }
            if(flag) break;
        }
        flag = 0;
        possible_eat = false;
        fill(&dist[0][0], &dist[20][21], 0);
    }
    cout << ans;
}