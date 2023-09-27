#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int RGB[1001][3] = { 0 };
	int r, g, b;
	cin >> r >> g >> b;
	RGB[0][0] = r;
	RGB[0][1] = g;
	RGB[0][2] = b;
	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		RGB[i][0] = min(RGB[i - 1][1], RGB[i - 1][2]) + r;
		RGB[i][1] = min(RGB[i - 1][0], RGB[i - 1][2]) + g;
		RGB[i][2] = min(RGB[i - 1][0], RGB[i - 1][1]) + b;
	}
	cout << min(RGB[n - 1][0], min(RGB[n - 1][1], RGB[n - 1][2]));
}