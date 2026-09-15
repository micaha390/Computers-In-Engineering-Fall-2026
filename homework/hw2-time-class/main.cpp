// programmer: Micah Anderson
// date: September 15 2026
// filename: main.cpp
// description: this program contains a class that models a 24-hour clock

#include <iostream>


class Time {
    public:
        Time();

        int getHour();
        int getMinute();

        void setTime(int newHour, int newMinute);

    private:
        int hour;
        int minute;
};

Time::Time() {
    hour = 0;
    minute = 0;
}

// Function: Gets the hour value currently stored in the Time object
// Input: None
// Output: hour - int - the current hour of the Time object
int Time::getHour() {
    return hour;
}

// Function: Gets the hour value currently stored in the Time object
// Input: None
// Output: hour - int - the current hour of the Time object
int Time::getMinute() {
    return minute;
}

// Function: Sets the time stored in the Time object
// Input: newHour - int - the hour you want to set the time to, the value must be between 0 and 23
//        newMinute - int - the minute you want to set the time to, the value must be between 0 and 59
// Output: None
void Time::setTime(int newHour, int newMinute) {
    if ((newHour <= 23 && newHour >= 0) || (newMinute <= 59 && newMinute >= 0)) {
        hour = newHour;
        minute = newMinute;
    }
    else {
        hour = 0;
        minute = 0;
    }
}

int main() {
    return 0;
}