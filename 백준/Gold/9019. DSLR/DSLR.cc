#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void bfs(int a, int b) {
	bool visit[10000] = { 0 };
	queue<pair<int, string>> q;
	string ans = "";
	q.push({ a,ans });
	visit[a] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num == b) {
			cout << str << '\n';
			return;
		}
		int next = num * 2 % 10000;
		if (visit[next] == false) {
			visit[next] = true;
			q.push({ next, str + "D" });
		}
		if (num == 0) next = 9999;
		else next = num - 1;
		
		if (visit[next] == false) {
			visit[next] = true;
			q.push({ next, str + "S" });
		}
		int temp = num / 1000;
		next = num % 1000 * 10 + temp;
		if (visit[next] == false) {
			visit[next] = true;
			q.push({ next, str + "L" });
		}
		temp = num % 10;
		next = temp * 1000 + num / 10;
		if (visit[next] == false) {
			visit[next] = true;
			q.push({ next, str + "R" });
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		bfs(a, b);
	}
}