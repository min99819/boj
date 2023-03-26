#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main() {
	int T, n;
	cin >> T;
	string cmd, arr;
	
	for(int i=0; i<T; i++) {
		deque<int> d;
		bool rev = true;
		bool non_empty = true;
		cin >> cmd >> n >> arr;
		string tmp = "";
		for(int j=0; j<arr.size(); j++) {
			if(arr[j] == '[') continue;
			else if(arr[j] >= '0' && arr[j] <= '9') {
				tmp += arr[j];
			}
			else {
				if(!tmp.empty()) {
					d.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		for(int j=0; j<cmd.length(); j++) {
			if(cmd[j] == 'R') {
				rev = !rev;
			}
			else {
				if(!d.empty()) {
					if(rev) {
						d.pop_front();
					}
					else d.pop_back();
				}
				else {
					non_empty = false;
					cout << "error\n";
					break;
				}
			}
		}
		if(non_empty) {
			cout << "[";
			if(rev) {
				while(!d.empty()) {
					cout << d.front();
					d.pop_front();
					if(!d.empty()) cout << ",";
				}
			}
			else {
				while(!d.empty()) {
					cout << d.back();
					d.pop_back();
					if(!d.empty()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}	
}