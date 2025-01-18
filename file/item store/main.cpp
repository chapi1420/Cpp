#include <iostream>
#include <fstream>
#include <string>
#include<string>

using namespace std;

const int MAX_ITEMS = 100; // Maximum number of items

struct Item {
    int itno;
    string itname;
    double unitPrice;
    int qty;
    double totalPrice;
};

// Function Declarations
void accept(Item items[], int n);
void writeFile(const Item items[], int n, const string& filename);
void readFile(const string& filename, Item items[], int& n);
void display(const Item items[], int n);

int main() {
    int n;
    Item items[MAX_ITEMS];
    string filename = "item_records.txt";

    cout << "Enter the number of items (max " << MAX_ITEMS << "): ";
    cin >> n;

    if (n > MAX_ITEMS) {
        cout << "Error: Number of items exceeds maximum limit." << endl;
        return 1;
    }

    accept(items, n);
    writeFile(items, n, filename);
    readFile(filename, items, n);
    display(items, n);

    return 0;
}

// Function to accept item records
void accept(Item items[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter item number: ";
        cin >> items[i].itno;
        cout << "Enter item name: ";
        cin >> items[i].itname;
        cout << "Enter unit price: ";
        cin >> items[i].unitPrice;
        cout << "Enter quantity: ";
        cin >> items[i].qty;
        items[i].totalPrice = items[i].unitPrice * items[i].qty;
    }
}

// Function to write item records to a file
void writeFile(const Item items[], int n, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        outFile << items[i].itno << " " << items[i].itname << " "
                << items[i].unitPrice << " " << items[i].qty << " "
                << items[i].totalPrice << endl;
    }

    outFile.close();
}

// Function to read item records from a file
void readFile(const string& filename, Item items[], int& n) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    n = 0; // Reset item count
    while (inFile >> items[n].itno >> items[n].itname >> items[n].unitPrice >> items[n].qty >> items[n].totalPrice) {
        n++;
        if (n >= MAX_ITEMS) break; // Prevent overflow
    }

    inFile.close();
}

// Function to display item records
void display(const Item items[], int n) {
    cout << "\nItem Records:\n";
    cout << "Item No | Item Name | Unit Price | Quantity | Total Price\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << items[i].itno << " | " << items[i].itname << " | "
             << items[i].unitPrice << " | " << items[i].qty << " | "
             << items[i].totalPrice << endl;
    }
}
