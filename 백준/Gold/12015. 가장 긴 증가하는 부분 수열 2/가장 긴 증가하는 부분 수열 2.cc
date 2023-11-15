#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        auto idx = lower_bound(v.begin(), v.begin() + ans, a);
        
        if(idx == v.begin() + ans) {
            v.push_back(a);
            ans++;
        } 
        else *idx = a;
    }
    
    cout << ans;
}