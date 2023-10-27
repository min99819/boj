#include <iostream>
using namespace std;
int a, b, c;
long long solve(long long n) {
	if (n == 1) return a % c;

	long long t = solve(n / 2) % c;
	if (n % 2 == 0) return t * t % c;
	else return t * t % c * a % c;
}
int main() {
	cin >> a >> b >> c;
	long long ans = solve(b);
	
	cout << ans;
}