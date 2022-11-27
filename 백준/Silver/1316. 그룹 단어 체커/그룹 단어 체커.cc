#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	string s;
	vector<char> group;
	int cnt = 0;
	bool decide = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = group.size();
		for (int j = 0; j < s.size(); j++) {
			if (j == 0) group.push_back(s[j]);

			if (s[j] != s[j + 1]) {
				group.push_back(s[j + 1]);
			}
		}
		for (int k = size; k < group.size(); k++) {
			for (int m = k + 1; m < group.size(); m++) {
				if (group[k] == group[m]) {
					decide = false;
					break;
				}
			}
		}
		if (decide) {
			cnt++;
		}
		decide = true;
	}
	cout << cnt;
}