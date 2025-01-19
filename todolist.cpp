#include <iostream>
#include <string>
using namespace std;

static int taskLimit, removedTaskCount = 0, completedStatus[10], taskIndex;
static string taskArray[6];
int extraTasks = 0, taskToRemoveIndex, updateIndex;
int i;

void addNewTasks() {
    cout << "Enter how many tasks to add" << endl;
    cin >> taskLimit;
    cin.ignore();
    for (i = 0; i < taskLimit; i++) {
        cout << "Enter task " << i + 1 << " :";
        getline(cin, taskArray[i]);
    }
}

void addTaskToExisting() {
    if (removedTaskCount >= 1) {
        cout << "Enter the new task to add" << endl;
        getline(cin, taskArray[taskLimit + extraTasks - removedTaskCount - 1]);
    } else {
        cout << "Enter the new task to add" << endl;
        getline(cin, taskArray[(taskLimit - 1) + extraTasks]);
    }
}

void displayTasks() {
    if (taskLimit > 0) {
        for (int j = 0; j < taskLimit + extraTasks - removedTaskCount; j++) {
            cout << taskArray[j] << endl;
        }
    } else {
        cout << "No tasks stored" << endl;
    }
}

void deleteTask() {
    if (taskLimit > 0) {
        removedTaskCount++;
        cout << "Enter the index of the task to remove" << endl;
        cin >> taskToRemoveIndex;
        for (updateIndex = 0; updateIndex < taskLimit + extraTasks - removedTaskCount; updateIndex++) {
            if (updateIndex >= taskToRemoveIndex - 1) {
                string temp = taskArray[updateIndex];
                taskArray[updateIndex] = taskArray[updateIndex + 1];
                taskArray[updateIndex + 1] = temp;
            }
        }
    } else {
        cout << "No tasks stored" << endl;
    }
}

void markTaskAsCompleted() {
    if (taskLimit > 0) {
        cout << "Enter the index of the completed task" << endl;
        cin >> taskToRemoveIndex;
        completedStatus[taskToRemoveIndex - 1] = 1;
        cout << "To see status enter [show] or else press [no]" << endl;
        string statusChoice;
        cin >> statusChoice;
        if (statusChoice == "show") {
            for (int j = 0; j < taskLimit + extraTasks - removedTaskCount; j++) {
                if (completedStatus[j] == 1) {
                    cout << taskArray[j] << " is completed" << endl;
                } else {
                    cout << taskArray[j] << " is not completed yet" << endl;
                }
            }
        }
    } else {
        cout << "No tasks stored" << endl;
    }
}

int main() {
    int continueRunning = 1;
    int userChoice;
    while (continueRunning) {
        cout << "\nTo perform below tasks, enter the corresponding number" << endl << endl;
        cout << "1. To add new tasks, enter 1" << endl;
        cout << "2. To view tasks, enter 2" << endl;
        cout << "3. To delete a task, enter 3" << endl;
        cout << "4. To mark a task as completed, enter 4" << endl;
        cout << "5. To add a task to the existing list, enter 5" << endl;
        cout << "6. To end the process, enter 6" << endl << endl;
        cin >> userChoice;
        cin.ignore();
        switch (userChoice) {
            case 1:
                addNewTasks();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                markTaskAsCompleted();
                break;
            case 5:
                extraTasks++;
                addTaskToExisting();
                break;
            case 6:
                continueRunning = 0;
                break;
            default:
                cout << "INVALID OPTION ";
        }
    }
    return 0;
}