#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string capitalize(std::string line) {
    for (char& c : line) {
        c = std::toupper(c);
    }
    return line;
}

std::string lowercase(std::string line) {
    for (char& c : line) {
        c = std::tolower(c);
    }
    return line;
}

std::string remove_punct_num(std::string line) {
    std::string result = "";
    for (char c : line) {
        if (!std::ispunct(c) && !std::isdigit(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");

    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << "Processing line: " << line << std::endl;
        std::cout << "Choose an option:\n"
                  << "1. Capitalize the entire line\n"
                  << "2. Lowercase the entire line\n"
                  << "3. Remove all punctuation/numbers\n"
                  << "Your choice: ";
        
        int choice;
        std::cin >> choice;

        // Clear the input buffer
        std::cin.clear();
        while (std::cin.get() != '\n');

        while (choice < 1 || choice > 3) {
            std::cout << "You can only enter numbers 1, 2, or 3. Try again: ";
            std::cin >> choice;
            // Clear the input buffer again
            std::cin.clear();
            while (std::cin.get() != '\n');
        }

        switch (choice) {
            case 1:
                outfile << capitalize(line) << std::endl;
                break;
            case 2:
                outfile << lowercase(line) << std::endl;
                break;
            case 3:
                outfile << remove_punct_num(line) << std::endl;
                break;
        }
    }

    infile.close();
    outfile.close();
    std::cout << "Results have been written in output.txt." << std::endl;

    return 0;
}
