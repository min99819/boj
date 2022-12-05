#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		int ans = 1;
		cin >> a >> b;
		int dig_b = b % 4 + 4;
		for (int j = 1; j <= dig_b; j++) {
			ans *= a;
			ans = ans % 10;
		}
		if (ans == 0) ans = 10;
		cout << ans << endl;
	}
}