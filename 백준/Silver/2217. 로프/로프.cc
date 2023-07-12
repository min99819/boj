#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> weight;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		weight.push_back(a);
	}
	sort(weight.begin(), weight.end());
	for (int i = 0; i < n; i++) {
		weight[i] *= (n - i);
	}
	int max = *max_element(weight.begin(), weight.end());
	cout << max;
}