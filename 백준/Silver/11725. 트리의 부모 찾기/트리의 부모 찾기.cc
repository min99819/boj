#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100001];
int ans[100001];
bool visit[100001];
int n;
void find_parent(int c) {
	visit[c] = true;
	for (int i = 0; i < v[c].size(); i++) {
		int next = v[c][i];
		if (!visit[next]) {
			ans[next] = c;
			find_parent(next);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	find_parent(1);
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}