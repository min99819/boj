#include <iostream>
using namespace std;
int pos[10001];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int h1, h2;
        cin >> h1 >> h2;
        pos[h1] = i+1, pos[h2] = i+1;
    }
    int idx = 1;
    n = n % (2 * m);
    if(n == 0) n = 2*m;

    for(int i=1; i<=10000; i++) {
        if(pos[i] != 0) {
            if(idx == n) {
                cout << pos[i];
                break;
            }
            else idx++;
        }
    }
}