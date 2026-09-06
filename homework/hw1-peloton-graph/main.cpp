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

//takes a vector of ints and returns the mean, rounded to 1 decimal place
double calculateMean(vector<int> data) {
    double mean{};
    for (auto i: data) {
        mean += i;
    }
    mean = round(mean / data.size() * 10) / 10;
    return mean;
}

//takes a vector of ints and a mean, and returns the standard deviation
double calculateStdDev(vector<int> data, double mean) {
    double stdDev{};

    for (auto i : data) {
        stdDev += pow((i - mean), 2);
    }

    stdDev = round(sqrt(stdDev / data.size()) * 10) / 10;

    return stdDev;
}

//takes a vector of ints and returns the max value
int calculateMax(vector<int> data) {
    int max{};

    for (auto i: data) {
        if (i > max) {
            max = i;
        }
    }

    return max;
}

//takes a vector of ints and returns the min value
int calculateMin(vector<int> data) {
    int min{numeric_limits<int>::max()};

    for (auto i: data) {
        if (i < min) {
            min = i;
        }
    }

    return min;
}

//takes an ifstream object for a properly formatted .txt file and returns a vector of ints
vector<int> readData(ifstream &fin) {
    vector<int> data;
    string temp; //store read lines from the data file before storing it in values
    bool endOfData = false; //flag to stop reading the file

    while (!fin.eof()) { //reads from the input file as long as there is still data in the file
        fin >> temp;
        fin >> temp; //gets the first 2 lines to skip the first '['
        if (temp[0] == '[') { //starts saving data to values once the ifstream object gets to the second '['
            temp.erase(0, 1); //removes the '[' from the temp variable
            int findSeperator = temp.find(','); //finds the comma to remove it from the temp variable
            temp.erase(findSeperator, 1); //removes the comma from the temp variable
            data.push_back(stoi(temp)); //stores the first data point
            /* reads from the file until the ifstream reaches the closing ']' of the data we are reading or the end of
            the file is reached */
            while (temp.back() != ']' && !fin.eof()) {
                getline(fin, temp, ','); //gets data from the file that is separated by a comma
                temp.erase(0, 1); //removes the comma before saving the data to values
                if (temp.back() == ']') { //checks if there is a closing ']'
                    temp.pop_back(); //removes the closing ']'
                    data.push_back(stoi(temp)); //adds the data to values
                    endOfData = true; //changes the flag to indicate the end of the data was reached
                    break; //exits the while loop because the end of the data was reached
                }
                data.push_back(stoi(temp)); //adds the data point to values
            }
        }
        if (endOfData) { //if the end of data was reached, closes the ifstream and exits the while loop
            fin.close();
            break;
        }
    }

    return data;
}

//takes the data and calculated values for the data and prints a .svg file to display a graph
void printSVGGraph(vector<int> data, double mean, double stdDev, int min, int max) {
    ofstream fout("test_file.svg"); //opens the ofstream

    //stores the size of the image and the margins
    const int SVG_WIDTH{1000}, SVG_HEIGHT{500}, SVG_TOP{60}, SVG_BOTTOM{40}, SVG_LEFT{40}, SVG_RIGHT{40};
    const string GRAPH_COLOR{"#0074d9"}; //selects the color for the graph

    //sets the X position of the mean, std dev, min, and max,
    //and ensures they don't go off the screen if the margins are small
    int textXPos = SVG_LEFT - 35;
    if (textXPos < 0) {
        textXPos = 0;
    }

    //sets the X value that each data point will increase by so the graph will fill the screen
    const double GRAPH_STEP_X = (SVG_WIDTH - SVG_LEFT - SVG_RIGHT) / static_cast<double>(data.size());
    //stretches the Y values so the lowest data point will always be at the bottom line,
    //and the highest data point at the top of the graph
    const double GRAPH_STEP_Y = static_cast<double>(SVG_HEIGHT - SVG_BOTTOM - SVG_TOP) / (max - min);

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

    fout << "\t" << R"(<text x=")" << textXPos << R"(" y="10" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">mean = )" << mean << "</text>)" << endl;

    fout << "\t" << R"(<text x=")" << textXPos << R"(" y="25" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">std dev = )" << stdDev << "</text>)" << endl;

    fout << "\t" << R"(<text x=")" << textXPos << R"(" y=")" << SVG_TOP + 10 << R"(" font-family="Verdana" font-size="12")";
    fout << R"( fill=")" << GRAPH_COLOR << R"(">)" << max << "</text>)" << endl;

    fout << "\t" << R"(<text x=")" << textXPos << R"(" y=")" << SVG_HEIGHT - SVG_BOTTOM << R"(" font-family="Verdana" font-size="12")";
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
    // ifstream fin("ride_data.txt");
    // ifstream fin("ride_data2.txt");
    ifstream fin("ride_data3.txt");
    // ifstream fin("ride_data4.txt");
    // ifstream fin("ride_data5.txt");

    vector<int> values{}; //store the data to be written to the .svg file
    double mean{}, stdDeviation{}; //stores the mean and standard deviation of the data
    int min{}, max{}; //stores the min and max of the data

    values = readData(fin);

    mean = calculateMean(values);
    stdDeviation = calculateStdDev(values, mean);
    max = calculateMax(values);
    min = calculateMin(values);

    printSVGGraph(values, mean, stdDeviation, min, max);

    return 0;
}