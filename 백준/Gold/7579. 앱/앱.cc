#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int capacity[101];
int cost[101];
int dp[101][10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int total = 0;
    int ans = 10001;
    for(int i=1; i<=n; i++) {
        cin >> capacity[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
        total += cost[i];
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=total; j++) {
            if(cost[i] - j <= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + capacity[i]);
            }
            else
                dp[i][j] = dp[i-1][j];

            if(dp[i][j] >= m) ans = min(ans, j);
        }
    }
    cout << ans;
}