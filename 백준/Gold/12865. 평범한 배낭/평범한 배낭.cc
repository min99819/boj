#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > bag;
int dp[101][100001];
int main() {
    int n, k;
    cin >> n >> k;
    bag.push_back(make_pair(0,0));
    for(int i=1; i<=n; i++) {
        int w, v;
        cin >> w >> v;
        bag.push_back(make_pair(w, v));
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j - bag[i].first >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-bag[i].first] + bag[i].second);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
}