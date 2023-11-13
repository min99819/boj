#include <iostream>
using namespace std;
int map[1025][1025];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int a;
            cin >> a;
            map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + a;
        }
    }
    int x1, x2, y1, y2;
    for(int i=0; i<m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
        cout << ans << '\n';
    }
}