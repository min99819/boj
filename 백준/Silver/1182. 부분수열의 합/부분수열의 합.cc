#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, s;
map<int, int> temp;
vector<int> arr;
long long res = 0;
void left(int start, int sum) {
    if(start == n/2) {
        temp[sum]++;
        return;
    }
    left(start + 1, sum);
    left(start + 1, sum + arr[start]);
}
void right(int mid, int sum) {
    if(mid == n) {
        res += temp[s - sum];
        return;
    }

    right(mid + 1, sum);
    right(mid + 1, sum + arr[mid]);
}
int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    left(0, 0);
    right(n/2, 0);
    if(s == 0) cout << res - 1;
    else cout << res;
}