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
    vector<double> values{};
    bool endOfData = false;

    while (!fin.eof()) {
        fin >> temp;
        fin >> temp;
        if (temp[0] == '[') {
            temp.erase(0, 1);
            int findSeperator = temp.find(',');
            temp.erase(findSeperator, 1);
            while (temp.back() != ']' && !fin.eof()) {
                getline(fin, temp, ',');
                temp.erase(0, 1);
                if (temp.back() == ']') {
                    cout << "!!!!" << endl;
                    temp.pop_back();
                    values.push_back(stod(temp));
                    endOfData = true;
                    break;
                }
                values.push_back(stod(temp));
            }
        }
        if (endOfData) {
            break;
        }
    }
    int tempval{};
    for (auto data:values) {
        cout << data << endl;
        tempval++;
        cout << tempval << endl;
    }

    cout << "Hello, World!" << endl;
    cout << values.size() << endl;

    return 0;
}
