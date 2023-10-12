#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[8];
int result[8];
void solve(int idx, int cnt) {
	int last = 0;
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = idx; i < n; i++) {
			if (last != arr[i] && result[cnt - 1] <= arr[i]) {
				result[cnt] = arr[i];
				last = arr[i];
				solve(idx, cnt + 1);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0, 0);
}
