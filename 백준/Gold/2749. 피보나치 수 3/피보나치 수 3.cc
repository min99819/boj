#include <iostream>
#include <map>
#define DIV 1000000
using namespace std;
map<long long, long long> m;
long long fib(long long x) {
    if(x == 0) return 0;
    if(x == 1 || x == 2) return 1;

    if(m[x]) return m[x];
    long long res;
    if(x % 2 == 0) {
        res = (fib(x / 2) * (fib(x / 2 + 1) + fib(x / 2 - 1))) % DIV;
    }
    else {
        res = ((fib((x + 1) / 2) * fib((x + 1) / 2)) % DIV) +
            ((fib((x - 1) / 2) * fib((x - 1) / 2)) % DIV) % DIV;
    }
    m[x] = res % DIV;
    return m[x];
}
int main() {
    long long n;
    cin >> n;
    cout << fib(n);
}