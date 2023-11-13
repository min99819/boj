#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        int temp = 0;
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                temp = max(dp[j], temp);
            }
        }
        dp[i] = temp + 1;
        ans = max(dp[i], ans);
    }
    cout << ans;
}