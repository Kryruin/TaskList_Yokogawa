// TaskList_Yokogawa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
struct Task {
    std::string name;
    std::string dueDate;
    bool isCompleted;
    Task(const std::string& name, const std::string& dueDate) : 
        name(name), 
        dueDate(dueDate),
        isCompleted(false) 
    {}
    const std::string ToString() const{
        std::string status = isCompleted ? "Completed" : "Pending";
        return "[" + status + "] " + name + "\t |\t Due: " + dueDate;
    }
};

class TaskList {
    std::vector<Task> taskList;
public:
    void ViewTasks() {
        for (int i = 0; i < taskList.size(); ++i) {
            std::cout<< i+1<< ". " << taskList[i].ToString() << std::endl;
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
            return;
        }
        taskList[choice - 1].isCompleted = true;
        std::cout << "Task( "<<taskList[choice - 1].ToString()<< ") has been updated" << std::endl;
    }
};

void PrintMenu() {
    std::cout << "\n===== Task List Menu =====\n";
    std::cout << "1. Add Task"<<std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}
int main()
{
    TaskList taskList;
    int choice = -1;
    //Main Loop
    while (true) {
        PrintMenu();
        std::cin >> choice;
        //Invalid input
        if (!choice){
            std::cout << "Please enter a valid number" << std::endl;
            //Reset failbit
            std::cin.clear();
            //Resets all characters in input buffer
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (choice == 4) {
            std::cout << "Exiting application!" << std::endl;
            break;
        }
        //Add Task
        else if (choice == 1) {
            std::string name;
            std::string date;
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Please enter task name: ";
            std::getline(std::cin, name);
            std::cout << "Please enter due date in DD-MM-YYYY format: ";
            std::getline(std::cin, date);
            //Add validation
            std::cout << name << " " << date << std::endl;
            taskList.AddTask(Task(name, date));
        }
        //View Tasks
        else if (choice == 2) {
            taskList.ViewTasks();
        }
        //Select task and set as complete
        else if (choice == 3) {
            while (true) {
                std::cout << "Please select a task id or press 0 to head back to main menu: " << std::endl;
                int taskChoice = -1;
                taskList.ViewTasks();
                std::cin >> taskChoice;
                //Invalid input
                if (!taskChoice) {
                    std::cout << "Please enter valid input" << std::endl;
                    //Reset failbit
                    std::cin.clear();
                    //Resets all characters in input buffer
                    std::cin.ignore(INT_MAX, '\n');
                    continue;
                }
                //Valid input
                taskList.SetTaskComplete(taskChoice);
                break;
            }
        }
    }
}
