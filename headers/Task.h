#pragma once
#include <string>

class Task {
    std::string name;
    std::string dueDate;
    bool isCompleted;
public:
    Task(const std::string& name, const std::string& dueDate);
    const std::string ToString() const;
    bool IsCompleted() const;
    void MarkComplete();
};