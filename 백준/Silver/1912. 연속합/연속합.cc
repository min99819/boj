#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    int ans = arr[0];
    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
        ans = max(dp[i], ans);
    }
    cout << ans;
}