#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int arr[1000001];
int position[1000001];
vector<int> ans_vec;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        auto idx = lower_bound(v.begin(), v.end(), arr[i]);
        
        if(idx == v.begin() + ans) {
            v.push_back(arr[i]);
            position[i] = ans;
            ans++;
        } 
        else {
            *idx = arr[i];
            position[i] = idx - v.begin();
        }
    }
    cout << ans << '\n';
    for(int i=n; i>0; i--) {
        if(position[i] == ans - 1) {
            ans_vec.push_back(arr[i]);
            ans--;
        }
    }
    reverse(ans_vec.begin(), ans_vec.end());
    for(int i=0; i<ans_vec.size(); i++) {
        cout << ans_vec[i] << ' ';
    }
}