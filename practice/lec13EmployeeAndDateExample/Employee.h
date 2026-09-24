//
// Created by Christensen, Gary E on 9/24/19.
//

#ifndef LEC08C_EMPLOYEE_H
#define LEC08C_EMPLOYEE_H

#include <string>
#include "Date.h"

using namespace std;

class Employee
{
public:
    Employee( const string &first, const string &last,
              const Date &dateOfBirth, const Date &dateOfHire );
    void print() const;

private:
    string firstName;       // member object
    string lastName;        // member object
    const Date birthDate;   // constant member object
    const Date hireDate;    // constant member object
};

#endif //LEC08C_EMPLOYEE_H
