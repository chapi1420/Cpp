#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    int itno;
    string itname;
    double unitPrice;
    int qty;
    double totalPrice;
};

// Function Declarations
void accept(Item* items, int n);
void writeFile(const Item* items, int n, const string& filename);
void readAndDisplay(const string& filename, Item*& items, int& n);

int main() {
    int n;
    Item* items = nullptr; // Pointer for dynamic array
    string filename = "item_records2.txt";

    cout << "Enter the number of items: ";
    cin >> n;

    // Dynamically allocate memory for items
    items = new Item[n];

    accept(items, n);
    writeFile(items, n, filename);
    readAndDisplay(filename, items, n);

    // Free dynamically allocated memory
    delete[] items;

    return 0;
}

// Function to accept item records
void accept(Item* items, int n) {
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
void writeFile(const Item* items, int n, const string& filename) {
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

// Combined function to read item records from a file and display them
void readAndDisplay(const string& filename, Item*& items, int& n) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    n = 0;
    items = new Item[100]; // Initial allocation, can resize later
    while (inFile >> items[n].itno >> items[n].itname >> items[n].unitPrice >> items[n].qty >> items[n].totalPrice) {
        n++;
        if (n % 100 == 0) { // Resize if needed
            Item* temp = new Item[n + 100]; // Allocate new larger array
            for (int i = 0; i < n; ++i) {
                temp[i] = items[i]; // Copy old items
            }
            delete[] items; // Free old array
            items = temp; // Point to new array
        }
    }

    inFile.close(); 

    // Display the records
    cout << "\nItem Records:\n";
    cout << "Item No | Item Name | Unit Price | Quantity | Total Price\n";
    cout << "---------------------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << items[i].itno << " | " << items[i].itname << " | "
             << items[i].unitPrice << " | " << items[i].qty << " | "
             << items[i].totalPrice << endl;
    }
}
