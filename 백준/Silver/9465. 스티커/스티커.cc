#include <iostream>
#include <algorithm>
using namespace std;
int n;
int sticker[2][100001];
int ans[2][1000001];
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        for(int j=0; j < n; j++) {
            cin >> sticker[0][j];
        }
        for(int j=0; j < n; j++) {
            cin >> sticker[1][j];
        }
        ans[0][0] = sticker[0][0];
        ans[1][0] = sticker[1][0];
        ans[0][1] = sticker[1][0] + sticker[0][1];
        ans[1][1] = sticker[0][0] + sticker[1][1];
        for(int j=2; j<n; j++) {
            ans[0][j] = sticker[0][j] + max(ans[1][j-1], ans[1][j-2]);
            ans[1][j] = sticker[1][j] + max(ans[0][j-1], ans[0][j-2]);
        }
        cout << max(ans[0][n-1], ans[1][n-1]) << '\n';
    }
}