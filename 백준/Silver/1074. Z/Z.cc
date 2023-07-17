#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans = 0;
void position(int x, int size) {
	if (size == 1) return;
	int pos = pow(4, x - 1);
	if (r <= size / 2 - 1 && c <= size / 2 - 1) {
		ans += 0;
	}
	else if (r <= size / 2 - 1 && c <= size - 1) {
		ans += pos;
		c -= size / 2;
	}
	else if (r <= size - 1 && c <= size / 2 - 1) {
		ans += pos * 2;
		r -= size / 2;
	}
	else {
		ans += pos * 3;
		r -= size / 2;
		c -= size / 2;
	}
	position(x - 1, size / 2);
}
int main() {
	cin >> n >> r >> c;
	position(n, pow(2, n));
	cout << ans;
}