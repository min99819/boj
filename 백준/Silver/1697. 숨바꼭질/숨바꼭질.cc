#include <iostream>
#include <queue>
using namespace std;
int visit[100001];
int main() {
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == m) break;

		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push(x - 1);
			visit[x - 1] = visit[x] + 1;
		}
		if (x + 1 <= 100000 && !visit[x + 1]) {
			q.push(x + 1);
			visit[x + 1] = visit[x] + 1;
		}
		if (x * 2 <= 100000 && !visit[x * 2]) {
			q.push(x * 2);
			visit[x * 2] = visit[x] + 1;
		}
	}
	cout << visit[m];
}