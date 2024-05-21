#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x, s;
    cin >> x >> s;
    bool flag = false;
    for(int i=0; i<n; i++) {
        int c, p;
        cin >> c >> p;
        if(c <= x && p > s) {
            cout << "YES";
            flag = true;
            break;
        }
    }
    if(!flag) cout << "NO";
}