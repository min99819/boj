#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[1000];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int ans = 0;
    for(int i=0; i<n; i++) {
        int flag = 0;
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
                flag = 1;
            }
        }
        if(!flag) dp[i] = arr[i];
        ans = max(dp[i], ans);
    }
    cout << ans;
}