#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int start = round(n * 0.15);
	int end = n - round(n * 0.15);

	double sum = 0;
	for (int i = start; i < end; i++) {
		sum += v[i];
	}
	cout << round(sum / (end - start));
}