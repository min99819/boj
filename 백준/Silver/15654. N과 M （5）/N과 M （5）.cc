#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[8];
bool visit[8];
vector<int> result;
void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			result.push_back(arr[i]);
			solve(cnt + 1);
			result.pop_back();
			visit[i] = false;
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