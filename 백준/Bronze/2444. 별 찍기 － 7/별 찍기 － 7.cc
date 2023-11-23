#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a = 1;
        while(a <= (n-i-1)) {
            cout << " ";
            a++;
        }
        a = 1;
        while(a <= (2*i + 1)) {
            cout << "*";
            a++;
        }
        cout << '\n';
    }
    for(int i=n-2; i>=0; i--) {
        int a = 1;
        while(a <= (n-i-1)) {
            cout << " ";
            a++;
        }
        a = 1;
        while(a <= (2*i + 1)) {
            cout << "*";
            a++;
        }
        cout << '\n';
    }
}