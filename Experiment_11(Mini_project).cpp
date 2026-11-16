#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    Student(int r, string n, float m)
        : roll(r), name(n), marks(m) {}
};

class StudentManagement {
    vector<Student> students;

public:
    void addStudent() {
        int roll;
        string name;
        float marks;

        cout << "Enter Roll No: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        students.emplace_back(roll, name, marks);

        cout << "Student Added Successfully!\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No Students Found\n";
            return;
        }

        for (auto& s : students) {
            cout << "\nRoll: " << s.roll;
            cout << "\nName: " << s.name;
            cout << "\nMarks: " << s.marks << endl;
        }
    }

    void searchStudent() {
        int roll;
        cout << "Enter Roll No: ";
        cin >> roll;

        for (auto& s : students) {
            if (s.roll == roll) {
                cout << "Name: " << s.name << endl;
                cout << "Marks: " << s.marks << endl;
                return;
            }
        }

        cout << "Student Not Found\n";
    }

    void saveToFile() {
        ofstream file("students.csv");

        for (auto& s : students) {
            file << s.roll << ","
                 << s.name << ","
                 << s.marks << endl;
        }

        file.close();
        cout << "Records Saved!\n";
    }
};

int main() {
    StudentManagement sm;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Save Records\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sm.addStudent();
            break;

        case 2:
            sm.displayStudents();
            break;

        case 3:
            sm.searchStudent();
            break;

        case 4:
            sm.saveToFile();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}
