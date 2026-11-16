#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char* name;

public:
    // Default constructor
    Student() {
        name = new char[8];
        strcpy(name, "Unknown");
    }

    // Parameterized constructor
    Student(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy constructor
    Student(const Student& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
    }

    // Move constructor
    Student(Student&& s) noexcept {
        name = s.name;
        s.name = nullptr;
    }

    // Copy assignment operator
    Student& operator=(const Student& s) {
        if (this != &s) {
            delete[] name;
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }
        return *this;
    }

    // Move assignment operator
    Student& operator=(Student&& s) noexcept {
        if (this != &s) {
            delete[] name;
            name = s.name;
            s.name = nullptr;
        }
        return *this;
    }

    void display() {
        cout << (name ? name : "Empty") << endl;
    }

    // Destructor
    ~Student() {
        delete[] name;
    }
};

int main() {
    Student s1("Rahul");
    Student s2(s1);
    Student s3;
    s3 = s1;

    Student s4(std::move(s1));
    Student s5("Amit");
    s5 = std::move(s2);

    s3.display();
    s4.display();
    s5.display();

    return 0;
}
