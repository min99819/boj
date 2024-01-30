#include <iostream>
using namespace std;
long long arr[55];
long long count_one(long long n) {
    long long cnt = n & 1;
    for(int i=54; i>0; i--) {
        if(n & (1LL << i)) {
            cnt += arr[i-1] + (n - (1LL << i) + 1);
            n -= 1LL << i;
        }
    }
    return cnt;
}

int main() {
    long long a, b;
    cin >> a >> b;

    arr[0] = 1;
    for(int i=i; i<55; i++) {
        arr[i] = arr[i-1] * 2 + (1LL << i);
    }

    long long result = count_one(b) - count_one(a - 1);
    cout << result << endl;

    return 0;
}
