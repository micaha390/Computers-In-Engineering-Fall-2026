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

void printSVGGraph(vector<int> data, double mean, double stdDev, double min, double max) {
    ofstream fout("test_file.svg"); //opens the ofstream

    //stores the size of the image and the margins
    const int SVG_WIDTH{1000}, SVG_HEIGHT{1000}, SVG_TOP{40}, SVG_BOTTOM{60}, SVG_LEFT{40}, SVG_RIGHT{40};
    const string GRAPH_COLOR{"#0074d9"}; //selects the color for the graph

    //sets the X value that each data point will increase by so the graph will fill the screen
    const double GRAPH_STEP_X = (SVG_WIDTH - SVG_LEFT - SVG_RIGHT) / static_cast<double>(data.size());
    //stretches the Y values so the lowest data point will always be at the bottom line,
    //and the highest data point at the top of the graph
    const double GRAPH_STEP_Y = (SVG_HEIGHT - SVG_BOTTOM - SVG_TOP) / (max - min);

    //takes the number of data points as the total time in seconds and converts to hours, rounding to 2 decimal places
    const double RIDE_TIME = round((data.size() / 60.0) * 100) / 100 ;

    //initializes a counter to use in the for loop
    //so we can iterate through the vector directly instead of using indices
    int count{0};

    //writes the svg file
    fout << R"(<svg version="1.1" width=")" << SVG_WIDTH << R"(" height=")" << SVG_HEIGHT << "\" ";
    fout << R"(xmlns="http://www.w3.org/2000/svg">)"<< endl;

    fout << "\t" << R"(<line x1=")" << SVG_LEFT << R"(" x2=")" << SVG_LEFT;
    fout << R"(" y1=")" << SVG_TOP << R"(" y2=")" << SVG_HEIGHT - SVG_BOTTOM << R"(" stroke=")";
    fout << GRAPH_COLOR << R"(" stroke-width="3"/>)" << endl;

    fout << "\t" << R"(<line x1=")" << SVG_LEFT << R"(" x2=")" << SVG_WIDTH - SVG_RIGHT;
    fout << R"(" y1=")" << SVG_HEIGHT - SVG_BOTTOM << R"(" y2=")" << SVG_HEIGHT - SVG_BOTTOM << R"(" stroke=")";
    fout << GRAPH_COLOR << R"(" stroke-width="3"/>)" << endl;

    fout << "\t<polyline" << endl;
    fout << "\t\t" << R"(fill="none")" << endl;
    fout << "\t\t" << R"(stroke=")" << GRAPH_COLOR << "\"" << endl;
    fout << "\t\t" << R"(stroke-width="3")" << endl;
    fout << "\t\t" << R"(points=")" << endl;

    /* iterates through the data to create the graph. each data point moves to the right by a fraction of the graph
     * that we calculated earlier so that the data fills the graph. then the Y data is shifted so all values start at 0
     * and is also scaled to the graph */
    for (auto i: data) {
        fout << "\t\t\t" << SVG_LEFT + (GRAPH_STEP_X * count) << ",";
        fout << SVG_HEIGHT - SVG_BOTTOM - ((i - min) * GRAPH_STEP_Y) << endl;
        count++;
    }

    fout << "\t\t\"/>" << endl;

    fout << "\t" << R"(<text x="5" y="10" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">mean = )" << mean << "</text>)" << endl;

    fout << "\t" << R"(<text x="5" y="25" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">std dev = )" << stdDev << "</text>)" << endl;

    fout << "\t" << R"(<text x="5" y=")" << SVG_TOP + 10 << R"(" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">)" << max << "</text>)" << endl;

    fout << "\t" << R"(<text x="5" y=")" << SVG_HEIGHT - SVG_BOTTOM << R"(" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">)" << min << "</text>)" << endl;

    fout << "\t" << R"(<text x=")" << SVG_LEFT << R"(" y=")" << SVG_HEIGHT - SVG_BOTTOM + 15;
    fout << R"(" font-family="Verdana" font-size="12" fill=")" << GRAPH_COLOR << R"(">)" << 0 << "</text>)" << endl;

    fout << "\t" << R"(<text x=")" << SVG_WIDTH - SVG_RIGHT - 10 << R"(" y=")" << SVG_HEIGHT - SVG_BOTTOM + 15;
    fout << R"(" font-family="Verdana" font-size="12" fill=")" << GRAPH_COLOR << R"(">)";
    fout << RIDE_TIME << "</text>)" << endl;

    fout << "</svg>";


    fout.close(); //closes the ofstream
}

int main() {

    // Only uncomment one ifstream command at a time
    //ifstream fin("ride_data.txt");
    ifstream fin("ride_data2.txt");
    //ifstream fin("ride_data3.txt");
    //ifstream fin("ride_data4.txt");
    //ifstream fin("ride_data5.txt");

    string temp; //store read lines from the data file before storing it in values
    vector<int> values{}; //store the data to be written to the .svg file
    bool endOfData = false; //flag to stop reading the file
    double mean{}, stdDeviation{}; //stores the mean and standard deviation of the data
    double min{numeric_limits<int>::max()}, max{}; //stores the min and max of the data,
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

    printSVGGraph(values, mean, stdDeviation, min, max);

    return 0;
}
