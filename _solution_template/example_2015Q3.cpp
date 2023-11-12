#include <iostream>
#include <fstream>
#include "csv.h"
#include <string>
#include <vector>
#include <sstream>
#include <numeric>
#include <tuple>
#include <unordered_map>


struct hash_function {
    template <class p1, class p2>
    std::size_t operator () (const std::pair<p1, p2>& p) const {
        auto x = std::hash<p1>{}(p.first);
        auto y = std::hash<p2>{}(p.second);

        return x ^ y;
    }
};


int main() {
    /* 
    Part 1
    ==============================================
    1. On each move compute a coordinate
    2. Add coordinate to map if doesn't exist
    3. Increment counter at map key
    4. Count number of keys with > 1 visits
    */

    io::CSVReader<1> in("data_2015Q3.csv");
    std::string c1;
    
    std::pair<int, int> this_house = std::make_pair(0, 0);
    std::unordered_map<std::pair<int, int>, int, hash_function> neighborhood;   
    neighborhood[std::make_pair(0, 0)] = 1;

    // Go through the house directions and update the map
    while (in.read_row(c1)) {

        // std::cout << std::get<0>(this_house) << ", " << std::get<1>(this_house) << " -> " << neighborhood[this_house] << std::endl;

        for (char t : c1) {
            if (t == '^') {std::get<1>(this_house) += 1;}
            else if (t == 'v') {std::get<1>(this_house) -= 1;}
            else if (t == '>') {std::get<0>(this_house) += 1;}
            else if (t == '<') {std::get<0>(this_house) -= 1;}
            else {}

            if (neighborhood.find(this_house) == neighborhood.end()) {
                neighborhood[this_house] = 1;
            } else {
                neighborhood[this_house]++;
            }

            // std::cout << std::get<0>(this_house) << ", " << std::get<1>(this_house) << " -> " << neighborhood[this_house] << std::endl;
        }
    }

    // Part 1
    int repeat_visits = 0;
    int num_keys = 0;

    for (const auto& pair : neighborhood) {
        num_keys++;

        if (pair.second > 1) {
            repeat_visits++;
        }
    }

    std::cout << "Total number of houses visited: " <<  num_keys << std::endl;
    std::cout << "Number of houses that have been revisited: " <<  repeat_visits << std::endl;



    return 0;
}