#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
bool is_visit[100001];
int main() {
    int n, k;
    cin >> n >> k;
    pq.push(make_pair(0, n));      
    is_visit[n] = true;
    int ans = 0;
    while(!pq.empty()) {
        int sec = pq.top().first;
        int x = pq.top().second;
        is_visit[x] = true;
        pq.pop();

        if(x == k) {
            ans = sec;
            break;
        }

        if(x - 1 >= 0 && !is_visit[x-1]) {
            pq.push(make_pair(sec+1, x-1));
        }
        if(x + 1 <= 100000 && !is_visit[x+1]) {
            pq.push(make_pair(sec+1, x+1));
        }
        if(2 * x <= 100000 && !is_visit[2*x]) {
            pq.push(make_pair(sec, 2*x));
        }
    }
    cout << ans;
}