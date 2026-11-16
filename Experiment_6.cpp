#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
        : real(r), imag(i) {}

    // Function overloading
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

    void display(string message) {
        cout << message << ": ";
        display();
    }

    // Operator overloading
    Complex operator+(const Complex& c) {
        return Complex(real + c.real,
                      imag + c.imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1 + c2;

    c1.display("First Number");
    c2.display("Second Number");
    c3.display("Sum");

    return 0;
}
