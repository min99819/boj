#include <iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long res = 0;
    for(int i=n-1; i > 0; i--) {
        res += i;
    }
    cout << res << '\n' << 2;
}
