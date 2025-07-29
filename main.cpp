#include "helpers.h"

enum class MenuItem {
    exit = 0,
    loadGrades = 1, 
    saveGrades = 2, 
    showGrades = 3,
    GPA = 4,
    addGrade = 5,
    changeGrade = 6,
    deleteGrade = 7,
};

void loadGrades(std::vector<int>& grades) {
    std::string filename = readLine("Enter file name: ");
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file \"" << filename << "\".\n";
        return;
    }

    grades.clear();

    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        ++lineNumber;
        try {
            int grade = helpers::stringToInteger(line);
            grades.push_back(grade);
        } catch (const std::exception&) {
            std::cerr << "Error on line " << lineNumber << ": \"" << line << "\"\n";
        }
    }

    std::cout << "Loaded " << grades.size() << " grade(s) from \"" << filename << "\".\n";
}

void saveGrades(const std::vector<int>& grades) {
    
}

void menu() {
    std::vector<int> grades;

    while (true) {
        std::cout << "1. Load grades\n"; 
        std::cout << "2. Save grades\n"; 
        std::cout << "3. Show grades\n";
        std::cout << "4. GPA\n"; 
        std::cout << "5. Add grade\n"; 
        std::cout << "6. Change grade\n"; 
        std::cout << "7. Delete grade\n"; 
        std::cout << "0. Exit\n";

        int menuChoice = readInt(0, 7, ">>> ");
        
        if (menuChoice == MenuItem::loadGrades) {
            loadGrades(grades);
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
    }
}

int main() {
    menu();
}