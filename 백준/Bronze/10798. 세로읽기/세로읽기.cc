#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    for(int i=0; i<15; i++) {
        if(i < a.length()) cout << a[i];
        if(i < b.length()) cout << b[i];
        if(i < c.length()) cout << c[i];
        if(i < d.length()) cout << d[i];
        if(i < e.length()) cout << e[i];
    }
}