#include <iostream>
#include <string>
using namespace std;

// Structures
struct Mark {
    int math;
    int coding;
    int AI;
    int cn; // communication
    float average;
};

struct Student {
    string name;
    string ID;
    Mark mar;
    string GPA; // Changed to string
};

// Functions
void decor() {
    cout << "...............*****...............\n";
}

void acceptor(Student** table, int sec, int stud) {
    cout << "Student information filling form\n";
    decor();
    for (int i = 0; i < sec; i++) {
        cout << "Section " << (i + 1) << " data entry:\n";
        for (int j = 0; j < stud; j++) {
            cout << "Enter name: ";
            cin >> table[i][j].name;
            cout << "Enter ID: ";
            cin >> table[i][j].ID;
            cout << "Enter marks of the student:\n";
            cout << "Enter math mark: ";
            cin >> table[i][j].mar.math;
            cout << "Enter coding mark: ";
            cin >> table[i][j].mar.coding;
            cout << "Enter AI mark: ";
            cin >> table[i][j].mar.AI;
            cout << "Enter communication mark: ";
            cin >> table[i][j].mar.cn;

            // Average calculator
            table[i][j].mar.average = (table[i][j].mar.cn + table[i][j].mar.AI + table[i][j].mar.coding + table[i][j].mar.math) / 4.0;
        }
        decor();
    }
}

void calcGPA(float average, string* GPA) { // Change char* to string*
    if (average > 90) {
        *GPA = "A+";
    } else if (average > 85) {
        *GPA = "A";
    } else if (average > 80) {
        *GPA = "A-";
    } else if (average > 75) {
        *GPA = "B+";
    } else if (average > 70) {
        *GPA = "B";
    } else if (average > 60) {
        *GPA = "C";
    } else if (average > 50) {
        *GPA = "D";
    } else {
        *GPA = "F";
    }
}

int main() {
    int sec, stud; // Number of sections and students in each class
    cout << "Enter the number of sections: \n";
    cin >> sec;
    cout << "Enter the number of students in each section: \n";
    cin >> stud;
    cout << "Number of sections and students in each class taken successfully\n";
    decor();

    // Create the dynamic 2D array
    Student** table = new Student*[sec];
    for (int i = 0; i < sec; i++) {
        table[i] = new Student[stud];
    }

    cout << "Data blueprint completed.\n";
    decor();
    
    // Accept student data
    acceptor(table, sec, stud);

    // Calculate GPA for each student
    for (int i = 0; i < sec; i++) {
        for (int j = 0; j < stud; j++) {
            string GPA; // Change char to string
            calcGPA(table[i][j].mar.average, &GPA);
            table[i][j].GPA = GPA; // Assign calculated GPA to student
        }
    }

    // Display the results
    for (int i = 0; i < sec; i++) {
        for (int j = 0; j < stud; j++) {
            cout << "Student Name: " << table[i][j].name << ", ID: " << table[i][j].ID
                 << ", Average: " << table[i][j].mar.average << ", GPA: " << table[i][j].GPA << endl;
        }
    }

    // Cleanup
    for (int i = 0; i < sec; i++) {
        delete[] table[i];
    }
    delete[] table;

    return 0;
}
