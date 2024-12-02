#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    // Read only
    std::ifstream input;
    input.open("input.txt"); 

    std::vector<int> leftSide;
    std::map<int, int> rightOccurences;

    if(input.is_open()) {
        std::string line;
        int value;

        // Copy each line and parse integers into leftSide and rightOccurences
        while(getline(input, line)) {
            std::stringstream ss(line); 
            ss >> value;
            leftSide.push_back(value);

            ss >> value;
            if(rightOccurences.count(value)) {
                rightOccurences[value] += 1;
            } else {
                rightOccurences[value] = 1;
            }
        }
    } else {
        std::cout << "Unable to open 'input.txt'";
    }
    
    // Sort our left side and right side vectors
    int similarityScore = 0;
    for(int i = 0; i < leftSide.size(); i++) {
        if(rightOccurences.count(leftSide[i])) {
            similarityScore += leftSide[i] * rightOccurences[leftSide[i]];
        }
    }
    
    std::cout << similarityScore;
    return similarityScore;
}