#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int cent;
        int q = 0, d = 0, n = 0, p = 0;
        cin >> cent;
        while(cent >= 25) {
            cent -= 25;
            q++;
        }
        while(cent >= 10) {
            cent -= 10;
            d++;
        }
        while(cent >= 5) {
            cent -= 5;
            n++;
        }   
        while(cent >= 1) {
            cent -= 1;
            p++;
        }
        cout << q << " " << d << " " << n << " " << p << '\n';
    }
}