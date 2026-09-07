//
// Programmer: Micah Anderson
// Date: 9/5/2026
// Filename: main.cpp
// Description: This program takes a .txt file that contains a formatted list of data points, then makes a .svg file
// that displays a graph of the data, along with the mean and standard deviation
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function: Calculates the mean of a vector of ints
// Input: data - vector<int> - a vector containing all data points that are going to be graphed
// Output: mean - double - the mean of the input data, rounded to 1 decimal place
double calculateMean(const vector<int> &data) {
    double mean{0.0};

    for (auto i: data) {
        mean += i;
    }

    mean = round(mean / data.size() * 10) / 10;

    return mean;
}

// Function: Calculates the standard deviation of a vector of ints
// Input: data - vector<int> - a vector containing all data points that are going to be graphed
//        mean - double - a double containing the mean value of the data
// Output: mean - double - the standard deviation of the input data, rounded to 1 decimal place
double calculateStdDev(const vector<int> &data, const double mean) {
    double stdDev{0.0};

    for (auto i : data) {
        stdDev += pow((i - mean), 2);
    }

    stdDev = round(sqrt(stdDev / data.size()) * 10) / 10;

    return stdDev;
}

// Function: Returns the maximum value of a vector of ints
// Input: data - vector<int> - a vector containing all data points that are going to be graphed
// Output: max - int - the largest value contained in the input vector
int calculateMax(const vector<int> &data) {
    int max{0};

    for (auto i: data) {
        if (i > max) {
            max = i;
        }
    }

    return max;
}

// Function: Returns the minimum value of a vector of ints
// Input: data - vector<int> - a vector containing all data points that are going to be graphed
// Output: min - int - the smallest value contained in the input vector
int calculateMin(const vector<int> &data) {
    int min{numeric_limits<int>::max()};

    for (auto i: data) {
        if (i < min) {
            min = i;
        }
    }

    return min;
}

// Function: Retrieves data from a formatted .txt file
// Input: fin - ifstream - an ifstream object reading from the file containing the data that is going to be graphed
// Output: data - vector<int> - the data that is going to be graphed
vector<int> readData(ifstream &fin) {
    vector<int> data; //return variable
    string temp; //store read lines from the data file before storing it in values

    fin >> temp;
    fin >> temp; //gets the first 2 inputs to skip the first '['

    while (temp[0] != '[') { //moves the ifstream object to the start of the data
        fin >> temp;
    }
    temp.erase(0, 1); //removes the '[' from the temp variable

    while (temp.back() != ']' && !fin.eof()) { //reads from the input file as long as there is still data in the file
        data.push_back(stoi(temp)); //stores the data point
        getline(fin, temp, ','); //gets data from the file that is separated by a comma
        temp.erase(0, 1); //removes the space before saving the data to values
    }

    temp.pop_back();  //removes the final ']'
    data.push_back(stoi(temp)); //adds the final data point to the vector

    fin.close();

    return data;
}

// Function: Takes data and creates a graph using a .svg file displaying it
// Input: data - vector<int> - a vector containing all data points that are going to be graphed
//        mean - double - a double containing the mean value of the data
//        stdDev - double - a double containing the standard deviation of the data
//        min - int - the smallest value in data
//        max - int - the largest value in data
// Output: Writes a .svg file that creates a graph of the data
void printSVGGraph(const vector<int> &data, const double mean, const double stdDev, const int min, const int max) {
    ofstream fout("output_graph.svg");

    //stores the size of the image and the margins
    constexpr int SVG_WIDTH{1000}, SVG_HEIGHT{500}, SVG_TOP{60}, SVG_BOTTOM{40}, SVG_LEFT{40}, SVG_RIGHT{40};
    const string GRAPH_COLOR{"#0074d9"}; //selects the color for the graph

    //sets the X position of the mean, std dev, min, and max,
    //and ensures they don't go off the screen if the margins are smaller than 35
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


    fout.close();
}

int main() {
    // Only uncomment one ifstream command at a time
    ifstream fin("ride_data.txt");
    // ifstream fin("ride_data2.txt");
    // ifstream fin("ride_data3.txt");
    // ifstream fin("ride_data4.txt");
    // ifstream fin("ride_data5.txt");

    vector<int> values; // stores the data to be written to the .svg file
    double mean{0.0}, stdDeviation{0.0};
    int min{0}, max{0};

    values = readData(fin);
    mean = calculateMean(values);
    stdDeviation = calculateStdDev(values, mean);
    max = calculateMax(values);
    min = calculateMin(values);

    printSVGGraph(values, mean, stdDeviation, min, max);

    return 0;
}