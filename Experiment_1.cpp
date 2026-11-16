#include <iostream>
using namespace std;

int main() {
    int age;
    float marks;
    char grade;
    bool passed;

    const float PI = 3.14159;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter marks: ";
    cin >> marks;

    cout << "Enter grade: ";
    cin >> grade;

    passed = marks >= 40;

    cout << "\n--- Student Details ---\n";
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << passed << endl;
    cout << "PI: " << PI << endl;

    cout << "Marks + 5: " << marks + 5 << endl;
    cout << "Marks * 2: " << marks * 2 << endl;

    return 0;
}
