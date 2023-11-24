#include <iostream>
#include <string>
using namespace std;
int main() {
    string title, grade;
    double credit;
    double credit_sum = 0;
    double total_sum = 0;
    for(int i=0; i<20; i++) {
        cin >> title >> credit >> grade;
        if(grade[0] == 'A') {
            if(grade[1] == '+') total_sum += (credit * 4.5);
            else total_sum += (credit * 4.0);
            credit_sum += credit;
        }   
        else if(grade[0] == 'B') {
            if(grade[1] == '+') total_sum += (credit * 3.5);
            else total_sum += credit * 3.0;
            credit_sum += credit;
        }
        else if(grade[0] == 'C') {
            if(grade[1] == '+') total_sum += (credit * 2.5);
            else total_sum += credit * 2.0;
            credit_sum += credit;
        }
        else if(grade[0] == 'D') {
            if(grade[1] == '+') total_sum += (credit * 1.5);
            else total_sum += credit * 1.0;
            credit_sum += credit;
        }
        else if(grade[0] == 'F') {
            credit_sum += credit;
        }
    }
    cout << total_sum / credit_sum;
}