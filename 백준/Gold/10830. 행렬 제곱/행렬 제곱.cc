#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int> > matrix;
int n;
matrix matrix_pow(matrix &A, matrix &B) {
    matrix C(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        C[i][j] %= 1000;
        }
    }

    return C;
}

int main() {
    long long b;
    cin >> n >> b;
    matrix A(n, vector<int>(n,0));
    matrix ans(n, vector<int>(n,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            A[i][j] = x;
        }
        ans[i][i] = 1;
    }
    while(b > 0) {
        if(b%2 == 1) {
            ans = matrix_pow(ans, A);
        }
        A = matrix_pow(A, A);
        b /= 2;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}