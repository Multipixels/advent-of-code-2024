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

    int safe = 0;

    if(input.is_open()) {
        std::string line;
        int value;
 
        while(getline(input, line)) {
            std::vector<int> values;
            std::stringstream ss(line); 
            ss >> value;
            while(!ss.fail()) {
                values.push_back(value);
                ss >> value;
            }

            for(int i = 0; i < values.size(); i++) {
                bool isSafe = true;
                int prevValue;
                if(i == 0) prevValue = values[1];
                else prevValue = values[0];

                int directionFlag = -1;

                for(int j = 0; j < values.size(); j++) {
                    if(i == j) continue;
                    if(i == 0 & j == 1) continue;
                    if(j == 0) continue;

                    if(directionFlag == -1) {
                        if(prevValue > values[j]) directionFlag = 0;
                        else if(prevValue < values[j]) directionFlag = 1;
                        else {
                            isSafe = false;
                            break;
                        }
                    }

                    if(directionFlag == 0) {
                        if(prevValue > values[j] && std::abs(prevValue - values[j]) >= 1 && std::abs(prevValue - values[j]) <= 3) prevValue = values[j];
                        else {
                            isSafe = false;
                            break;
                        }
                    } else if(directionFlag == 1) {
                        if(prevValue < values[j] && std::abs(prevValue - values[j]) >= 1 && std::abs(prevValue - values[j]) <= 3) prevValue = values[j];
                        else {
                            isSafe = false;
                            break;
                        }
                    }
                }

                if(isSafe) {
                    safe++;
                    break;
                } 
            }
        }

    } else {
        std::cout << "Unable to open 'input.txt'";
    }

    std::cout << safe;
    return 0;
}