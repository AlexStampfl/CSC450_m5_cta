#include <iostream>
#include <string>
#include <fstream>
#include <algorithm> // for reverse

void reverse();

int main() {
    // create i/o file variable
    std::ofstream outputFile("CSC450_CT5_mod5.txt", std::ios::app); // oepn file in 'append' mode via flag `std::ios::app`

    // check if open
    if (outputFile.is_open()) {
        std::string userInput;
        std::cout << "Enter text to append to file (type 'done' to finish):\n";

        // write to file while userInput is not done
        do {
            std::getline(std::cin, userInput);
            if (userInput != "done") {
                outputFile << userInput << std::endl;
            }
        } while (userInput != "done");

        outputFile.close();
        std::cout << "Data written successfully to file.\n";
    } else {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }

    reverse();
    return 0; // end program
}

// Reverse characters in external text file
void reverse() {
    std::ifstream inputFile("CSC450_CT5_mod5.txt");

    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return;
    }

    // Read entire file into string
    std::string fileContent, line;
    while (std::getline(inputFile, line)) {
        fileContent += line + "\n";
    }
    inputFile.close();

    // reverse string
    std::reverse(fileContent.begin(), fileContent.end());

    // Open output file for writing
    std::ofstream outputFile("CSC450_CT5_mod5.txt", std::ios::app); //append

    if (!outputFile) {
        std::cerr << "Error: Unable to open output file.\n";
        return;
    }

    // Write reverse content to output file
    outputFile << fileContent;

    outputFile.close();

    std::cout << "Reversed content appended to output file.";
}