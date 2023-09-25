#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int cnt = 0;
		for (int j = x; j <= (m * n); j+=m) {
			if ((j-1) % n == y - 1) {
				cout << j << '\n';
				cnt++;
				break;
			}
		}
		if (!cnt) cout << -1 << '\n';
	}
}