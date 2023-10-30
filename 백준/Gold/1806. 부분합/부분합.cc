#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int num[100001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int sum = num[0];
	int start = 0, end = 0;
	vector<int> ans;
	while (start <= end && end < n) {
		if (sum < m) {
			end++;
			sum += num[end];
		}
		else {
			ans.push_back(end - start + 1);
			sum -= num[start];
			start++;
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() == 0) cout << 0;
	else cout << ans[0];
}