#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s;
	vector<string> v;
	vector<string> result;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}