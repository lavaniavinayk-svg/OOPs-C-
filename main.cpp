//write a  generic
//stack or queue class using templates . test with int float and std string. give me a simple code for this question.
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
    T arr[5];
    int top;

public:

    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 4) {
            cout << "Stack Overflow!" << endl;
        }
        else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        }
        else {
            cout << arr[top] << " popped from stack" << endl;
            top--;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    cout << "\n--- INTEGER STACK ---" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();
    s1.pop();
    s1.display();

    cout << "\n--- FLOAT STACK ---" << endl;
    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.display();
    s2.pop();

    cout << "\n--- STRING STACK ---" << endl;
    Stack<string> s3;
    s3.push("Hello");
    s3.push("World");
    s3.display();
    s3.pop();
    s3.display();

    return 0;
}
