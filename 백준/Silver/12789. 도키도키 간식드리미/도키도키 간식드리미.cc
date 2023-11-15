#include <iostream>
#include <stack>
using namespace std;
int student[1002];
int main() {
    int n;
    cin >> n;
    stack<int> s;
    int order = 1;
    for(int i=1; i<=n; i++) {
        cin >> student[i];
    }
    for(int i=1; i<=n; i++) {
        while(!s.empty() && s.top() == order) {
            order++;
            s.pop();
        }

        if(student[i] != order && student[i] > 0) {
            s.push(student[i]);
            student[i] *= -1;
        }
        else if(student[i] == order){
            student[i] *= -1;
            order++;
        }  
    }
    while(!s.empty()) {
        int next = s.top();
        s.pop();
        if(next == order) {
            order++;
        }
    }
    if(order - 1 == n) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
}