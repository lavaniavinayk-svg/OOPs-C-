
#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    int accountNumber;
    string name;
    double balance;

public:

    // Constructor
    BankAccount(int acc, string n, double b) {
        accountNumber = acc;
        name = n;
        balance = b;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money deposited successfully!" << endl;
        }
        else {
            cout << "Invalid amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Money withdrawn successfully!" << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Display account details
    void display() {
        cout << "\n--- ACCOUNT DETAILS ---" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs." << balance << endl;
    }
};

int main() {

    BankAccount account(101, "Vinay", 5000);

    int choice;
    double amount;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Display Account Details";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                account.display();
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                cout << "Thank you for using our bank!";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}
