// TaskList_Yokogawa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TaskList.h"
#include "Utility.h"
#include <iostream>
void PrintMenu() {
    std::cout << "\n==========================\n";
    std::cout << "\n===== Task List Menu =====\n";
    std::cout << "\n==========================\n";
    std::cout << "1. Add Task"<<std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Clear the screen\n";
    std::cout << "5. Exit\n";
    std::cout << "Select an option: ";
}
int main()
{
    TaskList taskList;
    int choice = -1;
    //Main Loop
    while (true) {
        PrintMenu();
        //Invalid input
        if (!(std::cin >> choice)){
            std::cout << "Please enter a valid number" << std::endl;
            //Reset failbit
            std::cin.clear();
            //Resets all characters in input buffer
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (choice == 4) {
            std::system("cls");
            continue;
        }

        if (choice == 5) {
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
            taskList.AddTask(name, date);
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
                //Invalid input
                if (!(std::cin >> taskChoice)) {
                    std::cout << "Please enter valid input" << std::endl;
                    //Reset failbit
                    std::cin.clear();
                    //Resets all characters in input buffer
                    std::cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (taskChoice == 0) {
                    std::cout << "Going back to main menu" << std::endl;
                    break;
                }
                if (taskList.SetTaskComplete(taskChoice))
                    break;
            }
        }
    }
}
