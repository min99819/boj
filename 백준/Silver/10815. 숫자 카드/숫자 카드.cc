#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	int* card = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card, card + n);
	cin >> m;
	int compare;
	for (int i = 0; i < m; i++) {
		cin >> compare;
		cout << upper_bound(card, card + n, compare) - lower_bound(card, card + n, compare) << " ";
	}
	delete[] card;
}