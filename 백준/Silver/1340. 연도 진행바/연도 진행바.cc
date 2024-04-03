#include <iostream>
#include <string>
using namespace std;
int main() {
    string month, day, time;
    int year;
    cin >> month >> day >> year >> time;
    int total_time;
    bool leap_year = false;
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        total_time = 366 * 24 * 60;
        leap_year = true;
    }
    else total_time = 365 * 24 * 60;

    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string month_of_year[12] = {"January","February","March","April","May","June",
                                "July","August","September","October","November","December"};
    if(leap_year) day_of_month[1] = 29;

    int flag, current_time = 0;
    for(int i=0; i<12; i++) {
        if(month == month_of_year[i]) flag = i;
    }
    for(int i=0; i<flag; i++) {
        current_time += day_of_month[i] * 24 * 60;
    }
    
    int temp;
    temp = (day[0]-'0') * 10 + (day[1]-'0');
    current_time += (temp-1) * 24 * 60;

    temp = (time[0]-'0') * 10 * 60 + (time[1]-'0') * 60 + (time[3]-'0') * 10 + (time[4]-'0');
    current_time += temp;

    cout << fixed;
    cout.precision(10);
    cout << (double)current_time / (double)total_time * 100;
}