#include <iostream>
#include <fstream>
#include "csv.h"
#include <Eigen/Dense>
#include <unordered_map>
#include <string>

using Eigen::MatrixXd;

std::string get_name() 
{
    return "Chris Wright";
}

int main() {
    io::CSVReader<5> in("test.csv");  // Specify the number of columns

    int column1;
    float column2;
    std::string column3, column4, column5;

    while (in.read_row(column1, column2, column3, column4, column5)) {
        // Process the data as needed
        std::cout << "Column1: " << column1 * 434 << "\t";
        std::cout << "Column2: " << column2 << "\t";
        std::cout << "Column3: " << column3 << "\t";
        std::cout << "Column4: " << column4 << "\t";
        std::cout << "Column5: " << column5[4] << std::endl;
    }

    
    // Parse a CSV file into a matrix
    // -----------------------------------------------------------------
    // // Loop to read each row and column from the CSV file
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         char comma; // to handle the comma in the CSV format
    //         file >> matrix(i, j) >> comma;
    //     }
    // }

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;

    std::cout << get_name() << std::endl;


    // Let's try out a dictionary
    // ------------------------------------------------------------------
    // Create an unordered_map with int keys and string values
    std::unordered_map<int, std::string> myMap;

    // Insert key-value pairs
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Access values by key
    std::cout << "Value for key 2: " << myMap[2] << std::endl;

    // Check if a key exists
    if (myMap.find(3) != myMap.end()) {
        std::cout << "Key 3 exists!" << std::endl;
    }

    // Iterate over the map
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }


    return 0;
}