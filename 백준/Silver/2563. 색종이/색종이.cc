#include <iostream>
using namespace std;
int paper[100][100];
int main() {
    int n, a, b;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a >> b;
        for(int j=a; j<a+10; j++) {
            for(int k=b; k<b+10; k++) {
                if(j<=100 && k<=100) paper[j][k] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=100; i++) {
        for(int j=1; j<=100; j++) {
            if(paper[i][j] == 1) ans++;
        }
    }
    cout << ans;
}