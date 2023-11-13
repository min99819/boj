#include <iostream>
#include <algorithm>
using namespace std;
int dp_left[1001];
int dp_right[1001];
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
                temp = max(dp_left[j], temp);
            }
        }
        dp_left[i] = temp + 1;
    }
    for(int i=n-1; i>=0; i--) {
        int temp = 0;
        for(int j=n-1; j>i; j--) {
            if(arr[i] > arr[j]) {
                temp = max(dp_right[j], temp);
            }
        }
        dp_right[i] = temp + 1;
    }
    for(int i=0; i<n; i++) {
        if(ans < dp_left[i] + dp_right[i])
            ans = dp_left[i] + dp_right[i];
    }
    cout << ans - 1;
}