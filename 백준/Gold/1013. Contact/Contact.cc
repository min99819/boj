#include <iostream>
#include <regex>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        regex e("\\b(100+1+|01)+\\b");
        if(regex_match(s, e)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}