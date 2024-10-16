#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addTask(vector<string> &tasks);

void viewTasks(const vector<string> &tasks);

void removeTask(vector<string> &tasks);

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        // display menu
        cout << "\n--- Todo List ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline character

        switch (choice) {
            case 1: addTask(tasks);
                break;
            case 2: viewTasks(tasks);
                break;
            case 3: removeTask(tasks);
                break;
            case 4: cout << "Goodbye!";
                return 0;
            default: cout << "Invalid choice. Try again. \n";
        }
    }
}

void addTask(vector<string> &tasks) {
    string task;
    cout << "Enter a task: ";
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added! \n";
}

void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display. \n";
        return;
    }
    cout << "\n--- Todo List ---\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << '\n';
    }
}

void removeTask(vector<string> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove. \n";
        return;
    }
    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number. \n";
    } else {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed! \n";
    }
}
