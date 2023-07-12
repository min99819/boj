#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int dp[50001] = { 0 };
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	for (int i = 5; i <= n; i++) {
		dp[i] = 1 + dp[i - 1];
		for (int j = 2; j * j <= i; j++) {
			dp[j * j] = 1;
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}
	cout << dp[n];
}