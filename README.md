# TaskList_Yokogawa

## Project Overview

TaskList_Yokogawa is a command-line task list application written in C++ 20. 
It allows users to add tasks with a name and due date, view tasks, mark tasks as completed, and delete tasks. 
Tasks are stored in memory for the duration of the program run.

## Features

- Add tasks with a name and due date (DD-MM-YYYY format)
- View all tasks with status and due date
- Mark tasks as completed
- Delete tasks
- Color-coded output: completed tasks in green, pending tasks in red (ANSI escape codes)

## Requirements

- Visual Studio with a C++ toolset that supports C++20

## Build & Run

1. Open the solution in Visual Studio.
2. Build the solution and run the executable from a console or from the IDE.

## Usage

1. Run the program.
2. Use the menu to add, view, mark complete, or delete tasks

## Testing
1. Handles invalid menu input by rejecting non-numeric values and options that are not in the menu.
2. Enforces DD-MM-YYYY date format and prevents due dates from being set before the current date.
3. Validates task selection for deletion or completion by rejecting non-numeric input and indices outside the valid task range.
## $ Unit testing
- Add, complete, and validate tasks
- Add, delete, and verify tasks in the list
- Validate task due date format and constraints
- Validate task ID ranges within the task list
- Add multiple tasks and verify correct deletion behavior

## Demo
[Watch the demo here](https://drive.google.com/file/d/1FUPNypykfTy3MUgq5gYXmA7AHC88ePlG/view?usp=drive_link)

