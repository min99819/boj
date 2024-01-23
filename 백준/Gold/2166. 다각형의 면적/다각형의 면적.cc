#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
vector<pair<ll, ll>> v;
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    long double ans = 0;
    long double temp = 0;
    for(int i=1; i<n-1; i++) {
        temp = v[0].first * v[i].second + v[i].first * v[i+1].second 
            + v[i+1].first * v[0].second;
        temp -= v[i].first * v[0].second + v[i+1].first * v[i].second
            + v[0].first * v[i+1].second;
        temp /= 2;
        ans += temp;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}