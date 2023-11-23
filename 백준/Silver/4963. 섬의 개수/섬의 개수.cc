#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[51][51];
bool is_visit[51][51];
int w,h;
int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, 1, -1, -1, 1};
int ans = 0;
void bfs(int sx, int sy) {
    queue<pair<int, int> > q;
    is_visit[sx][sy] = true;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(is_visit[nx][ny]) continue;
            if(map[nx][ny] == 1) {
                is_visit[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    while(1) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        vector<pair<int,int> > land;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> map[i][j];
                if(map[i][j] == 1) {
                    land.push_back(make_pair(i,j));
                }
            }
        }
        ans = 0;
        for(int i=0; i<land.size(); i++) {
            if(!is_visit[land[i].first][land[i].second]) {
                bfs(land[i].first, land[i].second);
                ans++;
            }
        }
        cout << ans << '\n';
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                map[i][j] = 0;
                is_visit[i][j] = false;
            }
        }
    }
}