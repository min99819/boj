#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int dp[1001] = { 0 };
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		if (dp[i - 4] && dp[i - 3] && dp[i - 1]) {
			dp[i] = 0;
		}
		else dp[i] = 1;
	}
	if (dp[n] == 1) cout << "SK";
	else cout << "CY";
}