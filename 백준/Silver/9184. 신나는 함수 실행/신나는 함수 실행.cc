#include <iostream>
using namespace std;
int res[21][21][21];
int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) return 1;
    else if(a>20 || b>20 || c>20) {
        return w(20, 20, 20);
    }
    else if(res[a][b][c] != 0) return res[a][b][c];
    else if(a<b && b<c) {
        res[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return res[a][b][c];
    }
    else {
        res[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return res[a][b][c];
    }
}
int main() {
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}