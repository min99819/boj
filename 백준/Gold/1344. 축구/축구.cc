#include <iostream>
#include <cmath>
using namespace std;
double a, b;
long long comb(int x, int y) {
    long long res = 1;
    int temp = y;
    while(temp--) {
        res *= x;
        x--;
    }
    while(y > 1) {
        res /= y;
        y--;
    }
    return res;
}
double prob(double p, int x) {
    return pow(p, x) * pow(1-p, 18-x);
}
int main() {
    cout << fixed;
    cout.precision(7);
    cin >> a >> b;
    a /= 100;
    b /= 100;
    int prime[7] = {2, 3, 5, 7, 11, 13, 17};
    double pa = 0, pb = 0;
    for(int i=0; i<7; i++) {
        pa += comb(18, prime[i]) * prob(a, prime[i]);
        pb += comb(18, prime[i]) * prob(b, prime[i]);
    }
    cout << pa + pb - (pa * pb);
}