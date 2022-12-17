#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string name;
	map<string, int> poketmon;
	vector<string> s;
	for (int i = 0; i < n; i++) {
		cin >> name;
		poketmon.insert(make_pair(name, i + 1));
		s.push_back(name);
	}
	for (int i = 0; i < m; i++) {
		string test;
		cin >> test;
		if (test[0] < 'A') {
			int num = stoi(test);
			cout << s[num - 1] << "\n";
		}
		else {
			cout << poketmon[test] << "\n";
		}
	}
}