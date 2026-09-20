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
        void printTwelveHour() const;
        int toMinutes() const;
    private:
        int hour;
        int minute;
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

// Function: Sets the time stored in the Time object. When the either input is invalid sets hour to 0 and minute to 0
// Input: newHour - int - the hour you want to set the time to, the value should be between 0 and 23
//        newMinute - int - the minute you want to set the time to, the value should be between 0 and 59
// Output: Outputs the input variables to the Time object
void Time::setTime(const int newHour, const int newMinute) {
    if ((newHour <= 23 && newHour >= 0) && (newMinute <= 59 && newMinute >= 0)) {
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

void Time::printTwelveHour() const {
    if (hour > 12) {
        cout << hour - 12 << ":" << minute << " PM";
    }
    else {
        cout << hour << ":" << minute << " AM";
    }
}

// Function: Takes 2 Time objects and returns the time in minutes between the 2 clocks
// Inputs: clock1 - Time - A Time object representing a 24hr clock
//         clock2 - Time - A Time object representing a 24hr clock
// Outputs: int - The time in minutes between the 2 Time objects
int timeBetweenClocks(Time clock1, Time clock2) {
    return abs(clock1.toMinutes() - clock2.toMinutes());
}

int main() {
    Time clockA(7, 30);
    // test 1: testing the constructor and toMinutes method
    if (clockA.toMinutes() == 450) {
        cout << "Test passed, 7:30 is 450 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 7:30 should be 450 minutes passed midnight, not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    // test 2: testing the setTime method
    clockA.setTime(9, 15);
    if (clockA.toMinutes() == 555) {
        cout << "Test passed, 9:15 is 555 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 9:15 should be 555 minutes passed midnight, not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    Time clockB(-1, 45);
    // test 3: testing an invalid input for the constructor/setTime method
    if (clockB.toMinutes() == 0) {
        cout << "Test passed, both hours and minutes are set to 0 when the setTime method is given an invalid input";
    }
    else {
        cout << "Test failed, setTime does not correctly set both member variables to 0 when either input is invalid, ";
        cout << endl << "clock is set to " << clockB.toMinutes() << " minutes passed midnight.";
    }
    cout << endl;
    // test 4: checking the setTime method when given an invalid input for the minutes
    clockB.setTime(17, 60);
    if (clockB.toMinutes() == 0) {
        cout << "Test passed, both hours and minutes are set to 0 when the setTime method is given an invalid input";
    }
    else {
        cout << "Test failed, setTime does not correctly set both member variables to 0 when either input is invalid, ";
        cout << endl << "clock is set to " << clockB.toMinutes() << " minutes passed midnight.";
    }
    cout << endl;
    // test 5: testing border cases for setTime
    clockA.setTime(0, 0);
    if (clockA.toMinutes() == 0) {
        cout << "Test passed, 0:00 is 0 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 0:00 should be 0 minutes passed midnight, not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    // test 6: testing additional border cases for setTime
    clockB.setTime(23, 59);
    if (clockB.toMinutes() == 1439) {
        cout << "Test passed, 23:59 is 1439 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 23:59 should be 1439, not " << clockB.toMinutes() << ".";
    }
    cout << endl;
    // test 7: testing the toMinutes method
    clockA.setTime(17, 56);
    if (clockA.toMinutes() == 1076) {
        cout << "Test passed, 17:56 is 1076 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 17:56 should be 1076, not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    // test 8: testing the addMinutes method
    clockA.setTime(9, 52);
    clockA.addMinutes(1000);
    if (clockA.toMinutes() == 152) {
        cout << "Test passed, 9:52 + 1000 minutes is 152 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 9:52 + 1000 minutes should be 152 minutes passed midnight";
        cout << ", not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    // test 9: testing the subtractMinutes method
    clockA.setTime(0, 17);
    clockA.subtractMinutes(18);
    if (clockA.toMinutes() == 1439) {
        cout << "Test passed, 0:17 - 18 minutes is 1439 minutes passed midnight.";
    }
    else {
        cout << "Test failed, 0:17 - 18 minutes should be 1439 minutes passed midnight,";
        cout << " not " << clockA.toMinutes() << ".";
    }
    cout << endl;
    // test 10: testing the timeBetweenClocks method
    clockA.setTime(7, 30);
    clockB.setTime(12, 59);
    if (timeBetweenClocks(clockA, clockB) == 329) {
        cout << "Test passed, there are 329 minutes between clockA and clockB";
    }
    else {
        cout << "Test failed, there should be 329 minutes between clockA and clockB, ";
        cout << "not " << abs(clockA.toMinutes() - clockB.toMinutes()) << ".";
    }
    cout << endl;
    return 0;
}