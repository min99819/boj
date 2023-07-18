#include <iostream>
#include <algorithm>
using namespace std;
int score[1000];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	sort(score, score + n);
	reverse(score, score + n);
	cout << score[k - 1];
}