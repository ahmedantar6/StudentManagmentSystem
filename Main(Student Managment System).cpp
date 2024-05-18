#include "StudentManagementSystem.h"
#include <iostream>

using namespace std;

int main() {
    StudentManagementSystem system;
    bool running = true;
    int choice;
	system.load_students_from_file();
    while (running) {
        cout << "Student Management System\n";
        cout << "1. Add Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Modify Student Record\n";
        cout << "5. Generate Mark Sheet\n";
        cout << "6. Exit the program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system.add_student_record();
            break;
        case 2:
            system.search_student_record();
            break;
        case 3:
            system.delete_student_record();
            break;
        case 4:
            system.modify_student_record();
            break;
        case 5:
            system.generate_mark_sheet();
            break;
        case 6:
			system.save_students_to_file();
			cout << "Exiting the program.\n";

            return 0;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            break;
        }
    }
    return 0;}

