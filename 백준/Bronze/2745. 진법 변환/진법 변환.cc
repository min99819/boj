#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    string n;
    int b;
    cin >> n >> b;
    int ans = 0;
    int digit = 0;
    for(int i=n.length() - 1; i>=0; i--) {
        if(n[i] >= 'A' && n[i] <= 'Z') {
            ans += (n[i] - 'A' + 10) * pow(b, digit);
        }
        else ans += (n[i] - '0') * pow(b, digit);

        digit++;
    }
    cout << ans;
}