#include <iostream>
using namespace std;
int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int x, y;
    int res_x, res_y;
    for(int i=-999; i<1000; i++) {
        for(int j=-999; j<1000; j++) {
            if(a * i + b * j == c) {
                if(d * i + e * j == f) {
                    res_x = i;
                    res_y = j;
                }
            }
        }
    }
    cout << res_x << " " << res_y;
}