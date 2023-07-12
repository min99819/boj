#include <iostream>
using namespace std;
int count_re = 0;
int fib(int n) {
	if (n == 1 || n == 2) {
		count_re++;
		return 1;
	}
	else return fib(n - 1) + fib(n - 2);
}
int main() {
	int n;
	cin >> n;
	int fibo[41] = { 0 };
	fibo[1] = 1;
	fibo[2] = 1;
	int count_dp = 0;
	for (int i = 3; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		count_dp++;
	}
	fib(n);
	cout << count_re << ' ' << count_dp;
}