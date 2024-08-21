#include <iostream>
#include <string>
#include <map>

using namespace std;

void addTask(map<int, string> &tasks, map<int, int> &taskStates, int &taskId) {
    int continueAdding;
    string taskDetails;

    do {
        cin.ignore(); 
        cout << "Task Description: ";
        getline(cin, taskDetails);
        tasks[taskId] = taskDetails;
        taskStates[taskId] = 0; 
        taskId++;
        cout << "Add another task? (1 = Yes / 0 = No): ";
        cin >> continueAdding;
    } while (continueAdding);
}

void showTasks(const map<int, string> &tasks, const map<int, int> &taskStates) {
    cout << endl;
    for (const auto& task : tasks) {
        if (taskStates.at(task.first) == 1) {
            cout << "Task #" << task.first << " : " << task.second << " ---> [Done]\n";
        } else {
            cout << "Task #" << task.first << " : " << task.second << " ---> [Pending]\n";
        }
    }
}

void deleteTask(map<int, string> &tasks, map<int, int> &taskStates) {
    int removeId;
    cout << "Enter task number to remove: ";
    cin >> removeId;
    if (tasks.erase(removeId) && taskStates.erase(removeId)) {
        cout << "Task #" << removeId << " was successfully removed!\n";
    } else {
        cout << "Task not found!\n";
    }
}

void completeTask(map<int, string> &tasks, map<int, int> &taskStates) {
    int completeId;
    cout << "Enter task number to mark as done: ";
    cin >> completeId;
    if (tasks.find(completeId) != tasks.end()) {
        taskStates[completeId] = 1;
        cout << "Task #" << completeId << " marked as done!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int taskId = 1, userOption;
    map<int, string> tasks;
    map<int, int> taskStates;

    while (true) {
        cout << "\n------------------ TASK MANAGER ------------------\n";
        cout << "Choose an action:\n";
        cout << "1. Add New Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Complete Task\n";
        cout << "5. Exit Program\n";
        cout << "\nEnter your selection: ";
        
        // Input validation
        if (!(cin >> userOption)) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (userOption) {
            case 1:
                addTask(tasks, taskStates, taskId);
                break;
            case 2:
                showTasks(tasks, taskStates);
                break;
            case 3:
                deleteTask(tasks, taskStates);
                break;
            case 4:
                completeTask(tasks, taskStates);
                break;
            case 5:
                cout << "Thank you for using Task Manager!\n";
                return 0;
            default:
                cout << "Invalid option, please select again...\n";
                break;
        }
    }

    return 0;
}
