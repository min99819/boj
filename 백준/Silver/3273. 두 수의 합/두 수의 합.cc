#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[i] = a;
	}
	int ans;
	cin >> ans;
	sort(num, num + n);
	int start = 0, end = n - 1;
	int cnt = 0;
	while (start < end) {
		int sum = num[start] + num[end];
		if (sum == ans) {
			cnt++;
			start++;
			end--;
		}
		else if (sum > ans) end--;
		else start++;
	}
	cout << cnt;
	delete[] num;
}