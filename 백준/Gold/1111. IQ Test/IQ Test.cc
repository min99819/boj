#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int num[51] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int a=0, b=0;
	if (n == 1) cout << "A";
	else if (n == 2) {
		if (num[0] == num[1]) cout << num[0];
		else cout << "A";
	}
	else {
		if (num[1] - num[0] != 0) {
			a = (num[2] - num[1]) / (num[1] - num[0]);
		}
		b = num[1] - num[0] * a;
		for (int i = 0; i < n - 1; i++) {
			if (num[i + 1] != num[i] * a + b) {
				cout << "B";
				return 0;
			}
		}
		cout << num[n - 1] * a + b;
	}
}