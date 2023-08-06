#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, m;
	string s;
	cin >> n >> m >> s;
	string cmp = "I";
	for (int i = 0; i < n; i++) {
		cmp += "OI";
	}
	int index = 0;
	int cnt = 0;
	while (1) {
		if (s.find(cmp, index) == string::npos) break;
		else {
			cnt++;
			index = s.find(cmp, index) + 1;
		}
	}
	cout << cnt;
}