#include <iostream>
using namespace std;
const int DIV = 1000000007;
long long fpow(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % DIV;
        }
        a = (a * a) % DIV;
        b /= 2;
    }
    return res;
}
int main() {
    long long a, b, temp, temp2;
    cin >> a >> b;
    temp = a;
    if(a == 1) cout << b % DIV;
    else {
        temp = fpow(temp, b);
        temp2 = fpow(a - 1, DIV - 2);
        cout << ((temp - 1) * temp2) % DIV;
    }
}