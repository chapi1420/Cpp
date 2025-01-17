#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    int itno;
    char itname[100]; // Fixed-size array for item name
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
    string filename = "item_records.bin";

    cout << "Enter the number of items: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n

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
        cin.ignore(); // Ignore the newline character

        cout << "Enter item name: ";
        cin.getline(items[i].itname, 100); // Read the entire line for item name

        cout << "Enter unit price: ";
        cin >> items[i].unitPrice;

        cout << "Enter quantity: ";
        cin >> items[i].qty;

        items[i].totalPrice = items[i].unitPrice * items[i].qty;
    }
}

// Function to write item records to a binary file
void writeFile(const Item* items, int n, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&n), sizeof(n)); // Write the number of items
    outFile.write(reinterpret_cast<const char*>(items), sizeof(Item) * n); // Write all items

    outFile.close();
}

// Combined function to read item records from a binary file and display them
void readAndDisplay(const string& filename, Item*& items, int& n) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(&n), sizeof(n)); // Read the number of items
    items = new Item[n]; // Allocate memory for items
    inFile.read(reinterpret_cast<char*>(items), sizeof(Item) * n); // Read all items

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
