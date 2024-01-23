#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> card;
bool check[1000001];
int res[1000001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        card.push_back(a);
        check[a] = true;
    }
    for(int i=0; i<n; i++) {
        for(int j=card[i] * 2; j<=1000000; j += card[i]) {
            if(check[j]) {
                res[j]--;
                res[card[i]]++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << res[card[i]] << ' ';
    }
}