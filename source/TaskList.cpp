#include "TaskList.h"
#include "Utility.h"
#include <iostream>
void TaskList::ViewTasks() {
    if (!taskList.size()) {
        std::cout << "No tasks to display" << std::endl;
        return;
    }
    for (int i = 0; i < taskList.size(); ++i) {
        const std::string taskColour = taskList[i].IsCompleted() ? COLOUR::GREEN : COLOUR::RED;
        //Print index and task data
        Utility::PrintColour(taskColour, std::to_string(i + 1) + ". " + taskList[i].ToString());
    }
}
bool TaskList::AddTask(const std::string& name, const std::string& date) {
    if (Utility::isValidDueDate(date)) {
        taskList.push_back(Task(name, date));
        return true;
    }
    else 
        return false;
    
}
const std::vector<Task>& TaskList::GetList()
{
    return taskList;
}
Task TaskList::DeleteTask(const int& choice)
{
	Task tempTask = taskList[choice - 1];
    taskList.erase(taskList.begin() + (choice - 1));
    return tempTask;
}
bool TaskList::IsValidTaskID(const int& choice) const
{
    if (choice < 1 || choice > taskList.size()) {
        return false;
    }
    return true;
}
//Sets task from non incomplete to completed
const Task&  TaskList::SetTaskComplete(const int& choice) {
    taskList[choice - 1].MarkComplete();
    return taskList[choice - 1];
}