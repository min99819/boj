#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int map[51][51];
bool check[14];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int chicken_dist = 1000000000;
int dist(int x, int y, int dx, int dy) {
	return abs(x - dx) + abs(y - dy);
}
void find_distance() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		int min_dist = 1000000000;
		for (int j = 0; j < chicken.size(); j++) {
			if (check[j]) {
				int nx = chicken[j].first;
				int ny = chicken[j].second;
				min_dist = min(min_dist, dist(x, y, nx, ny));
			}
		}
		sum += min_dist;
	}
	chicken_dist = min(chicken_dist, sum);
}
void choice(int index, int cnt) {
	if (cnt == m) {
		find_distance();
	}
	for (int i = index; i < chicken.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			choice(i, cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	choice(0, 0);
	cout << chicken_dist;
}