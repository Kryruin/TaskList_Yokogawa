#include "TaskList.h"
#include "Utility.h"
#include <iostream>
void TaskList::ViewTasks() {
    for (int i = 0; i < taskList.size(); ++i) {
        //Print index and task data
        std::cout << i + 1 << ". " << taskList[i].ToString() << std::endl;
    }
}
void TaskList::AddTask(const std::string& name, const std::string& date) {
    if (Utility::isValidDueDate(date)) {
        taskList.push_back(Task(name, date));
        std::cout << "Adding task: " << name << " " << date << std::endl;
    }
    else {
        std::cout << "Invalid format detected. Please enter date with the DD-MM-YYYY format AFTER today" << std::endl;
    }
}
//Sets task from non incomplete to completed
bool TaskList::SetTaskComplete(const int& choice) {
    //Invalid option
    if (choice < 1 || choice > taskList.size()) {
        std::cout << "Invalid option.... Please select a valid task id" << std::endl;
        return false;
    }
    taskList[choice - 1].SetComplete();
    std::cout << "Task( " << taskList[choice - 1].ToString() << ") has been updated" << std::endl;
    return true;
}