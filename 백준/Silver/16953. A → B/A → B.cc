#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int a, b;
void add_one(long long cur, int cnt);
void mul_two(long long cur, int cnt) {
	if (cur == b) {
		v.push_back(cnt);
		return;
	}
	else if (cur > b) return;

	cur *= 2;
	cnt++;
	mul_two(cur, cnt);
	add_one(cur, cnt);
}
void add_one(long long cur, int cnt) {
	if (cur == b) {
		v.push_back(cnt);
		return;
	}
	else if (cur > b) return;

	cur = cur * 10 + 1;
	cnt++;
	mul_two(cur, cnt);
	add_one(cur, cnt);
}
int main() {
	cin >> a >> b;
	mul_two(a, 0);
	add_one(a, 0);
	
	sort(v.begin(), v.end());
	if (v.size() == 0) cout << -1;
	else cout << v[0] + 1;
}