#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void acceptor(string** units, int chap, int cont[]) {
    cout << "Please enter the courses in each chapter below...\n";
    for (int i = 0; i < chap; ++i) {
        for (int c = 0; c < cont[i]; ++c) {
            cout << "Chapter: " << i + 1 << " Course: " << c + 1 << ": ";
            cin >> units[i][c];
        }
    }
}

int main() {
    int chap;
    cout << "Enter the number of chapters the course has: ";
    cin >> chap;

    // Input validation for chapters
    if (chap <= 0) {
        cout << "Number of chapters must be positive." << endl;
        return 1;
    }

    int* cont = new int[chap];

    for (int i = 0; i < chap; i++) {
        cout << "Enter the number of courses in chapter " << i + 1 << ": ";
        cin >> cont[i];

        // Input validation for courses
        if (cont[i] <= 0) {
            cout << "Number of courses in chapter " << i + 1 << " must be positive." << endl;
            delete[] cont; // Clean up before exiting
            return 1;
        }
    }

    string** units = new string*[chap];
    for (int i = 0; i < chap; ++i) {
        units[i] = new string[cont[i]];
    }
    acceptor(units, chap, cont);

    for (int i = 0; i < chap; i++) {
        ofstream outfile("chapter_" + to_string(i + 1) + ".txt");
        if (outfile.is_open()) {
            for (int j = 0; j < cont[i]; ++j) {
                outfile << units[i][j] << "\n";
            }
            outfile.close(); 
        }
    }

    // Merging into a single file
    string* chaplst = new string[chap];
    for (int i = 0; i < chap; i++) {
        chaplst[i] = "chapter_" + to_string(i + 1) + ".txt";
    }
    string course;

    ofstream writer("course outline.txt", ios::app); 
    if (writer.is_open()) {
        for (int i = 0; i < chap; i++) {
            ifstream reader(chaplst[i]);
            if (reader.is_open()) {
                while (getline(reader, course)) {
                    writer << course << "\n";
                }
                reader.close(); 
            }
        }
        writer.close(); // Close the writer after writing
    }

    // Clean up memory
    for (int i = 0; i < chap; i++) {
        delete[] units[i];
    }
    delete[] units;
    delete[] cont;
    delete[] chaplst; 

    return 0;
}
