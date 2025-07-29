#include "helpers.h"

namespace helpers {

    void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }

    std::string readLine(const std::string& prompt) {
        std::string input;

        if (!prompt.empty()) {
            std::cout << prompt;
            std::cout.flush();
        }

        if (!std::getline(std::cin, input)) {
            std::cerr << "Input error or EOF encountered. Exiting.\n";
            std::exit(EXIT_FAILURE);
        }

        return input;
    }

    int stringToInteger(const std::string& str) {
        size_t pos;
        int integer = std::stoi(str, &pos);
        if (pos != str.size()) {
            throw std::invalid_argument("Trailing characters.");
        }
        return integer;
    }

    int readInt(int min, int max, const std::string& prompt) {
        while (true) {
            std::cout << prompt;
            std::string line;
            if (!std::getline(std::cin, line)) {
                std::cerr << "Input error or EOF encountered. Exiting.\n";
                std::exit(EXIT_FAILURE);
            }

            try {
                int value = stringToInteger(line);
                if (value < min || value > max) {
                    std::cerr << "Please enter a number between " << min << " and " << max << ".\n";
                    continue;
                }
                return value;
            } catch (const std::exception&) {
                std::cerr << "Invalid input. Please enter a valid integer.\n";
            }
        }
    }

}