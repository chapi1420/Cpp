#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;

    Node() : prev(nullptr), data(0), next(nullptr) {}
};

void insertBeginning(Node*& head, int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(Node*& head, int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;     
}

void insertMid(Node*& head, int num, int position) {
    if (position <= 1) {
        insertBeginning(head, num);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) 
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteBeg(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

void deleteEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == nullptr) {   
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
}

void deleteMid(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (position <= 1) {
        deleteBeg(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    delete temp;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int searcher(Node* head, int elem){
    Node* temp =head;
    int pos =0;
    while(temp !=nullptr){
        if(temp->data ==elem){
            return pos;
        }
        pos++;
        temp =temp->next;
    }
    return -1;
}

int main() {
    Node* head = nullptr;   

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    cout << "Linked list: ";
    displayList(head);

    insertBeginning(head, 5);
    cout << "After inserting at beginning: ";
    displayList(head);

    insertMid(head, 45, 2);
    cout << "After inserting in middle: ";
    displayList(head);
    
    int pos =searcher(head, 45);
    cout<<"searching element: 45 in the list... position: "<<pos<<endl;

    deleteMid(head, 3);
    cout << "After deleting from middle: ";
    displayList(head);

    deleteBeg(head);
    cout << "After deleting beginning: ";
    displayList(head);

    deleteEnd(head);
    cout << "After deleting end: ";
    displayList(head);

    return 0;
}
