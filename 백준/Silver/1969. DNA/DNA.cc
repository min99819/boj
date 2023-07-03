#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v;
	char dna[5] = { 'T', 'G', 'C', 'A' };
	int cnt[4] = { 0 };
	string ans;
	int ans_sum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j][i] == dna[0]) cnt[0]++;
			else if (v[j][i] == dna[1]) cnt[1]++;
			else if (v[j][i] == dna[2]) cnt[2]++;
			else cnt[3]++;
		}
		int cnt_max = 0;
		int flag;
		for (int j = 0; j < 4; j++) {
			if (cnt[j] >= cnt_max) {
				cnt_max = cnt[j];
				flag = j;
			}
		}
		ans_sum += n - cnt_max;
		ans += dna[flag];
		fill_n(cnt, 4, 0);
	}
	cout << ans << "\n" << ans_sum;
}