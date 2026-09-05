//
// Programmer:
// Date:
// Filename:
// Description:
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    // Only uncomment one ifstream command at a time
    ifstream fin("ride_data.txt");
    //ifstream fin("ride_data2.txt");
    //ifstream fin("ride_data3.txt");
    //ifstream fin("ride_data4.txt");
    //ifstream fin("ride_data5.txt");

    string temp;
    vector<int> values{};

    while (!fin.eof()) {
        fin >> temp;
        fin >> temp;
        if (temp[0] == '[') {
            std::cout << "TESTTEST";
            while (temp.back() != ']' && !fin.eof()) {
                getline(fin, temp, ',');
                if (temp.back() == ']') {
                    cout << "TEST" << endl;
                    temp.pop_back();
                }
                cout << temp << endl;
            }
        }
    }


    cout << "Hello, World!" << endl;

    return 0;
}
