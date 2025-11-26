#include "Task.h"

Task::Task(const std::string& name, const std::string& dueDate) :
name(name),
dueDate(dueDate),
isCompleted(false)
{
}

void Task::SetComplete()
{
    isCompleted = true;
}

const std::string Task::ToString() const {
    std::string status = isCompleted ? "Completed" : "Pending";
    return "[" + status + "] " + name + "\t |\t Due: " + dueDate;
}