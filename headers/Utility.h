#pragma once
#include <string>
namespace COLOUR {
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string NORMAL = "\033[0m";
}

namespace Utility {
    bool isValidDueDate(const std::string& date);
    void PrintColour(const std::string& colour, const std::string& text);
}