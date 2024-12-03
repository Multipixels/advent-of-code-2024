#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int parse_int(char *currentChar, char *peekChar, int length) {
    ;
}

int main() {
    // Read only
    std::ifstream input;
    input.open("input.txt"); 
    std::string raw_input;

    const std::string firstPart = "mul(";
    int progress = 0;

    if(input.is_open()) {
        input >> raw_input;

        while(!input.fail()) {

            char *currentChar = &raw_input[0];
            char *peekChar = &raw_input[1];
            int leftVal = -1;
            int rightVal = -1;


            while(currentChar > &raw_input[-1]) {
                if(progress < 4 && *currentChar == firstPart[progress]) {
                    progress++;
                    currentChar += sizeof(char);
                    peekChar += sizeof(char);
                } else if(progress == 4) {
                    leftVal = parse_int(currentChar, peekChar, raw_input.length());
                } else if(progress == 5 && *currentChar == ',') {
                    // Expect ','    
                } else if(progress == 6) {
                    rightVal = parse_int(currentChar, peekChar, raw_input.length());
                } else if (progress == 7 && *currentChar == ')') {
                    // Expect ')' 
                } else {
                    progress = 0;
                    currentChar += sizeof(char);
                    peekChar += sizeof(char);
                }
            }

            input >> raw_input;            
        }


    } else {
        std::cout << "Unable to open 'input.txt'";
    }

    std::cout << raw_input;

    return 0;
}