#include <iostream>
#include <deque>
using namespace std;
deque< pair<int,int> > dq;
int main() {
    int n;
    cin >> n;
    int num;
    for(int i=1; i<=n; i++) {
        cin >> num;
        dq.push_back(make_pair(num,i));
    }
    int cnt = 0;
    while(1) {
        int x = dq.front().first;
        int idx = dq.front().second;
        dq.pop_front();
        cout << idx << " ";
        
        if(dq.empty()) break;
        while(x != 0) {
            if(x < 0) {
                pair<int, int> a = dq.back();
                dq.pop_back();
                dq.push_front(a);
                x++;
            }
            else {
                if(x == 1) break;
                pair<int, int> a = dq.front();
                dq.pop_front();
                dq.push_back(a);
                x--;
            }
        }
    }
}