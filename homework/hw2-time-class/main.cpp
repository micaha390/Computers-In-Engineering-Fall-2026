// programmer: Micah Anderson
// date: September 15 2026
// filename: main.cpp
// description: this program contains a class that models a 24-hour clock

#include <iostream>

class Time {
    public:
        Time();
    private:
        int hour;
        int minute;
};

Time::Time() {
    hour = 0;
    minute = 0;
}

int main() {
    return 0;
}