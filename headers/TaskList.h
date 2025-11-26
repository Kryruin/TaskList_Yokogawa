#pragma once
#include "Task.h"
#include <vector>

class TaskList {
    std::vector<Task> taskList;
public:
    void ViewTasks();
    void AddTask(const std::string& name, const std::string& date);
    //Sets task from non incomplete to completed
    bool SetTaskComplete(const int& choice); 
};