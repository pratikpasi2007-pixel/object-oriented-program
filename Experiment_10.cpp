#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream file;

    // Write student records
    file.open("students.csv", ios::out);

    file << "101,Rahul,90\n";
    file << "102,Amit,85\n";
    file << "103,Neha,95\n";

    file.close();

    // Read student records
    file.open("students.csv", ios::in);

    string line;

    cout << "Student Records:\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    // tellg
    cout << "Position: " << file.tellg() << endl;

    // seekg
    file.clear();
    file.seekg(0);

    cout << "\nFirst Record: ";
    getline(file, line);
    cout << line << endl;

    file.close();

    // Demonstrate seekp and tellp
    file.open("students.csv", ios::out | ios::app);

    cout << "Write Position: " << file.tellp() << endl;

    file.seekp(0, ios::end);
    file << "104,Sam,80\n";

    file.close();

    return 0;
}
