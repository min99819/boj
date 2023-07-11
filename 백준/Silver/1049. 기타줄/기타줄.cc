#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int x = 1000, y = 1000;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		x = min(a, x);
		y = min(b, y);
	}
	int ans = min(((n / 6) + 1) * x, n * y);
	ans = min(ans, (n / 6) * x + (n % 6) * y);
	cout << ans;
}