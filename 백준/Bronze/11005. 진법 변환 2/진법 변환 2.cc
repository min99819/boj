#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int n, b;
    vector<char> tmp;
    string ans;
    cin >> n >> b;
    while(n > 0) {
        if(n % b < 10) {
            tmp.push_back(n % b + '0');
        }
        else tmp.push_back((n % b - 10) + 'A');
        n /= b;
    }
    for(int i=tmp.size() - 1; i>=0; i--) {
        cout << tmp[i];
    }
}