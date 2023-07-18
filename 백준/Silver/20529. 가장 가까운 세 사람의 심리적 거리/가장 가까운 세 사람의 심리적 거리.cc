#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<string> mbti(n);
		string s;
		for (int j = 0; j < n; j++) {
			cin >> mbti[j];
		}
		if (n > 32) {
			cout << 0 << '\n';
			continue;
		}
		int dist = 0;
		int min_dis = INT_MAX;
		for (int x = 0; x < n; x++) {
			for (int y = x + 1; y < n; y++) {
				for (int z = y + 1; z < n; z++) {
					dist = 0;
					for (int k = 0; k < 4; k++) {
						if (mbti[x][k] != mbti[y][k]) {
							dist++;
						}
						if (mbti[y][k] != mbti[z][k]) {
							dist++;
						}
						if (mbti[z][k] != mbti[x][k]) {
							dist++;
						}
					}
					min_dis = min(dist, min_dis);
				}
			}
		}
		cout << min_dis << '\n';
	}
}