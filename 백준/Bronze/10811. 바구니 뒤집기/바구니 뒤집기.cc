#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int ans[101];
    for(int i=1; i<=n; i++) {
        ans[i] = i;
    }
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        reverse(ans + x, ans + y + 1);
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}