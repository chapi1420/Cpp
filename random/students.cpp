#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    unsigned id;
    float marks[5];
    float average;
    unsigned rank;
};

float calculateAverage(float marks[], int size) {
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += marks[i];
    }
    return sum / size;
}

bool compareStudents(const Student &a, const Student &b) {
    return a.average > b.average; 
}

void displayStudents(const vector<Student> &students) {
    cout << fixed << setprecision(2);
    cout << "ID\tAverage\tRank\n";
    for (const auto &student : students) {
        cout << student.id << "\t" << student.average << "\t" << student.rank << '\n';
    }
}

int main() {
    const int numStudents = 3; 
    vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter ID for student " << (i + 1) << ": ";
        cin >> students[i].id;
        cout << "Enter 5 marks for student " << (i + 1) << ": ";
        for (int j = 0; j < 5; ++j) {
            cin >> students[i].marks[j];
        }
        students[i].average = calculateAverage(students[i].marks, 5);
    }

    sort(students.begin(), students.end(), compareStudents);
    for (int i = 0; i < numStudents; ++i) {
        students[i].rank = i + 1; 
    }

    displayStudents(students);

    return 0;
}
