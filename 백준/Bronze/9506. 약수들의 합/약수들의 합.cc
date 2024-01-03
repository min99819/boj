#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    while(1) {
        cin >> n;
        if(n == -1) {
            break;
        }
        vector<int> v;
        int sum = 0;
        for(int i=1; i<n; i++) {
            if(n % i == 0) {
                v.push_back(i);
                sum += i;
            }
        }
        cout << n << " ";
        if(sum != n) {
            cout << "is NOT perfect." << '\n';
        }
        else {
            cout << "= ";
            for(int i=0; i<v.size(); i++) {
                if(i == v.size() - 1) {
                    cout << v[i];
                }
                else cout << v[i] << " + ";
            }
            cout << '\n';
        }
    }
}