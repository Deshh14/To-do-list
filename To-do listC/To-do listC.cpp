#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Function for saving a list of tasks to a file
void save(const vector<string>& todo, const string& filename) {
    ofstream file(filename);
    try {
        if (file.is_open()) {
            // We write each task to a file
            for (const string& task : todo) {
                file << task << endl;
            }
            file.close();
        }
        else {
            throw runtime_error("We have problem...");
        }
    }
    catch (const exception& e) {
        cerr << "Ohhh..." << e.what() << endl;
    }
}

// Function for loading a list of tasks from a file
void load(vector<string>& todo, const string& filename) {
    ifstream file(filename);
    try {
        if (file.is_open()) {
            string task;
            // We read each task from the file and add it to the task list
            while (getline(file, task)) {
                todo.push_back(task);
            }
            file.close();
        }
        else {
            throw runtime_error("You have problem...");
        }
    }
    catch (const exception& e) {
        cerr << "OMG!!! " << e.what() << endl;
    }
}

int main() {
    vector<string> todo;
    cout << "The best To-do list from Max)" << endl;

    cout << endl;

    cout << "This to-do sheet has the following commands: Add, Delete, Show and Exit." << endl;
    cout << "The 'Add' command is activated when writing '1'. She adds a task to the to-do list." << endl;
    cout << "The 'Delete' command is activated when writing '2'. It removes the task from the to-do list." << endl;
    cout << "The 'Show' command is activated when writing '3'. It shows the entire to-do list." << endl;
    cout << "The 'Exit' command is activated when writing '4'. It shows the entire to-do list." << endl;
    cout << "If used correctly, this program will help in a variety of situations." << endl;

    cout << endl;

    cout << "Select operation:" << endl;
    cout << "1. Add" << endl << "2. Delete" << endl << "3. Show" << endl << "4. Exit" << endl;

    load(todo, "todo.txt");

    while (true) {
        int operation;
        cin >> operation;
        string task;
        int index;
        try {
            if (operation == 1) {
                cout << "Write task: ";
                cin.ignore();
                getline(cin, task);
                // Adding a task to the list
                todo.push_back(task);
            }
            else if (operation == 2) {
                try {
                    cout << "Select the number of the task you want to delete: ";
                    cin >> index;
                    if (index >= 0 && index < todo.size()) {
                        // Delete the task at the specified index
                        todo.erase(todo.begin() + index);
                    }
                    else {
                        throw runtime_error("Incorrect index");
                    }
                }
                catch (const exception& e) {
                    cerr << e.what() << endl;
                }
            }
            else if (operation == 3) {
                cout << endl;
                cout << "Your tasks:" << endl;
                // Displaying a list of tasks
                for (const auto& task : todo) {
                    cout << task << endl;
                }
            }
            else if (operation == 4) {
                // Save the list of tasks to a file and end the program
                save(todo, "todo.txt");
                cout << "Good luck bro!" << endl;
                break;
            }
            else {
                cout << "What?" << endl;
            }
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }
    return 0;
}