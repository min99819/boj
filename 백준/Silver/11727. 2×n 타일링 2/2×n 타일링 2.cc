#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans[1001] = { 0 };
	ans[1] = 1;
	ans[2] = 3;
	ans[3] = 5;
	ans[4] = 11;
	for (int i = 5; i <= n; i++) {
		if (i % 2) ans[i] = ans[i - 1] * 2 - 1;
		else ans[i] = ans[i - 1] * 2 + 1;
		
		ans[i] = ans[i] % 10007;
	}
	cout << ans[n];
}