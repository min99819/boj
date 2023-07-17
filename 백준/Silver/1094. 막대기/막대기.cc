#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	int stick = 64;
	int cnt = 0;
	while (x > 0) {
		if (stick > x) {
			stick /= 2;
		}
		else {
			x -= stick;
			cnt++;
		}
	}
	cout << cnt;
}
