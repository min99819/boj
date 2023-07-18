#include <iostream>
using namespace std;
int main() {
	long long s;
	cin >> s;
	long long num = 1;
	long long sum = 0;
	int cnt = 0;
	while (sum <= s) {
		sum += num;
		cnt++;
		num++;
	}
	cout << cnt - 1;
}