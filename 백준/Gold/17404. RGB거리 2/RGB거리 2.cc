#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;
int color[1001][3];
int RGB[1001][3];
int main() {
	int n;
	cin >> n;
    int ans = MAX;
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> color[i][j];
        }
    }
    for(int rgb=0; rgb<3; rgb++) {
        for(int i=0; i<3; i++) {
            if(i == rgb) {
                RGB[0][i] = color[0][i];
            }
            else RGB[0][i] = MAX;
        }
        for (int i = 1; i < n; i++) {
            RGB[i][0] = min(RGB[i - 1][1], RGB[i - 1][2]) + color[i][0];
            RGB[i][1] = min(RGB[i - 1][0], RGB[i - 1][2]) + color[i][1];
            RGB[i][2] = min(RGB[i - 1][0], RGB[i - 1][1]) + color[i][2];
        }
        for(int i=0; i<3; i++) {
            if(i != rgb) {
                ans = min(ans, RGB[n-1][i]);
            }
        }
    }
	
	cout << ans;
}