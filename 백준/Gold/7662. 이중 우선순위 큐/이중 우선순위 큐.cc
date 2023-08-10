#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;
		int cnt = 0;
		bool flag = true;
		priority_queue<int> pq_max;
		priority_queue<int, vector<int>, greater<int>> pq_min;
		map<int, int> map;
		for (int j = 0; j < k; j++) {
			string s;
			int n;
			cin >> s >> n;
			if (flag) {
				while (!pq_max.empty()) pq_max.pop();
				while (!pq_min.empty()) pq_min.pop();
				flag = false;
			}
			if (s == "I") {
				pq_max.push(n);
				pq_min.push(n);
				map[n]++;
				cnt++;
			}
			else {
				if (cnt == 0) continue;

				if (n == 1 && cnt != 0) {
					map[pq_max.top()]--;
					pq_max.pop();
					cnt--;
				}
				else if (n == -1 && cnt != 0) {
					map[pq_min.top()]--;
					pq_min.pop();
					cnt--;
				}

				while (!pq_max.empty() && map[pq_max.top()] == 0) {
					pq_max.pop();
				}
				while (!pq_min.empty() && map[pq_min.top()] == 0) {
					pq_min.pop();
				}
			}
		}
		if (!cnt) {
			cout << "EMPTY" << '\n';
		}
		else {
			while (!pq_max.empty() && map[pq_max.top()] == 0) {
				pq_max.pop();
			}
			while (!pq_min.empty() && map[pq_min.top()] == 0) {
				pq_min.pop();
			}
			cout << pq_max.top() << " " << pq_min.top() << '\n';
		}
	}
}