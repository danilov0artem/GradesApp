#pragma once

#include <iostream>

namespace console {
    void clearConsole();
    std::string readLine(const std::string& prompt = "");
    int stringToInteger(const std::string& str);
    int readInt(int min, int max, const std::string& prompt = "Enter an integer: ");
}
