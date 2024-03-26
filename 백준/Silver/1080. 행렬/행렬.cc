#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int matrix[50][50];
    int res[50][50];
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            matrix[i][j] = s[j] - '0';
        }
    }
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            res[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m-2; j++) {
            if(matrix[i][j] != res[i][j]) {
                for(int x=i; x<i+3; x++) {
                    for(int y=j; y<j+3; y++) {
                        matrix[x][y] = 1 - matrix[x][y]; 
                    }
                }
                ans++;
            }
        }
    }
    bool flag = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] != res[i][j]) {
                cout << -1;
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag) cout << ans;
}