//
// Created by Christensen, Gary E on 9/24/19.
//

#include <iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(const string &first, const string &last,
                   const Date &dateOfBirth, const Date &dateOfHire)
        : firstName{first},       // initialize firstName
          lastName{last},         // initialize lastName
          birthDate{dateOfBirth}, // initialize birthDate
          hireDate{dateOfHire}    // initialize hireDate
{
    // output Employee object to show when constructor is called
    cout << "Employee object constructor: " << firstName
         << ' ' << lastName << endl;
}

void Employee::print() const {
    cout << lastName << ", " << firstName << "  Hired: ";
    hireDate.print();
    cout << "  Birthday: ";
    birthDate.print();
}

