#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 5; i <= n; i += 5) {
		if (!(i % 125)) cnt += 3;
		else if (!(i % 25)) cnt += 2;
		else if (!(i % 5)) cnt++;
	}
	cout << cnt;
}