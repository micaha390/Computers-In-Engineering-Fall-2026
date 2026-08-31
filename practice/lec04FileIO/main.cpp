#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("data2.txt"); // Attempt to open file

    if (fin.fail()){
        cout << "Error: could not open data2.txt";
        return -1;
    }

    int num{}, sum{0}, count{0};

    while (!fin.eof()){
        fin >> num;
        if(!fin.fail()) {
            sum += num;
            count++;
        }
    }

    fin.close();

    cout << "ave = " << static_cast<float>(sum)/count << endl;
    return 0;
}