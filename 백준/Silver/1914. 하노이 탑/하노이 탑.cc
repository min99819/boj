#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int s = 1, m = 2, e = 3;
vector<pair<int, int> > v;
void hanoi(int n, int s, int e, int m) {
    if(n == 1) {
        v.push_back(make_pair(s, e));
        return;
    }

    hanoi(n-1, s, m, e);
    v.push_back(make_pair(s, e));
    hanoi(n-1, m, e, s);
}
int main() {
    long long n;
    cin >> n;
    int idx;
    string tmp = to_string(pow(2, n));
    string ans;
    for(int i=0; i<tmp.length(); i++) {
        if(tmp[i] == '.') {
            idx = i - 1;
            break;
        }
    }
    tmp[idx]--;
    ans = tmp.substr(0, idx+1);
    cout << ans << '\n';
    if(n <= 20) {
        hanoi(n, s, e, m);
        for(int i=0; i<v.size(); i++) {
            cout << v[i].first << " " << v[i].second << '\n';
        }
    }
}