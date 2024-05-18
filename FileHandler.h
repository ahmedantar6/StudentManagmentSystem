#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <vector>
#include <fstream>
#include "student.h"

using namespace std;
class FileHandler {
private:
	string file_path;

public:
	FileHandler() = default;

	FileHandler(const string& path) : file_path(path) {
		file_path = path;
	}

	// Function to read student data from a file (implementation missing)
    vector<Student> read_data() {
        vector<Student> student_vector; // Vector to store student data

        ifstream input_file("student_data.txt");
        if (input_file.is_open()) {
            while (!input_file.eof()) {
                Student s; // Create a new student
                input_file >> s.student_id;
                input_file >> s.name;
                input_file >> s.grade;
                input_file >> s.password;
                input_file >> s.num_subjects;
                for (int i = 0; i < s.num_subjects; ++i) {
                    input_file >> s.marks[i].subject;
                    input_file >> s.marks[i].score;
                }
                student_vector.push_back(s); // Add student to vector
            }
        }
        input_file.close();

        return student_vector;
    }

	// Function to write student data to a file (implementation missing)
	void write_data(const Student& s) {
		ofstream output_file("student_data.txt");
		if (output_file.is_open()) {
			output_file << s.student_id << endl;
			output_file << s.name << endl;
			output_file << s.grade << endl;
			output_file << s.password << endl;
			output_file << s.num_subjects << endl;
			for (int i = 0; i < s.num_subjects; ++i) {
				output_file << s.marks[i].subject << " " << s.marks[i].score << endl;
			}
			output_file << endl;
		}
		output_file.close();
	}

	// Function to parse data from a file (already implemented)
	vector<string> parse_data(const string& filename) {
        vector<string> data;
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data.push_back(line);
            }
            file.close();
        }
        else {
            cout << "Failed to open file: " << filename << endl;
        }

        return data;
    }

	// Function to format and write data to a file (already implemented)
	void format_data(const vector<int>& data, const string& filename) {
        ofstream file(filename);

        if (file.is_open()) {
            for (const int& item : data) {
                file << item << "\n";
            }

            file.close();
            cout << "Data formatted and written to file: " << filename << endl;
        }
        else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
};

#endif
