#include <iostream>
#include <vector>
#include <algorithm>\
#include <utility>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	int cnt=0;
	for(int i=0; i<n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	int last_end = v[0].first;
	for(int i=1; i<n; i++) {
		if(last_end <= v[i].second) {
			cnt++;
			last_end = v[i].first;
		}
	}
	cout << cnt + 1;
}