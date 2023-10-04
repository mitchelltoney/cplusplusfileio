#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[]) {
    std::ifstream inputFile("test.txt");
    std::ofstream outputFile(argv[1]);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 2;
    }

    char ch;
    while (inputFile.get(ch)) {//goes until it is empty
        if (std::isupper(ch)) {
            outputFile.put(std::tolower(ch));
        } else if (std::islower(ch)) {
            outputFile.put(std::toupper(ch));
        } else {
            outputFile.put(ch);
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
