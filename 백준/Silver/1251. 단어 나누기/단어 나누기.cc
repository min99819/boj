#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		ans += 'z';
	}
	for (int i = 0; i < s.length() - 2; i++) {
		for (int j = i + 1; j < s.length() - 1; j++) {
			string temp = "";
			for (int k = i; k >= 0; k--) {
				temp += s[k];
			}
			for (int k = j; k > i; k--) {
				temp += s[k];
			}
			for (int k = s.length() - 1; k > j; k--) {
				temp += s[k];
			}
			if (ans > temp) ans = temp;
		}
	}
	cout << ans;
}