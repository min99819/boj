#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int start = 0;
    int end = s.size()-1;
    int cnt = 0;
    while(start <= end) {
        if(s.size() == 1) {
            cout << 1;
            break;
        }
        if(s[start] == s[end]) {
            cnt++;
            if(cnt == s.size()/2) {
                cout << 1;
                break;
            }
        }
        else {
            cout << 0;
            break;
        }
        start++;
        end--;
    }
}