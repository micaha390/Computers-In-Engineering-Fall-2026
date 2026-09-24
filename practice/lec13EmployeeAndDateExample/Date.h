//
// Created by Christensen, Gary E on 9/24/19.
//

#ifndef LEC08C_DATE_H
#define LEC08C_DATE_H

class Date
{
public:
    static const int monthsPerYear = 12;            // number of months in a year

    Date (int mn = 1, int dy = 1, int yr = 1900);   // constructors
    void print() const;                             // print date in month/day/year format
private:
    int month;      // 1-12 (January-December)
    int day;        // 1-31 based on month
    int year;       // any year

    // utility function to check if day is proper for month and year
    int checkDay( int testDay ) const;
};

#endif
