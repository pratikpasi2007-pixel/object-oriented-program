#include <iostream>
using namespace std;

class Person {
public:
    string name;

    void displayPerson() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    int rollNo;

    void displayStudent() {
        cout << "Roll No: " << rollNo << endl;
    }
};

class GraduateStudent : public Student {
public:
    string researchTopic;

    void displayGraduate() {
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent g;

    g.name = "Rahul";
    g.rollNo = 101;
    g.researchTopic = "Artificial Intelligence";

    g.displayPerson();
    g.displayStudent();
    g.displayGraduate();

    return 0;
}
