
#include "Student.h"
#include "StudentManagementSystem.h"
#include <iostream>
#include <string>
#include <fstream> // for file operations (optional)
using namespace std;




bool StudentManagementSystem::is_unique_id(const string& id) {
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id) {
            return false;
        }
    }
    return true;
}

bool StudentManagementSystem::is_unique_password(const string& pwd) {
    // This implementation checks if any student currently has the provided password but doesn't enforce unique passwords during record creation.
    // You might want to consider modifying this logic.
    for (int i = 0; i < num_students; ++i) {
        if (students[i].password == pwd) {
            return false;
        }
    }
    return true;
}

void StudentManagementSystem::add_student_record() {
    if (num_students < MAX_STUDENTS) {
        string id, name, pwd;
        cout << "Enter student ID: ";
        cin >> id;
        if (!is_unique_id(id)) {
            cout << "This ID is already taken. Please enter a unique ID.\n";
            return;
        }
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Create a password for the student: ";
        getline(cin, pwd);
        // Commenting out the following line as it enforces unique passwords during record creation but might not be the desired behavior based on the current implementation of is_unique_password
        // if (!is_unique_password(pwd)) {
        //   cout << "This password is already taken. Please enter a unique password.\n";
        //   return;
        // }
        Student new_student(id, name, pwd);
        string subjects[] = { "Math", "Science", "Physics", "Biology", "Chemistry" };
        int score;
        for (const string& subject : subjects) {
            do {
                cout << "Enter grade for " << subject << " (0-100): ";
                cin >> score;
                if (score < 0 || score > 100) {
                    cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                }
            } while (score < 0 || score > 100);
            new_student.add_marks(subject, score);
        }
        students[num_students++] = new_student;
        cout << "Student record added with grades.\n";
    }
    else {
        cout << "Maximum number of students reached.\n";
    }
}

void StudentManagementSystem::search_student_record() {
    string search_term, pwd;
    cout << "Enter student ID or full name to search: ";
    cin.ignore();
    getline(cin, search_term);
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == search_term || students[i].name == search_term) {
            cout << "Enter password for " << students[i].name << ": ";
            getline(cin, pwd);
            if (students[i].verify_password(pwd)) {
                cout << "Student found: " << students[i].name << " with ID: " << students[i].student_id << endl;
                students[i].display_grades();
            }
            else {
                cout << "Invalid password.\n";
            }
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManagementSystem::delete_student_record() {
    string id_to_delete;
    cout << "Enter student ID to delete: ";
    cin >> id_to_delete;
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id_to_delete) {
            // Shift elements to fill the gap
            for (int j = i; j < num_students - 1; ++j) {
                students[j] = students[j + 1];
            }
            num_students--;
            cout << "Student record deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManagementSystem::modify_student_record() {
    string id_to_modify;
    cout << "Enter student ID to modify: ";
    cin >> id_to_modify;
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id_to_modify) {
            int choice;
            cout << "Select what you want to modify:\n";
            cout << "1. Name\n";
            cout << "2. Password\n";
            cout << "3. Grades\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, students[i].name);
                break;
            case 2:
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, students[i].password);
                break;
            case 3:
                int score;
                for (int j = 0; j < students[i].num_subjects; ++j) {
                    cout << "Enter new grade for " << students[i].marks[j].subject << " (0-100): ";
                    cin >> score;
                    if (score < 0 || score > 100) {
                        cout << "Invalid grade. Please enter a value between 0 and 100.\n";
                        --j;
                        continue;
                    }
                    students[i].marks[j].score = score;
                }
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }
            cout << "Student record modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManagementSystem::generate_mark_sheet() {
    string id_to_generate;
    cout << "Enter student ID to generate mark sheet: ";
    cin >> id_to_generate;
    for (int i = 0; i < num_students; ++i) {
        if (students[i].student_id == id_to_generate) {
            students[i].generate_mark_sheet();
            return;
        }
    }
    cout << "Student not found.\n";
}

