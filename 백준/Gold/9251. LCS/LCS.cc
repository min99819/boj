#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int lcs[1001][1001];
int main() {
    string s1, s2;
    s1 = ' ';
    s2 = ' ';
    string a, b;
    cin >> a >> b;
    s1 += a;
    s2 += b;
    int ans = 0;
    for(int i=0; i<s1.length(); i++) {
        for(int j=0; j<s2.length(); j++) {
            if(i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if(s1[i] == s2[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
            ans = max(ans, lcs[i][j]);
        }
    }
    cout << ans;
}