#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	long long a = 1, b = 1;
	long long c;
	for (int i = 3; i <= n; i++) {
		c = a + b;
		if (c > 1000000006) c -= 1000000007;
		swap(a, b);
		swap(b, c);
	}
	cout << b << ' ' << n-2;
}