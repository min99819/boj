#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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
    string ans_str = "";
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
    int i = s1.length() - 1, j = s2.length() - 1;
    int cnt = ans;
    while(i > 0 && j > 0 && cnt > 0) {
        if(lcs[i][j] == lcs[i-1][j]) {
            i--;
        }
        else if(lcs[i][j] == lcs[i][j-1]) {
            j--;
        }
        else {
            ans_str += s1[i];
            i--;
            j--;
            cnt--;
        }
    }
    reverse(ans_str.begin(), ans_str.end());
    cout << ans << '\n' << ans_str;
}