#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    vector<int> bag(k);
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i=0; i<n; i++) {
        cin >> jewel[i].first >> jewel[i].second;
    }
    for(int i=0; i<k; i++) {
        cin >> bag[i];
    }
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    long long ans = 0;
    int flag = 0;
    for(int i=0; i<k; i++) {
        while(flag < n) {
            if(bag[i] >= jewel[flag].first) {
                pq.push(jewel[flag++].second);
            }
            else break;
        }
        if(!pq.empty()) {
            ans += (long long)pq.top();
            pq.pop();
        }
    }
    cout << ans;
}