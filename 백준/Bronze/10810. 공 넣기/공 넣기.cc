#include <iostream>
using namespace std;
int basket[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++) {
			basket[j] = c;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << basket[i] << " ";
	}
}