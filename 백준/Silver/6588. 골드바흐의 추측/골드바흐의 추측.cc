#include <iostream>
#include <vector>
using namespace std;
bool prime[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<=1000000; i++) {
        prime[i] = true;
    }
    for(int i=2; i * i <= 1000000; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=1000000; j += i) {
                prime[j] = false;
            }
        }
    }
    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;
        int left = 3, right = n;
        if(right % 2 == 0) {
            right--;
        }
        bool flag = false;
        while(left<=right) {
            if(left + right == n) {
                if(prime[left] && prime[right]) {
                    cout << n << " = " << left << " + " << right << '\n';
                    flag = true;
                    break;
                }
                left += 2;
            }
            else if(left + right > n) {
                right-=2;
            }
            else left += 2;
        }
        if(!flag) {
            cout << "Goldbach's conjecture is wrong.\n";
        }     
    }
}