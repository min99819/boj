#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<int> building;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if (building.empty()) building.push(h);
		while (!building.empty()) {
			if (building.top() > h) break;
			building.pop();
		}
		ans += building.size();
		building.push(h);
	}
	cout << ans;
}