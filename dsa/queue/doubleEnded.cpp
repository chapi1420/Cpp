#include<iostream>
using namespace std;



struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Deque {
    Node* front;
    Node* rear;
};

void init(Deque &d) {
    d.front = d.rear = NULL;
}

void insertFront(Deque &d, int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = d.front;
    temp->prev = NULL;

    if (d.front == NULL)
        d.front = d.rear = temp;
    else {
        d.front->prev = temp;
        d.front = temp;
    }
}

void insertRear(Deque &d, int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = d.rear;

    if (d.rear == NULL)
        d.front = d.rear = temp;
    else {
        d.rear->next = temp;
        d.rear = temp;
    }
}

int deleteFront(Deque &d) {
    if (d.front == NULL) return -1;

    Node* temp = d.front;
    int val = temp->data;

    d.front = d.front->next;
    if (d.front == NULL) d.rear = NULL;
    else d.front->prev = NULL;

    delete temp;
    return val;
}

int deleteRear(Deque &d) {
    if (d.rear == NULL) return -1;

    Node* temp = d.rear;
    int val = temp->data;

    d.rear = d.rear->prev;
    if (d.rear == NULL) d.front = NULL;
    else d.rear->next = NULL;

    delete temp;
    return val;
}

void display(Deque &d) {
    Node* curr = d.front;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


int main() {
    Deque d;
    init(d);

    insertFront(d, 10);
    insertRear(d, 20);
    insertFront(d, 5);
    insertRear(d, 30);

    cout << "Deque: ";
    display(d);

    cout << "Delete front: " << deleteFront(d) << endl;
    cout << "Delete rear: " << deleteRear(d) << endl;

    cout << "Deque now: ";
    display(d);

    return 0;
}
