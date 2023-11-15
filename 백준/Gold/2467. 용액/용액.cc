#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int point[100001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> point[i];
    }
    int start = 0;
    int end = n - 1;
    int sum = 2000000000;
    int temp = sum;
    int ans_x, ans_y;
    while(start < end) {
        sum = point[start] + point[end];
        int flag = temp;
        temp = min(abs(temp), abs(sum));
        if(temp != flag) {
            ans_x = point[start];
            ans_y = point[end];
        }
        if(sum < 0) {
            start++;
        }
        else end--;
    }
    cout << ans_x << " " << ans_y;
}