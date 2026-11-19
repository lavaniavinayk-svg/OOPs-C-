#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    double balance;

public:
    // Constructor
    BankAccount(string n, double b)
    {
        name = n;
        balance = b;
    }

    // Function overloading: deposit without message
    void deposit(double amount)
    {
        balance += amount;
    }

    // Function overloading: deposit with message
    void deposit(double amount, string message)
    {
        balance += amount;
        cout << message << endl;
    }

    // Display account details
    void display()
    {
        cout << name << " Balance: " << balance << endl;
    }

    // Operator overloading (+)
    BankAccount operator+(BankAccount &other)
    {
        return BankAccount(name + " & " + other.name,
                          balance + other.balance);
    }
};

int main()
{
    BankAccount a1("Rahul", 5000);
    BankAccount a2("Aman", 3000);

    a1.deposit(1000);
    a2.deposit(500, "Deposit successful!");

    a1.display();
    a2.display();

    BankAccount combined = a1 + a2;

    cout << "\nCombined account balances:" << endl;
    combined.display();

    return 0;
}