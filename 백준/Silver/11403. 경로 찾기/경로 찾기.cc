#include <iostream>
using namespace std;
int map[101][101];
int visit[101][101];
int n;
void dfs(int x, int temp) {
	for (int i = 0; i < n; i++) {
		if (map[x][i] == 1 && !visit[temp][i]) {
			visit[temp][i] = 1;
			dfs(i, temp);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		dfs(i, temp);
		temp++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
}