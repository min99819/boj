#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    int sum = 0;
    int max_sum = -999999999;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        cnt++;
        if(cnt == k) {
            max_sum = max(sum, max_sum);
            sum -= arr[i - k + 1];
            cnt--;
        }
    }
    cout << max_sum;
}