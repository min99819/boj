#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, x2, y1, y2, n;
		int cnt = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (pow(cx - x1, 2) + pow(cy - y1, 2) < r * r) {
				if (pow(cx - x2, 2) + pow(cy - y2, 2) > r * r) cnt++;
			}
			if (pow(cx - x1, 2) + pow(cy - y1, 2) > r * r) {
				if (pow(cx - x2, 2) + pow(cy - y2, 2) < r * r) cnt++;
			}
		}
		cout << cnt << '\n';
	}
}