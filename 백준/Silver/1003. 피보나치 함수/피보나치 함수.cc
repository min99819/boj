#include <iostream>
using namespace std;
long long fibo[41] = {0,1,1};
int main() {
	int t;
	cin >> t;
    int n;
    for (int i = 3; i < 41; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0) cout << "1 0\n";
        else if (n == 1) cout << "0 1\n";
        else cout << fibo[n - 1] << " " << fibo[n] << "\n";
    }
}