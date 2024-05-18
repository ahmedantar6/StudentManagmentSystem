#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <vector>
#include <fstream>
using namespace std ;
class FileHandler {
private:
  string file_path;

public:
  FileHandler(const string& path); // Constructor to specify file path

  // Function to read student data from a file (implementation missing)
  void read_data();

  // Function to write student data to a file (implementation missing)
  void write_data();

  // Function to parse data from a file (already implemented)
  vector<string> parse_data(const string& filename);

  // Function to format and write data to a file (already implemented)
  void format_data(const vector<int>& data, const string& filename);
};

#endif
