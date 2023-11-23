#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
vector<pair<int, int> > virus;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[9][9];
int tmp[9][9];
bool is_visit[9][9];
int n, m;
int area = 0;
pair<int,int> w1, w2, w3;
void bfs(int sx, int sy) {
    queue<pair<int, int> > q;
    fill(&is_visit[0][0], &is_visit[n][m], false);
    is_visit[sx][sy] = true;
    q.push(make_pair(sx,sy));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(is_visit[nx][ny]) continue;
            if(tmp[nx][ny] == 1) continue;
            if(tmp[nx][ny] == 0) {
                tmp[nx][ny] = 2;
                is_visit[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
void map_reset() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            tmp[i][j] = map[i][j];
        }
    }
}
void infect() {
    for(int i=0; i<virus.size(); i++) {
        int x = virus[i].first;
        int y = virus[i].second;
        bfs(x,y);
    }
}
void cal_area() {
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(tmp[i][j] == 0) cnt++;
        }
    }
    area = max(area,cnt);
    map_reset();
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            tmp[i][j] = map[i][j];
            if(map[i][j] == 0) v.push_back(make_pair(i,j));
            else if(map[i][j] == 2) virus.push_back(make_pair(i,j));
        }
    }
    for(int i=0; i<v.size()-2; i++) {
        for(int j=i+1; j<v.size()-1; j++) {
            for(int k=j+1; k<v.size(); k++) {
                w1 = v[i];
                w2 = v[j];
                w3 = v[k];
                tmp[w1.first][w1.second] = 1;
                tmp[w2.first][w2.second] = 1;
                tmp[w3.first][w3.second] = 1;
                infect();
                cal_area();
            }
        }
    }
    cout << area;
}