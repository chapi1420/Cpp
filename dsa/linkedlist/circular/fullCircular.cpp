#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* n = new Node();
    n->data = value;
    n->next = n->prev = nullptr;
    return n;
}

void insertBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;

    head = newNode;
}

void insertEnd(Node*& head, int value) {
    if (head == nullptr) {
        insertBeginning(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
}

void insertMid(Node*& head, int value, int position) {
    if (position <= 1 || head == nullptr) {
        insertBeginning(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
        if (temp == head) {   
            insertEnd(head, value);
            return;
        }
    }

    Node* newNode = createNode(value);
    Node* nextNode = temp->next;

    newNode->next = nextNode;
    newNode->prev = temp;

    temp->next = newNode;
    nextNode->prev = newNode;
}

void deleteBeg(Node*& head) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    if (head->next == head) { 
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head->prev;
    Node* temp = head;

    head = head->next;

    tail->next = head;
    head->prev = tail;

    delete temp;
}

void deleteEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head->prev;
    Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    delete tail;
}

void deleteMid(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    if (position == 1) {
        deleteBeg(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position; i++) {
        temp = temp->next;
        if (temp == head) {
            cout << "Position out of range.\n";
            return;
        }
    }

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete temp;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
}

int searcher(Node* head, int elem) {
    if (head == nullptr) return -1;

    Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == elem) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    displayList(head);

    insertBeginning(head, 5);
    displayList(head);

    insertMid(head, 45, 2);
    displayList(head);

    cout << "45 found at: position " << searcher(head, 45) << endl;

    deleteMid(head, 3);
    displayList(head);

    deleteBeg(head);
    displayList(head);

    deleteEnd(head);
    displayList(head);

    return 0;
}
