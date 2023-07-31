#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double center_dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		double dist = abs(r1 - r2);
		double dist2 = r1 + r2;
		if (center_dist == 0 && r1 == r2) cout << -1 << '\n';
		else if (center_dist == dist2 || center_dist == dist) cout << 1 << '\n';
		else if (center_dist > dist && center_dist < dist2) cout << 2 << '\n'; \
		else cout << 0 << '\n';
	}
}
	