#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
protected:
    int marks;
    string course;

public:
    Student(string n, int a, int m, string c) : Person(n, a)
    {
        marks = m;
        course = c;
    }

    void displayStudent()
    {
        displayPerson();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
    }
};

class GraduateStudent : public Student
{
private:
    string researchTopic;
    string faculty;

public:
    GraduateStudent(string n, int a, int m, string c,
                   string topic, string f)
        : Student(n, a, m, c)
    {
        researchTopic = topic;
        faculty = f;
    }

    void displayGraduateStudent()
    {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Faculty Guide: " << faculty << endl;
    }
};

int main()
{
    Student s1("Vinay Verma", 20, 98, "Computer Science");

    cout << "--- Student Details ---" << endl;
    s1.displayStudent();

    cout << endl;

    GraduateStudent g1(
        "Rahul Sharma", 24, 95,
        "Data Science",
        "Artificial Intelligence",
        "Dr. Anil Verma"
    );

    cout << "--- Graduate Student Details ---" << endl;
    g1.displayGraduateStudent();

    return 0;
}