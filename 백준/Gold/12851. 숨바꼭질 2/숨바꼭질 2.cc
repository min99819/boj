#include <iostream>
#include <queue>
using namespace std;
int is_visit[100001];
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int,int>> q;
	q.push({n,0});
    int ans1 = 0, ans2 = 0;
    int flag = 0;
	while (!q.empty()) {
		int x = q.front().first;
        int cnt = q.front().second;
		q.pop();
        is_visit[x] = 1;

        if(x == m && flag) {
            if(ans1 == cnt) ans2++;
        }
		if (x == m && !flag) {
            flag = 1;
            ans1 = cnt;
            ans2++;
        }
        

		if (x - 1 >= 0 && !is_visit[x - 1]) {
			q.push({x-1, cnt + 1});
		}
		if (x + 1 <= 100000 && !is_visit[x + 1]) {
			q.push({x+1, cnt + 1});
		}
		if (x * 2 <= 100000 && !is_visit[x * 2]) {
			q.push({x*2, cnt + 1});
		}
	}
	cout << ans1 << '\n' << ans2;
}