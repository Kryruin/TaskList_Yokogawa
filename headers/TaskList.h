#pragma once
#include "Task.h"
#include <vector>

class TaskList {
    std::vector<Task> taskList;
public:
    void ViewTasks();
    bool AddTask(const std::string& name, const std::string& date);
    const std::vector<Task>& GetList();
    Task DeleteTask(const int& choice);
    bool IsValidTaskID(const int& choice) const;
    //Sets task from non incomplete to completed
    const Task& SetTaskComplete(const int& choice); 
};