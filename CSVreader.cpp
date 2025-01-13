//  C++ Program to illustrate how we can read data from a
//  CSV file into a 2D array
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// Maximum number of rows for the 2D array
const int MAX_ROWS = 100;
// Maximum number of columns for the 2D array
const int MAX_COLS = 100;

int main()
{   
    // Open the CSV file
    ifstream file("data.csv");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        //Return error if not able to save the data
        return 1;
    }

    // Define a 2D array to store the CSV data
    string data[MAX_ROWS][MAX_COLS];
    string line;
    int row = 0;
    int col;
    // Store the CSV data from the CSV file to the 2D array
    while (getline(file, line) && row < MAX_ROWS) {
        stringstream ss(line);
        string cell;
        col = 0;
        while (getline(ss, cell, ',') && col < MAX_COLS) {
            data[row][col] = cell;
            col++;
        }
        row++;
    }
    // close the file after read opeartion is complete
    file.close();

    //TODO: Finish this c++ script
    //QUICK ANALYSIS: Have a list of all the states in the CSV
    string states_usa[MAX_ROWS];
    int items = 0;

    for (int f = 1; f < row; f++)
    {
        bool on_list = 0;
        for (int k = 0; k <= items; k++) {
            if (states_usa[k] == data[f][0]) {
                on_list = 1;
            }
        }
        if (on_list == 0) {
            states_usa[items] = data[f][0];
            items++;
        }
    }
    // Create an output filestream object
    std::ofstream myFile("Locations.csv");
    // Print the data stored in the 2D array
    for (int g = 0; g < items; g++)
    {
        myFile << states_usa[g] << "\n";
        cout << "Locations: " << states_usa[g] << endl;
    }
    cout << "Loaded results into CSV file (You can find it in the same repository as your code)" << endl;
    // Close the file
    myFile.close();
    cout << "Results on the search of only 100 rows, you can change that value in the constant variable at the beginning of this code." << endl;

    return 0;
}