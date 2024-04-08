#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k;
char c[10];
bool is_visit[10];
string max_ans = "0";
string min_ans = "9876543210";

bool check_sign(char a, char b, char sign) {
    if(sign == '>') {
        if(a > b) return true;
        else return false;
    }
    else {
        if(a < b) return true;
        else return false;
    }
}

void dfs(int cnt, string num) {
    if(cnt == k+1) {
        max_ans = max(max_ans, num);
        min_ans = min(min_ans, num);
    }
    for(int i=0; i<=9; i++) {
        if(!is_visit[i]) {
            if(cnt == 0 || check_sign(num[cnt-1], i+'0', c[cnt-1])) {
                is_visit[i] = true;
                dfs(cnt+1, num + to_string(i));
                is_visit[i] = false;
            }
        }
    }
}

int main() {
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> c[i];
    }
    dfs(0, "");
    cout << max_ans << '\n' << min_ans;
}