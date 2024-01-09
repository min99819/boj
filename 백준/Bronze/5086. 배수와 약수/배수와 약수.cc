#include <iostream>
using namespace std;
int main() {
    int n, m;
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        if(n < m) {
            if(m % n == 0) {
                cout << "factor" << '\n';
            }
            else cout << "neither" << '\n';
        }
        else {
            if(n % m == 0) {
                cout << "multiple" << '\n';
            }
            else cout << "neither" << '\n';
        }
    }
}