#include <iostream>
#include <fstream>
#include "csv.h"
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

int main() {
    io::CSVReader<1> in("data_2015Q2.csv");
    std::string c1;

    std::vector<std::string> tokens;

    int total_paper_size = 0;
    int total_ribbon_length = 0;

    while (in.read_row(c1)) {
        int paper_size = 0;
        int ribbon_length = 0;

        std::istringstream iss(c1);
        std::vector<int> tokens;
        std::string token;

        while (std::getline(iss, token, 'x')) {
            int dimension = std::stoi(token);
            tokens.push_back(dimension);
        }
        std::sort(tokens.begin(), tokens.end());

        // Part 1
        paper_size += (3 * tokens[0] * tokens[1]);
        paper_size += (2 * tokens[1] * tokens[2]);
        paper_size += (2 * tokens[2] * tokens[0]);

        total_paper_size += paper_size;

        // Part 2
        ribbon_length += (2 * tokens[0] + 2 * tokens[1]);
        ribbon_length += std::accumulate(tokens.begin(), tokens.end(), 1, std::multiplies<int>());

        total_ribbon_length += ribbon_length;

        std::cout << "Input: " << c1 << "\t" << total_paper_size << "\t" << total_ribbon_length << std::endl;   

        }

      

    return 0;
}