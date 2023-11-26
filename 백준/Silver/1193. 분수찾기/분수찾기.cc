#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    int x;
    cin >> x;
    int a=1, b=2;
    int last = 2;
    int cnt = 1;
    int flag = 1;
    if(x == 1) cout << "1/1";
    else {
        for(int i=3; i<=x; i++) {
            if(cnt < last) {
                if(flag > 0) {
                    a++;
                    b--;
                }
                else {
                    a--;
                    b++;
                }
                cnt++;
            }
            else if(cnt == last) {
                if(flag > 0) a++;
                else b++;
                flag *= -1;
                last++;
                cnt = 1;
            }
        }
        cout << a << '/' << b;
    }
}