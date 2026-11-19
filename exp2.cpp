#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string Name;

protected:
    int DOB;

public:
    Student(string name, int dob) : Name(name), DOB(dob)
    {
    }

    void display()
    {
        cout << "Name: " << Name << ", DOB: " << DOB << endl;
    }
};

class Graduate : public Student
{
protected:
    int marks;

public:
    Graduate(string name, int dob, int m)
        : Student(name, dob), marks(m)
    {
    }

    friend void showGrade(Graduate &g);
};

// Friend function
void showGrade(Graduate &g)
{
    g.display();

    cout << "Marks: " << g.marks << endl;
    cout << "DOB (protected access): " << g.DOB << endl;
}

int main()
{
    Graduate myDetails("Vinay", 2007, 85);

    showGrade(myDetails);  // Calling friend function

    return 0;
}