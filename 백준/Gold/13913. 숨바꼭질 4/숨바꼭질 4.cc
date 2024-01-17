#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool is_visit[100001];
int position[100001];
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int,int>> q;
	q.push({n,0});
    int cnt;
	while (!q.empty()) {
		int x = q.front().first;
        cnt = q.front().second;
		q.pop();
		if (x == m) break;

		if (x - 1 >= 0 && !is_visit[x - 1]) {
			q.push({x-1, cnt + 1});
			is_visit[x - 1] = true;
            position[x - 1] = x;
		}
		if (x + 1 <= 100000 && !is_visit[x + 1]) {
			q.push({x + 1, cnt + 1});
			is_visit[x + 1] = true;
            position[x + 1] = x;
		}
		if (x * 2 <= 100000 && !is_visit[x * 2]) {
			q.push({x * 2, cnt + 1});
			is_visit[x * 2] = true;
            position[x * 2] = x;
		}
	}
	cout << cnt << '\n';
    int a = m;
    stack<int> s;
    while(a != n) {
        s.push(position[a]);
        a = position[a];
    }
    while(!s.empty()) {
        int ans = s.top();
        cout << ans << ' ';
        s.pop();
    }
    cout << m;
}