#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	queue<int> que;
	string cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			que.push(x);
		}
		if (cmd == "pop") {
			if (que.empty())
				cout << -1 << "\n";
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		if (cmd == "size") {
			cout << que.size() << "\n";
		}
		if (cmd == "empty") {
			cout << que.empty() << "\n";
		}
		if (cmd == "front") {
			if (que.empty())
				cout << -1 << "\n";
			else cout << que.front() << "\n";
		}
		if (cmd == "back") {
			if (que.empty())
				cout << -1 << "\n";
			else cout << que.back() << "\n";
		}
	}
	return 0;
}