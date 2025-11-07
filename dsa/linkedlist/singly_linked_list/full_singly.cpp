#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//delete from beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

//delete from middle
void deleteFromPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Initial list: ";
    displayList(head);

    insertAtBeginning(head, 5);
    cout << "After inserting at beginning: ";
    displayList(head);

    insertAtPosition(head, 15, 3);
    cout << "After inserting at position 3: ";
    displayList(head);

    insertAtEnd(head, 40);
    cout << "After inserting at end: ";
    displayList(head);


    deleteFromPosition(head, 2);
    cout<<"after deleting from a position: ";
    displayList(head);

    deleteFromBeginning(head);
    cout<<"after deleting at the beginning: ";
    displayList(head);


    deleteFromEnd(head);
    cout<<"after deleting from the the end: ";
    displayList(head);


    

    return 0;
}
