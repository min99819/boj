#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[1000][1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, target;
    cin >> n >> target;
    int i = -1, j = 0, k = n * n, dir = 1, p = n;
    int ans_x, ans_y;
    while(1) {
        for(int x=0; x<p; x++) {
            i += dir;
            if(target == k) {
                ans_x = i + 1;
                ans_y = j + 1;
            }
            map[i][j] = k--;
        }
        p--;
        if(p <= 0) break;
        for(int x=0; x<p; x++) {
            j += dir;
            if(target == k) {
                ans_x = i + 1;
                ans_y = j + 1;
            }
            map[i][j] = k--;
        }
        dir *= -1;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << ans_x << ' ' << ans_y;
}