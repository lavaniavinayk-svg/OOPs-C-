#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Student
{
public:
    string name;

    // Default constructor
    Student()
    {
        name = "Vinay";
        cout << "Default constructor" << endl;
    }

    // Parameterized constructor
    Student(string n)
    {
        name = n;
        cout << "Parameterized Constructor" << endl;
    }

    // Copy constructor
    Student(const Student &s)
    {
        name = s.name;
        cout << "Copy Constructor" << endl;
    }

    // Move constructor
    Student(Student &&s)
    {
        name = move(s.name);
        cout << "Move Constructor" << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Destructor" << endl;
    }
};

int main()
{
    Student s1;
    cout << "Name: " << s1.name << endl;

    Student s2("John");
    cout << "Name: " << s2.name << endl;

    Student s3(s2);
    cout << "Name: " << s3.name << endl;

    Student s4 = move(Student("Raj"));
    cout << "Name: " << s4.name << endl;

    return 0;
}