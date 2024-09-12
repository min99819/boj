#include <iostream>
#include <algorithm>
using namespace std;
int student[1001][5];
bool flag[1001][1001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            cin >> student[i][j];
        }
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                if(j != k && student[j][i] == student[k][i]) {
                    flag[j][k] = flag[k][j] = true;
                }
            }
        }
    }
    int max_cnt = -1;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(flag[i][j]) {
                cnt++;
            }
        }
        if(max_cnt < cnt) {
            max_cnt = cnt;
            ans = i+1;
        }
    }
    cout << ans;
}