#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10001];
int dp[10001];
int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    int ans = dp[1];
    if(n>=2) dp[2] = arr[2] + arr[1];
    for(int i=2; i<=n; i++) {
        if(i==2) {
            dp[i] = max(arr[i] + arr[i-2], max(arr[i] + arr[i-1], dp[i-1]));
        }
        else {
            dp[i] = max(arr[i] + arr[i-1] + dp[i-3], max(arr[i] + dp[i-2], dp[i-1]));
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

