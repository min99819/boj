#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			for (int j = i; j < s.length(); j++) {
				if (s[j] == '+') s[j] = '-';
			}
		}
	}
	string num;
	int sum = 0;
	int number = 0;
	int cnt = 0;
	char flag[50];
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.length()) {
			cnt++;
			number = stoi(num);
			flag[cnt] = s[i];
			if (cnt == 1) {
				sum += number;
			}
			else {
				if (flag[cnt - 1] == '+') {
					sum += number;
				}
				else sum -= number;
			}
			num = "";
		}
		else {
			num += s[i];
		}
	}
	cout << sum;
}