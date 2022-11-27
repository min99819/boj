#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}
int main() {
	string n;
	int cnt = 1;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n.size(); i++) {
		num.push_back(n[i] - '0');
	}
	sort(num.begin(), num.end(), compare);
	for (int i = 0; i < num.size(); i++) {
		cout << num[i];
	}
}