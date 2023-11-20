#include <iostream>
using namespace std;
int arr[2001];
int is_palindrome[2001][2001];
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        is_palindrome[i][i] = 1;
        if(i > 1 && arr[i-1] == arr[i]) {
            is_palindrome[i-1][i] = 1;
        }
    }
    for(int i=2; i<=n-1; i++) {
        for(int j=1; i+j<=n; j++) {
            int left = j;
            int right = i + j;
            if(arr[left] == arr[right] && is_palindrome[left+1][right-1]) {
                is_palindrome[left][right] = 1;
            }
        }
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << is_palindrome[a][b] << '\n';
    }
}