#include <iostream>

int readInt(const std::string& prompt = "Enter an integer: ") {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cerr << "\nInput error or EOF encountered. Exiting.\n";
            std::exit(EXIT_FAILURE);
        }

        try {
            size_t pos;
            int value = std::stoi(line, &pos);
            if (pos != line.size()) {
                // Extra characters after number
                throw std::invalid_argument("Trailing characters");
            }
            return value;
        } catch (...) {
            std::cout << "Invalid input. Please enter a valid integer.\n";
        }
    }
}

enum class MenuItem {
    exit = 0,
    loadGrades = 1, 
    saveGrades = 2, 
    showGrade = 3,
    GPA = 4,
    addGrade = 5,
    changeGrade = 6,
    deleteGrade = 7,
};

void menu() {
    std::cout << "1. Load grades\n"; 
    std::cout << "2. Save grades\n"; 
    std::cout << "3. Show grades\n";
    std::cout << "4. GPA\n"; 
    std::cout << "5. Add grade\n"; 
    std::cout << "6. Change grade\n"; 
    std::cout << "7. Delete grade\n"; 
    std::cout << "0. Exit\n";

    std::cout << ">>> ";
    std::string menuChoice;
    getline(std::cin, menuChoice);
    
    if (menuChoice == MenuItem::loadGrades) {
        
    }
    else if (menuChoice == MenuItem::saveGrades) {

    }
    else if (menuChoice == MenuItem::showGrades) {
        
    }
    else if (menuChoice == MenuItem::GPA) {
        
    }
    else if (menuChoice == MenuItem::addGrade) {
        
    }
    else if (menuChoice == MenuItem::changeGrade) {
        
    }
    else if (menuChoice == MenuItem::deleteGrade) {
        
    }
    else if (menuChoice == MenuItem::exit) {
        
    }
    else {
        std::cout << "Invalid input! Press any key to continue...\n";
    }
}

int main() {
    
}