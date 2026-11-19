//create a custom exception herarchy write a program that throws and catched specific exception for a banking transaction scenerio
#include <iostream>
#include <exception>
using namespace std;

// Base Exception Class
class BankException : public exception {
public:
    virtual const char* what() const noexcept {
        return "Banking Error!";
    }
};

// Insufficient Balance Exception
class InsufficientBalance : public BankException {
public:
    const char* what() const noexcept override {
        return "Error: Insufficient balance!";
    }
};

// Invalid Amount Exception
class InvalidAmount : public BankException {
public:
    const char* what() const noexcept override {
        return "Error: Amount must be greater than zero!";
    }
};

// Bank Account Class
class BankAccount {
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        balance += amount;
        cout << "Amount deposited successfully!" << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmount();
        }

        if (amount > balance) {
            throw InsufficientBalance();
        }

        balance -= amount;
        cout << "Amount withdrawn successfully!" << endl;
    }

    void displayBalance() {
        cout << "Current Balance: Rs." << balance << endl;
    }
};

// Main Function
int main() {

    BankAccount account(5000);

    int choice;
    double amount;

    do {
        cout << "\n--- BANKING SYSTEM ---";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Check Balance";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        try {

            switch (choice) {

            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;

                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                account.withdraw(amount);
                break;

            case 3:
                account.displayBalance();
                break;

            case 4:
                cout << "Thank you for banking with us!";
                break;

            default:
                cout << "Invalid choice!";
            }

        }
        catch (const BankException& e) {
            cout << e.what() << endl;
        }

    } while (choice != 4);

    return 0;
}
