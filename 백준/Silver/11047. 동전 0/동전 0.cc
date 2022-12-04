#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int* won = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> won[i];
	}
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k < won[i]) continue;
		else {
			while (k >= won[i]) {
				cnt++;
				k -= won[i];
			}
		}
	}
	cout << cnt;
	delete[] won;
}