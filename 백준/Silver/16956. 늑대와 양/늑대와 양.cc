#include <iostream>
using namespace std;
char farm[500][500];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> farm[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (farm[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
						if (farm[ny][nx] == 'W') {
							cout << 0;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << 1 << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (farm[i][j] == '.') {
				cout << 'D';
			}
			else cout << farm[i][j];
		}
		cout << '\n';
	}
}