#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> hist{0, 0, 0, 0, 0};
    int num_bins = 5;
    vector<int> indices{0, 0, 2, 3, 3, 3, 3, 4, 4, 4};
    int num_indices = 10;

    for (int i=0; i < num_indices; ++i)
    {
        hist[ indices[i] ]++;
    }

    for (int i=0; i < num_bins; ++i)
    {
        cout << hist[i] << " ";
    }
    cout << endl;
}
