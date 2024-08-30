#include <iostream>
using namespace std;
int map[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

void dfs(int cnt) {
    int a = cnt / 9;
    int b = cnt % 9;
    // 탈출 조건
    if(cnt == 81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    
    if(map[a][b] == 0) {
        for(int i=1; i<=9; i++) {
            if(!row[a][i] && !col[b][i] && !square[(a / 3) * 3 + (b / 3)][i]) {
                row[a][i] = true;
                col[b][i] = true;
                square[(a / 3) * 3 + (b / 3)][i] = true;
                map[a][b] = i;
                dfs(cnt + 1);
                map[a][b] = 0;
                row[a][i] = false;
                col[b][i] = false;
                square[(a / 3) * 3 + (b / 3)][i] = false;
            }
        }
    }
    else dfs(cnt + 1);
}

int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0 ) {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }
    dfs(0);
}