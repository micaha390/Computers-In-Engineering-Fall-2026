// programmer: Micah Anderson
// date: September 15 2026
// filename: main.cpp
// description: this program contains a class that models a 24-hour clock

#include <iostream>

using namespace std;

class Time {
    public:
        Time(int newHour = 0, int newMinute = 0);

        int getHour() const;
        int getMinute() const;

        void setTime(int newHour, int newMinute);


        void addMinutes(int minutes);
        void subtractMinutes(int minutes);
        void print() const;

    private:
        int hour;
        int minute;
        int toMinutes() const;
};

Time::Time(const int newHour, const int newMinute) {
    setTime(newHour, newMinute);
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
int Time::toMinutes() const {
    return hour * 60 + minute;
}

// Function: Takes a non-negative number of minutes less than 24hrs from the user and increases the time on the clock,
//           wrapping around if the new time is greater than or equal to 24hrs
// Inputs: minutes - int - the number of minutes you want to add to the clock
// Outputs: Changes the value of hour and minute for the Time object to match the new time
void Time::addMinutes(const int minutes) {
    if (minutes < 1440 && minutes > 0) {
        int currentMinutes = toMinutes() + minutes;
        if (currentMinutes >= 1440) {
            currentMinutes -= 1440;
        }
        setTime(currentMinutes / 60, currentMinutes % 60);
    }
}

// Function: Takes a non-negative number of minutes less than 24hrs from the user and reduces the time on the clock,
//           wrapping around if the new time is greater than or equal to 24hrs
// Inputs: minutes - int - the number of minutes you want to subtract from the clock
// Outputs: Changes the value of hour and minute for the Time object to match the new time
void Time::subtractMinutes(const int minutes) {
    if (minutes < 1440 && minutes > 0) { // Subtracts 24hrs from the clock until the time is less than 24hrs
        int currentMinutes = toMinutes() - minutes;
        if (currentMinutes < 0) {
            currentMinutes += 1440;
        }
        setTime(currentMinutes / 60, currentMinutes % 60);
    }}

// Function: Prints the current time to the console in 24-hour time
// Inputs: None
// Outputs: Prints the time to the console in the xx:xx format
void Time::print() const {
    cout << hour << ":" << minute;
}

int main() {
    Time clock{};
    clock.print();
    cout << endl;
    clock.setTime(9, 28);
    clock.print();
    cout << endl << clock.toMinutes() << endl;
    clock.setTime(clock.getHour(), 40);
    clock.print();
    cout << endl;
    clock.setTime(7, clock.getMinute());
    clock.print();
    cout << endl;
    clock.addMinutes(1818);
    clock.print();
    cout << endl;
    clock.setTime(23, 50);
    clock.print();
    cout << endl;
    clock.addMinutes(20);
    clock.print();
    cout << endl;
    clock.subtractMinutes(80);
    clock.print();
    cout << endl;
    return 0;
}