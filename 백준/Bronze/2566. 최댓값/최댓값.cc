#include <iostream>
using namespace std;
int main() {
    int matrix[9][9];
    int max_num = 0;
    int x, y;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> matrix[i][j];
            if (max_num <= matrix[i][j]) {
                max_num = matrix[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << max_num << '\n' << x + 1 << ' ' << y + 1;
}