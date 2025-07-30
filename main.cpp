#include <fstream>
#include <iomanip>

#include "input_utils.h"

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
    std::string filename = console::readLine("Enter file name: ");
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
            int grade = console::stringToInteger(line);
            grades.push_back(grade);
        } catch (const std::exception&) {
            std::cerr << "Error on line " << lineNumber << ": \"" << line << "\"\n";
        }
    }

    std::cout << "Loaded " << grades.size() << " grade(s) from \"" << filename << "\".\n";
}

void saveGrades(const std::vector<int>& grades) {
    std::string filename = console::readLine("Enter file name to save grades: ");
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open file \"" << filename << "\" for writing.\n";
        return;
    }

    for (int grade : grades) {
        file << grade << '\n';
    }

    std::cout << "Saved " << grades.size() << " grade(s) to \"" << filename << "\".\n";
}

void showGrades(const std::vector<int>& grades) {
    if (grades.empty()) {
        std::cout << "No grades to show.\n";
        return;
    }

    const int columnsPerRow = 10;
    const int columnWidth = 6;

    std::cout << "\n===== Grades Table =====\n";

    for (size_t i = 0; i < grades.size(); i += columnsPerRow) {
        size_t end = std::min(i + columnsPerRow, grades.size());

        std::cout << "No.:   ";
        for (size_t j = i; j < end; ++j) {
            std::cout << std::setw(columnWidth) << (j + 1);
        }
        std::cout << '\n';

        std::cout << "Grade: ";
        for (size_t j = i; j < end; ++j) {
            std::cout << std::setw(columnWidth) << grades[j];
        }
        std::cout << "\n\n";
    }

    std::cout << "Total grades: " << grades.size() << "\n";
}

void GPA(const std::vector<int>& grades) {
    if (grades.empty()) {
        std::cout << "No grades to calculate GPA.\n";
        return;
    }

    double sum = 0.0;
    for (int grade : grades) {
        if (grade < 1 || grade > 5) {
            std::cerr << "Invalid grade detected: " << grade << ". Skipping.\n";
            continue;
        }
        sum += grade;
    }

    double gpa = sum / grades.size();

    std::cout << "GPA: " << std::fixed << std::setprecision(2) << gpa << "\n\n";
}

void addGrade(std::vector<int>& grades) {
    int grade = console::readInt(1, 5, "Enter grade: ");
    grades.push_back(grade);
    std::cout << "New grade added.\n";
}

void changeGrade(std::vector<int>& grades) {
    showGrades(grades);
    if (grades.empty()) return;
    int gradeNumber = console::readInt(1, grades.size(), "Enter number of grade to change: ");
    int newGrade = console::readInt(1, 5, "Enter new grade: ");
    grades[gradeNumber - 1] = newGrade;
    std::cout << "Grade changed.\n";
}

void deleteGrade(std::vector<int>& grades) {
    showGrades(grades);
    if (grades.empty()) return;
    int gradeToDelete = console::readInt(1, grades.size(), "Enter number of grade to delete: ");
    grades.erase(grades.begin() + gradeToDelete - 1);
    std::cout << "Grade deleted";
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

        int menuInput = console::readInt(0, 7, ">>> ");
        MenuItem menuChoice = static_cast<MenuItem>(menuInput);

        switch (menuChoice) {
            case MenuItem::loadGrades:
                loadGrades(grades);
                break;
            case MenuItem::saveGrades:
                saveGrades(grades);
                break;
            case MenuItem::showGrades:
                showGrades(grades);
                break;
            case MenuItem::GPA:
                GPA(grades);
                break;
            case MenuItem::addGrade:
                addGrade(grades);
                break;
            case MenuItem::changeGrade:
                changeGrade(grades);
                break;
            case MenuItem::deleteGrade:
                deleteGrade(grades);
                break;
            case MenuItem::exit:
                return;
        }
        
    }
}

int main() {
    menu();
}