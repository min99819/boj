#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans[501][501];
int main() {
    int n;
    cin >> n;
    vector<int> v[n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    ans[0][0] = v[0][0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            ans[i][j] = max(ans[i-1][j], ans[i-1][j-1]) + v[i][j];
        }
    }
    int res = 0;
    for(int i=0; i<n; i++) {
        res = max(res, ans[n-1][i]);
    }
    cout << res;
}