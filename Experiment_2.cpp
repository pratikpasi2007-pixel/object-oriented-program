#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;

protected:
    double balance;

public:
    string name;

    BankAccount(int acc, string n, double b) {
        accountNumber = acc;
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int acc, string n, double b)
        : BankAccount(acc, n, b) {}

    void addInterest() {
        balance += balance * 0.05;
    }
};

int main() {
    SavingsAccount s(101, "Rahul", 5000);

    s.deposit(1000);
    s.addInterest();
    s.display();

    return 0;
}
