#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<string, string> set;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		set[s1] = s2;
	}
	for (int i = 0; i < m; i++) {
		string find;
		cin >> find;
		cout << set[find] << "\n";
	}
}