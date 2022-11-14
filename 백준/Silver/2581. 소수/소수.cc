#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool isPrime(int num) {
	int cnt = 0;
	for (int i = 2; i < num; i++) {
		if (num % i != 0) cnt++;
	}
	if (cnt == num - 2) {
		v.push_back(num);
		return true;
	}
	return false;
}
int main() {
	int m, n;
	cin >> m >> n;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	if (!v.size()) cout << "-1";
	else {
		int min = *min_element(v.begin(), v.end());
		cout << sum << "\n" << min;
	}
}