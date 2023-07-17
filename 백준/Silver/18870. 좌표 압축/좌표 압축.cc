#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
		v2.push_back(a);
	}
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() << ' ';
	}
}
