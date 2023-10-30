#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, c;
long long weight[31];
void cal_weight(int start, int end, vector<long long>& v, long long sum) {
	if (sum > c) return;

	if (start > end) {
		v.push_back(sum);
		return;
	}
	else {
		cal_weight(start + 1, end, v, sum);
		cal_weight(start + 1, end, v, sum + weight[start]);
	}
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	long long cnt = 0;
	vector<long long> weight_a;
	vector<long long> weight_b;
	cal_weight(0, (n / 2) - 1, weight_a, 0);
	cal_weight(n / 2, n - 1, weight_b, 0);
	sort(weight_b.begin(), weight_b.end());
	for (int i = 0; i < weight_a.size(); i++) {
		cnt += upper_bound(weight_b.begin(), weight_b.end(), c - weight_a[i]) - weight_b.begin();
	}
	cout << cnt;
}