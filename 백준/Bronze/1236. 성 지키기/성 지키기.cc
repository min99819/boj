#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, m;
	char castle[51][51];
	int cnt = 0;
	int temp1 = 0, temp2 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			castle[i][j] = a[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (castle[i][j] == 'X') cnt++;
		}
		if (!cnt) temp1++;
		cnt = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (castle[j][i] == 'X') cnt++;
		}
		if (!cnt) temp2++;
		cnt = 0;
	}
	int ans = (temp1>temp2) ? temp1:temp2;
	cout << ans;
}