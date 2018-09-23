#include <iostream>
using namespace std;

const unsigned int Sunday = 1;

unsigned int getWeekday(unsigned long long yy, unsigned int mm, unsigned int dd){

    if (mm <= 2){
        mm += 12;
        yy--;
    }

    return (dd + 13*(mm + 1)/5 + yy + yy/4 - yy/100 + yy/400) % 7;
}

int main(){
    unsigned int tests;
    cin >> tests;
    while (tests--){
        unsigned long long year1, year2;
        unsigned int month1, month2, day1, day2;
        cin >> year1 >> month1 >> day1;
        cin >> year2 >> month2 >> day2;

        unsigned long long currentYear = year1;
        unsigned int currentMonth = month1;

        if (day1 > 1){
            currentMonth++;

            if (currentMonth > 12){
                currentMonth -= 12;
                currentYear++;
            }
        }

        unsigned int sum = 0;

        unsigned int reps = (year2 - currentYear) / 2800;
        sum += 4816 * reps;
        currentYear += 2800 * reps;

        while (currentMonth < month2 || currentYear < year2){
            if (getWeekday(currentYear, currentMonth, 1) == Sunday)
                sum++;

            currentMonth++;

            if (currentMonth > 12){
                currentMonth -= 12;
                currentYear++;
            }
        }

        if (getWeekday(currentYear, currentMonth, 1) == Sunday)
            sum++;

        cout << sum << endl;
    }
    return 0;
}
