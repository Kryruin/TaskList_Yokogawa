#include "Task.h"

Task::Task(const std::string& name, const std::string& dueDate) :
name(name),
dueDate(dueDate),
isCompleted(false)
{
}
const std::string Task::ToString() const {
    std::string status = isCompleted ? "Completed" : "Pending";
    return "[" + status + "] " + name + "\nDue: " + dueDate;
}

void Task::MarkComplete()
{
    isCompleted = true;
}
bool Task::IsCompleted() const {
    return isCompleted;
}
