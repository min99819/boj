#include <iostream>
#include <vector>
using namespace std;
using matrix = vector<vector<long long>>;
matrix adj = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};
matrix ans = {
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}
};
matrix mul(matrix a, matrix b) {
    matrix c(8, vector<long long>(8, 0));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            for(int k=0; k<8; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000000007;
        }
    }
    return c;
}
int main() {
    int d;
    cin >> d;
    while(d > 0) {
        if(d % 2) {
            ans = mul(ans, adj);
        }
        adj = mul(adj, adj);
        d /= 2;
    }
    cout << ans[0][0];
}