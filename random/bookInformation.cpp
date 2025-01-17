#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    int publicationYear;
    string status;
};

void determineStatus(Book &book) {
    if (book.publicationYear < 2010) {
        book.status = "Out dated";
    } else if (book.publicationYear >= 2011 && book.publicationYear <= 2023) {
        book.status = "Medium";
    } else {
        book.status = "Latest";
    }
}

void displayBooks(const Book books[], int size) {
    cout << "Title\t\tPublication Year\tStatus\n";
    for (int i = 0; i < size; ++i) {
        cout << books[i].title << "\t\t" << books[i].publicationYear << "\t\t" << books[i].status << '\n';
    }
}

int main() {
    const int numBooks = 5;
    Book books[numBooks];

    for (int i = 0; i < numBooks; ++i) {
        cout << "Enter title for book " << (i + 1) << ": ";
        cin.ignore(); 
        getline(cin, books[i].title);
        cout << "Enter publication year for book " << (i + 1) << ": ";
        cin >> books[i].publicationYear;
        determineStatus(books[i]);
    }

    displayBooks(books, numBooks);

    return 0;
}
