#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    // Read only
    std::ifstream input;
    input.open("input.txt"); 

    std::vector<int> leftSide;
    std::vector<int> rightSide;

    if(input.is_open()) {
        std::string line;
        int value;

        // Copy each line and parse integers into leftSide and rightSide
        while(getline(input, line)) {
            std::stringstream ss(line); 
            ss >> value;
            leftSide.push_back(value);
            ss >> value;
            rightSide.push_back(value);
        }
    } else {
        std::cout << "Unable to open 'input.txt'";
    }
    
    // Sort our left side and right side vectors
    std::sort(leftSide.begin(), leftSide.end());
    std::sort(rightSide.begin(), rightSide.end());

    // Find the sum of the differences
    int totalDifference = 0;
    for(int i = 0; i < leftSide.size(); i++) {
        totalDifference += std::abs(leftSide[i] - rightSide[i]);
    }

    std::cout << totalDifference;
    return totalDifference;
}