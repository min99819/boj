#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int tree[27][2];
void preorder(int n) {
	if (n < 0) return;
	
	cout << char(n + 'A');
	preorder(tree[n][0]);
	preorder(tree[n][1]);

	return;
}
void inorder(int n) {
	if (n < 0) return;

	inorder(tree[n][0]);
	cout << char(n + 'A');
	inorder(tree[n][1]);
}
void postorder(int n) {
	if (n < 0) return;

	postorder(tree[n][0]);
	postorder(tree[n][1]);
	cout << char(n + 'A');
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'][0] = b - 'A';
		tree[a - 'A'][1] = c - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
}