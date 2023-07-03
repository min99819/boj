#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt_0 = 0;
	int cnt_1 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[i + 1]) {
			continue;
		}
		else if (s[i] == '0') cnt_0++;
		else cnt_1++;
	}
	if (cnt_0 > cnt_1) cout << cnt_1;
	else cout << cnt_0;
}