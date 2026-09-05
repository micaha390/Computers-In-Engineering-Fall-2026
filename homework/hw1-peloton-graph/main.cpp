//
// Programmer: Micah Anderson
// Date: 9/5/2026
// Filename: Peloton Data Graphing Utility
// Description: Takes a .txt fil
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

    string temp; //store read lines from the data file before storing it in values
    vector<int> values{}; //store the data to be written to the .svg file
    bool endOfData = false; //flag to stop reading the file

    while (!fin.eof()) { //reads from the input file as long as there is still data in the file
        fin >> temp;
        fin >> temp; //gets the first 2 lines to skip the first '['
        if (temp[0] == '[') { //starts saving data to values once the ifstream object gets to the second '['
            temp.erase(0, 1); //removes the '[' from the temp variable
            int findSeperator = temp.find(','); //finds the comma to remove it from the temp variable
            temp.erase(findSeperator, 1); //removes the comma from the temp variable
            values.push_back(stoi(temp)); //stores the first data point
            /* reads from the file until the ifstream reaches the closing ']' of the data we are reading or the end of
            the file is reached */
            while (temp.back() != ']' && !fin.eof()) {
                getline(fin, temp, ','); //gets data from the file that is separated by a comma
                temp.erase(0, 1); //removes the comma before saving the data to values
                if (temp.back() == ']') { //checks if there is a closing ']'
                    temp.pop_back(); //removes the closing ']'
                    values.push_back(stoi(temp)); //adds the data to values
                    endOfData = true; //changes the flag to indicate the end of the data was reached
                    break; //exits the while loop because the end of the data was reached
                }
                values.push_back(stoi(temp)); //adds the data point to values
            }
        }
        if (endOfData) { //if the end of data was reached, closes the ifstream and exits the while loop
            fin.close();
            break;
        }
    }

    int tempval{};
    for (auto data:values) {
        cout << data << endl;
        tempval++;
        cout << tempval << endl;
    }

    cout << values.size() << endl;

    return 0;
}
