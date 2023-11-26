#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 2;
    for(int i=1; i<=n; i++) {
        ans += (ans - 1);
    }
    cout << (int)pow(ans, 2);
}