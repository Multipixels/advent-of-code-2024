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

    std::vector<int> values;
    int safe = 0;

    if(input.is_open()) {
        std::string line;
        int value;
        int prevValue;
        int flag = -1;
        int isSafe = 1;

        // Copy each line and parse integers into leftSide and rightSide
        while(getline(input, line)) {
            std::stringstream ss(line); 
            ss >> prevValue;
            ss >> value;
            while(!ss.fail()) {
                if(flag == -1) {
                    if(prevValue < value) {
                        flag = 0;
                    } else if(prevValue > value) {
                        flag = 1;
                    } else {
                        isSafe = 0;
                        break;
                    }
                } else if(flag == 0) {
                    if(prevValue < value && std::abs(prevValue - value) >= 1 && std::abs(prevValue - value) <= 3) {
                        prevValue = value;
                        ss >> value;
                    } else {
                        std::cout << flag << " " << prevValue << " " << value << std::endl;
                        isSafe = 0;
                        break;
                    }
                } else if(flag == 1) {
                    if(prevValue > value && std::abs(prevValue - value) >= 1 && std::abs(prevValue - value) <= 3) {
                        prevValue = value;
                        ss >> value;
                    } else {
                        std::cout << flag << " " << prevValue << " " << value << std::endl;
                        isSafe = 0;
                        break;
                    }
                }
            }

            if(isSafe) {
                safe++;
            }

            values = std::vector<int>();
            flag = -1;
            isSafe = 1;
        }

    } else {
        std::cout << "Unable to open 'input.txt'";
    }

    std::cout << safe;
    return 0;
}