//use stl containers vector map unordered map and algorithm sort find if transform to process a student marks dataset
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    // Student dataset
    vector<pair<string, int>> students = {
        {"Amit", 85},
        {"Rahul", 65},
        {"Priya", 92},
        {"Sneha", 45},
        {"Karan", 75}
    };

    // 1. VECTOR - Display student records
    cout << "\n--- STUDENT DATASET ---\n";

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }


    // 2. MAP - Store students in sorted order
    map<int, string> studentMap;

    int roll = 101;

    for (auto s : students) {
        studentMap[roll++] = s.first;
    }

    cout << "\n--- STUDENT MAP ---\n";

    for (auto s : studentMap) {
        cout << s.first << " : " << s.second << endl;
    }


    // 3. UNORDERED_MAP - Store name and marks
    unordered_map<string, int> marks;

    for (auto s : students) {
        marks[s.first] = s.second;
    }

    cout << "\n--- UNORDERED MAP ---\n";

    for (auto s : marks) {
        cout << s.first << " : " << s.second << endl;
    }


    // 4. SORT - Sort students by marks
    sort(students.begin(), students.end(),
         [](auto a, auto b) {
             return a.second > b.second;
         });

    cout << "\n--- SORTED BY MARKS ---\n";

    for (auto s : students) {
        cout << s.first << " : " << s.second << endl;
    }


    // 5. FIND - Search for a particular mark
    auto it = find_if(students.begin(), students.end(),
                      [](auto s) {
                          return s.second == 92;
                      });

    cout << "\n--- FIND MARKS ---\n";

    if (it != students.end()) {
        cout << "Student with 92 marks: " << it->first << endl;
    }
    else {
        cout << "Marks not found!" << endl;
    }


    // 6. IF - Find students who passed
    cout << "\n--- PASSED STUDENTS ---\n";

    for (auto s : students) {
        if (s.second >= 40) {
            cout << s.first << " : " << s.second << endl;
        }
    }


    // 7. TRANSFORM - Convert marks into percentages
    vector<double> percentage(students.size());

    transform(students.begin(), students.end(),
              percentage.begin(),
              [](auto s) {
                  return (s.second / 100.0) * 100;
              });

    cout << "\n--- STUDENT PERCENTAGES ---\n";

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].first << " : "
             << percentage[i] << "%" << endl;
    }

    return 0;
}
