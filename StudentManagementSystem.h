#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H
#include <vector>
#include "Student.h"
#include "FileHandler.h"

using namespace std;
const int MAX_STUDENTS = 100;
class StudentManagementSystem {
private:
    Student students[MAX_STUDENTS]; // Assuming MAX_STUDENTS is defined elsewhere
    int num_students;
    FileHandler file_handler;

public:
    StudentManagementSystem() : num_students(0) {}

    // Member functions related to student management
    bool is_unique_id(const string& id);
    bool is_unique_password(const string& pwd);
    void add_student_record();
    void search_student_record();
    void delete_student_record();
    void modify_student_record();
    void generate_mark_sheet();
    // Function to get the list of students (optional for file operations)
    const vector<Student>& get_students() const {
        vector<Student> student_list(students, students + num_students);
        return student_list;
    }

    void save_students_to_file() {
        for (int i = 0; i < num_students; i++) {
			file_handler.write_data(students[i]);
        }
    }
    void load_students_from_file() {
        vector<Student> students_vector = file_handler.read_data();
        num_students = students_vector.size();

        // Convert vector to array
        for (int i = 0; i < num_students; ++i) {
            students[i] = students_vector[i];
        }
    }
};

#endif
