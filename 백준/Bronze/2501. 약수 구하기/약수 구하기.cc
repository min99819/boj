#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> divisor;
    for(int i=1; i<=n; i++) {
        if(n % i == 0) {
            divisor.push_back(i);
        }
    }
    if(k > divisor.size()) cout << 0;
    else cout << divisor[k-1];
}