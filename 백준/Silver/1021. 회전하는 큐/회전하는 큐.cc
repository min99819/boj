#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    deque<int> dq;
    for(int i=1; i<=n; i++) {
        dq.push_back(i);
    }
    int cnt = 0;
    while(m--) {
        int a;
        int idx;
        cin >> a;
        for(int i=0; i<dq.size(); i++) {
            if(dq[i] == a) {
                idx = i;
                break;
            }
        }
        if(idx > dq.size() - idx) {
            while(1) {
                if(dq.back() == a){ 
                    dq.pop_back();
                    cnt++;
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        else {
            while(1) {
                if(dq.front() == a) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
    }
    cout << cnt;
}