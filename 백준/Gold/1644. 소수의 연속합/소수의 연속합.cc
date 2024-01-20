#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> prime;
    for(int i=2; i*i<=n; i++) {
        if(!v[i]) {
            for(int j=i*i; j<=n; j+=i) {
                v[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(!v[i]) prime.push_back(i);
    }

    int start = 0, end = 1;
    int cnt = 0;
    int sum = 2;
    while(start <= end && end <= prime.size()) {
        if(sum == n) {
            cnt++;
            sum += prime[end];
            end++;
        }
        else if(sum < n) {
            sum += prime[end];
            end++;
        }
        else {
            sum -= prime[start];
            start++;
        }
    }
    cout << cnt;
}