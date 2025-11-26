#pragma once
#include "Utility.h"
#include <chrono>
#include <sstream>
namespace Utility {
    bool isValidDueDate(const std::string& date) {
        std::istringstream in{ date };
        std::chrono::year_month_day ymd;
        in >> std::chrono::parse("%d-%m-%Y", ymd);
        //Check if valid format
        if (in.fail() || !ymd.ok()) {
            return false;
        }
        //Check if it's AFTER today
        auto now = std::chrono::system_clock::now();
        auto today = floor<std::chrono::days>(now);
        std::chrono::sys_days given = std::chrono::sys_days{ ymd };

        return given > today;
    }
}