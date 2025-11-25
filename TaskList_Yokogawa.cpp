// TaskList_Yokogawa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
struct Task {
    std::string name;
    std::string dueDate;
    bool isCompleted;
    Task(const std::string& name, const std::string dueDate) : 
        name(name), 
        dueDate(dueDate),
        isCompleted(false) 
    {}
    const std::string ToString() const{
        std::string status = isCompleted ? "Completed" : "Pending";
        return "[" + status + "] " + name + " Due: " + dueDate;
    }
};

class TaskList {
    std::vector<Task> taskList;
public:
    void ViewTasks() {
        for (const auto& elem : taskList) {
            std::cout << elem.ToString() << std::endl;
        }
    }
    void AddTask(const Task& newTask) {
        taskList.push_back(newTask);
    }
    //Sets task from non incomplete to completed
    void SetTaskComplete(const int& choice) {
        //Invalid option
        if (choice < 1 || choice > taskList.size()) {
            std::cout << "Invalid option.... Please select a valid task id" << std::endl;
        }
        taskList[choice - 1].isCompleted = true;
    }
};
int main()
{
    
}
