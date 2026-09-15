// programmer: Micah Anderson
// date: September 15 2026
// filename: main.cpp
// description: this program contains a class that models a 24-hour clock

#include <iostream>


class Time {
    public:
        Time();

        int getHour() const;
        int getMinute() const;

        void setTime(int newHour, int newMinute);

        int toMinutes();

    private:
        int hour;
        int minute;
};

Time::Time() {
    setTime(0, 0);
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

// Function: Sets the time stored in the Time object. When the inputs are invalid sets hour to 0 and minute to 0
// Input: newHour - int - the hour you want to set the time to, the value must be between 0 and 23
//        newMinute - int - the minute you want to set the time to, the value must be between 0 and 59
// Output: Outputs the input variables to the Time object
void Time::setTime(const int newHour, const int newMinute) {
    if ((newHour <= 23 && newHour >= 0) || (newMinute <= 59 && newMinute >= 0)) {
        hour = newHour;
        minute = newMinute;
    }
    else {
        hour = 0;
        minute = 0;
    }
}

// Function: Returns the number of minutes since 0:00
// Inputs: None
// Output: int - the number of minutes since midnight
int Time::toMinutes() {
    return hour * 60 + minute;
}

int main() {
    return 0;
}