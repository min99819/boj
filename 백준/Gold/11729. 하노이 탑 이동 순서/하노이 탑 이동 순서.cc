#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt = 0;
int s = 1, m = 2, e = 3;
vector<pair<int, int> > v;
void hanoi(int n, int s, int e, int m) {
    cnt++;
    if(n == 1) {
        v.push_back(make_pair(s, e));
        return;
    }

    hanoi(n-1, s, m, e);
    v.push_back(make_pair(s, e));
    hanoi(n-1, m, e, s);
}
int main() {
    int n;
    cin >> n;
    hanoi(n, s, e, m);
    cout << cnt << '\n';
    for(int i=0; i<v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
}