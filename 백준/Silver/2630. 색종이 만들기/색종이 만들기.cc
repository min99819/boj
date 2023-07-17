#include <iostream>
using namespace std;
int n;
int map[128][128];
int cnt_white = 0;
int cnt_blue = 0;
void solve(int x, int y, int size) {
	int first = map[x][y];
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (first != map[i][j]) {
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (first == 1) cnt_blue++;
	else cnt_white++;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, n);
	cout << cnt_white << '\n' << cnt_blue;
}