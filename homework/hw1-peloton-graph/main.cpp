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

void printSVGGraph() {
    ofstream fout("test_file.svg"); //opens the ofstream

    const int svgWidth{1000}, svgHeight{500}, svgTop{20}, svgBottom{60}, svgLeft{80}, svgRight{50};
    //stores the size of the image and the margins

    //writes the svg file
    fout << R"(<svg version="1.1" width=")" << svgWidth << R"(" height=")" << svgHeight << "\" ";
    fout << R"(xmlns="http://www.w3.org/2000/svg">)"<< endl;
    fout << "\t" << R"(<line x1="60" x2="60" y1="80" y2="393" stroke="#0074d9" stroke-width="3"/>)" << endl;
    fout << "\t" << R"(<line x1="60" x2="500" y1="393" y2="393" stroke="#0074d9" stroke-width="3"/>)" << endl;
    fout << "\t" << "<polyline" << endl;
    fout << "\t\t" << R"(fill="none")" << endl;
    fout << "\t\t" << R"(stroke="#0074d9")" << endl;
    fout << "\t\t" << R"(stroke-width="3")" << endl;
    fout << "\t\t" << R"(points=")" << endl;
    fout << "\t\t\t" << "80,80" << endl;
    fout << "\t\t\t" << "80,80" << endl;
    fout << "\t\t\t" << "80,80" << endl;
    fout << "\t\t\t" << "80,80/>" << endl;
    fout << "\t" << R"(<text x="0" y="20" font-family="Verdana" font-size="12" fill="blue">mean = 260.1</text>)" << endl;
    fout << "\t" << R"(<text x="0" y="40" font-family="Verdana" font-size="12" fill="blue">std dev = 52.7</text>)" << endl;
    fout << "\t" << R"(<text x="0" y="75" font-family="Verdana" font-size="12" fill="blue">388.0</text>)" << endl;
    fout << "\t" << R"(<text x="0" y="393" font-family="Verdana" font-size="12" fill="blue">75.0</text>)" << endl;
    fout << "\t" << R"(<text x="45" y="408" font-family="Verdana" font-size="12" fill="blue">0.0</text>)" << endl;
    fout << "\t" << R"(<text x="480" y="408" font-family="Verdana" font-size="12" fill="blue">60.0</text>)" << endl;
    fout << "</svg>";


    fout.close(); //closes the ofstream
}

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
    double mean{}, stdDeviation{}; //stores the mean and standard deviation of the data
    int min{numeric_limits<int>::max()}, max{}; //stores the min and max of the data,
                                                //min is initialized to the largest value for an int


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

    for (auto value : values) { //loops through the values
        mean += value; //sums all of the values
        if (value > max) {
            max = value; //sets the max to the largest found value
        }
        if (value < min) {
            min = value; //sets the min to the smallest found value
        }
    }

    mean = round(mean / values.size() * 10) / 10; //calculates the mean and rounds to 1 decimal place

    for (auto value : values) {
        stdDeviation += pow((value - mean), 2); //sums the squares of value - mean
    }

    stdDeviation = round(sqrt(stdDeviation / values.size()) * 10) / 10; //calculates the standard deviation
                                                                           //and rounds to one decimal place

    cout << mean << endl;
    cout << min << endl;
    cout << max << endl;
    cout << stdDeviation << endl;

    printSVGGraph();

    return 0;
}
