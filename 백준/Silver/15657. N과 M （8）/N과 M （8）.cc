#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[8];
vector<int> result;
void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else if (cnt == 0) {
		for (int i = 0; i < n; i++) {
			result.push_back(arr[i]);
			solve(cnt + 1);
			result.pop_back();
		}
	}
	for (int i = 0; i < n; i++) {
		if (cnt >= 1 && result[cnt-1] <= arr[i]) {
			result.push_back(arr[i]);
			solve(cnt + 1);
			result.pop_back();
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0);
}
