#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[8];
int visit[8];
vector<int> result;
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	else if (cnt == 0) {
		for (int i = 0; i < n; i++) {
			visit[i] = 1;
			result.push_back(arr[i]);
			dfs(cnt + 1);
			result.pop_back();
			visit[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == 1) continue;
		if (cnt >= 1 && result[cnt - 1] < arr[i]) {
			visit[i] = 1;
			result.push_back(arr[i]);
			dfs(cnt + 1);
			result.pop_back();
			visit[i] = 0;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		visit[i] = 0;
	}
	dfs(0);
}
