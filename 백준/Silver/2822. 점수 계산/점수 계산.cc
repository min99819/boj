#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int score[8];
	int ord[8];
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		cin >> score[i];
		ord[i] = score[i];
	}
	sort(score, score + 8);
	reverse(score, score + 8);
	for (int i = 0; i < 5; i++) {
		sum += score[i];
	}
	cout << sum << endl;
	int ans[5];
	for (int i = 0; i < 5; i++) {
		ans[i] = find(ord, ord + 8, score[i]) - ord + 1;
	}
	sort(ans, ans + 5);
	for (int i = 0; i < 5; i++) {
		cout << ans[i] << ' ';
	}
}
