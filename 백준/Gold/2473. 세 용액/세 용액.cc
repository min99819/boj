#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long point[100001];
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> point[i];
    }
    sort(point, point+n);
    long long sum = 3000000000;
    long long temp = sum;
    long long ans_x, ans_y, ans_z;
    for(int i=0; i<n-2; i++) {
        int start = i+1;
        int end = n - 1;
        while(start < end) {
            sum = point[i] + point[start] + point[end];
            long long flag = temp;
            temp = min(abs(temp), abs(sum));
            if(temp != flag) {
                ans_x = point[i];
                ans_y = point[start];
                ans_z = point[end];
        }
        if(sum < 0) {
            start++;
        }
        else end--;
    }
    }
    cout << ans_x << " " << ans_y << " " << ans_z;
}