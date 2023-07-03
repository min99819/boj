#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 1;
	while (n >= cnt) {
		n -= cnt;
		cnt++;
	}
	if (cnt % 2) cout << cnt - n;
	else cout << 0;
}