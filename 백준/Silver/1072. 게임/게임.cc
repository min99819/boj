#include <iostream>
#include <ctime>
using namespace std;
int main() {
    long long x, y;
    cin >> x >> y;
    long long z = (y * 100) / x;
    int cnt = 0;
    if(z >= 99) {
        cout << -1 << '\n';
        return 0;
    }
    int start = 0, end = 1000000000;
    while(start <= end) {
        int shwoa = (start + end) / 2;
        int woaldjqtdj = ((y+shwoa) * 100) / (x+shwoa);
        if(woaldjqtdj > z) end = shwoa-1;
        else start = shwoa+1;
    }
    cout << start;
}