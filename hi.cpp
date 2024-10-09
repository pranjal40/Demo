#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Function to split a string by a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<std::string> data = split(line, ',');
        // Process data (for example, print each token)
        for (const auto& token : data) {
            outputFile << token << " ";
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Data processed and saved to output.txt" << std::endl;
    return 0;
}
