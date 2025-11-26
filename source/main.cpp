// TaskList_Yokogawa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TaskList.h"
#include "Utility.h"
#include <iostream>
enum OPTIONS {
	EXIT = 1,
    CLEAR,
	ADD_TASK,
	VIEW_TASKS,
	MARK_COMPLETE,
	DELETE_TASK
};
void PrintMenu() {
    std::cout << "\n==========================\n";
    std::cout << "\n===== Task List Menu =====\n";
    std::cout << "\n==========================\n";
    std::cout << "1. Exit\n";
    std::cout << "2. Clear the screen\n";
    std::cout << "3. Add Task" << std::endl;
    std::cout << "4. View Tasks" << std::endl;
    std::cout << "5. Mark Task as Completed" << std::endl;
    std::cout << "6. Delete Task" << std::endl;
    std::cout << "Select an option: ";
}
//Prompts user for task ID and handles invalid input
int PromptTaskID(TaskList& tasklist) {
    while (true) {
        int taskChoice = -1;
        tasklist.ViewTasks();
        std::cout << "Please select a task id or press 0 to head back to main menu: " << std::endl;
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
            return 0;
        }
        if (!tasklist.IsValidTaskID(taskChoice)) {
            std::cout << "Invalid option.... Please select a valid task id" << std::endl;
            continue;
        }
        return taskChoice;
    }
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
            std::cout << "Please enter a valid option" << std::endl;
            //Reset failbit
            std::cin.clear();
            //Resets all characters in input buffer
            std::cin.ignore(INT_MAX, '\n');
            continue;
        }
        if (choice == EXIT) {
            std::cout << "Exiting application!" << std::endl;
            break;
        }
        if (choice == CLEAR) {
            std::system("cls");
            continue;
        }

        //Add Task
        else if (choice == ADD_TASK) {
            std::string name;
            std::string date;
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Please enter task name: ";
            std::getline(std::cin, name);
            std::cout << "Please enter due date in DD-MM-YYYY format: ";
            std::getline(std::cin, date);
            //Add validation
            if (taskList.AddTask(name, date)) {
                std::cout << "Adding task: " << name << " " << date << std::endl;
            }
            else {
                std::cout << "Invalid format detected. Please enter date with the DD-MM-YYYY format AFTER today" << std::endl;
            }
        }
        //View Tasks
        else if (choice == VIEW_TASKS) {
            std::cout << "Displaying all tasks... "<<std::endl;
            taskList.ViewTasks();
        }
        //Select task and set as complete
        else if (choice == MARK_COMPLETE) {
            std::cout << "Please select a task to complete" << std::endl;
            int choice = PromptTaskID(taskList);
            //If 0 wasn't selected
            if (choice > 0) {
                Task completedTask = taskList.SetTaskComplete(choice);
                std::cout << "Task has been updated\n" << completedTask.ToString() << std::endl;
            }
        }
        else if (choice == DELETE_TASK) {
            std::cout << "Please select a task to delete" << std::endl;
            int choice = PromptTaskID(taskList);
            if (choice > 0) {
                Task deletedTask = taskList.DeleteTask(choice);
                std::cout << "Task has been deleted\n" << deletedTask.ToString() << std::endl;
            }
        }
    }
}
