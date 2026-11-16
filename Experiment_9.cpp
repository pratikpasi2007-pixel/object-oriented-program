#include <iostream>
#include <stdexcept>
using namespace std;

class BankingException : public runtime_error {
public:
    BankingException(string msg)
        : runtime_error(msg) {}
};

class InsufficientBalance : public BankingException {
public:
    InsufficientBalance()
        : BankingException("Insufficient Balance!") {}
};

class InvalidAmount : public BankingException {
public:
    InvalidAmount()
        : BankingException("Invalid Amount!") {}
};

class BankAccount {
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount) {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientBalance();

        balance -= amount;
        cout << "Withdrawal Successful\n";
    }

    void display() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount b(5000);

    try {
        b.withdraw(6000);
    }
    catch (const InsufficientBalance& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidAmount& e) {
        cout << e.what() << endl;
    }
    catch (const BankingException& e) {
        cout << e.what() << endl;
    }

    b.display();

    return 0;
}
