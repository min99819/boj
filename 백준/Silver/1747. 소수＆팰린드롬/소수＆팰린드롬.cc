#include <iostream>
#include <vector>
#include <string>
using namespace std;
int v[2000001];
int main() {
    int n;
    cin >> n;
    vector<int> prime;
    for(int i=2; i*i<=2000000; i++) {
        if(!v[i]) {
            for(int j=i*i; j<=2000000; j+=i) {
                v[j] = 1;
            }
        }
    }
    v[1] = 1;
    for(int i=n; i<=2000000; i++) {
        if(!v[i]) prime.push_back(i);
    }
    for(int i=0; i<prime.size(); i++) {
        string num = to_string(prime[i]);
        bool flag = true;
        for(int j=0; j<num.length()/2; j++) {
            if(num[j] != num[num.length() - j - 1]) flag = false;
        }
        if(flag) {
            cout << prime[i];
            break;
        }
    }
    return 0;
}