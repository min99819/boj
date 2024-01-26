#include <iostream>
#define DIV 1000000007
using namespace std;
long long fpow(int a, int b) {
    if(b == 0) return 1;

    long long x;
    if(b % 2 == 0) {
        x = fpow(a, b/2);
        x *= x;
    }
    else {
        x = fpow(a, b/2);
        x *= x * a;
    }
    return x % DIV;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) cout << 1 << '\n';
        else cout << fpow(2, n - 2) << '\n';
    }
}
