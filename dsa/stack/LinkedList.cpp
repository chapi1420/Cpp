#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void init(Stack &s) {
    s.top = NULL;
}

void push(Stack &s, int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = s.top;
    s.top = temp;
}

int pop(Stack &s) {
    if (s.top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }

    Node* temp = s.top;
    int val = temp->data;
    s.top = s.top->next;
    delete temp;
    return val;
}

int peek(Stack s) {
    if (s.top == NULL) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return s.top->data;
}

bool search(Stack s, int key) {
    Node* curr = s.top;
    while (curr != NULL) {
        if (curr->data == key) return true;
        curr = curr->next;
    }
    return false;
}

int main() {
    Stack s;
    init(s);

    push(s, 5);
    push(s, 10);
    push(s, 20);

    cout << "Top element = " << peek(s) << endl;
    cout << "Pop = " << pop(s) << endl;
    cout << "Search 10? " << (search(s, 10) ? "Found" : "Not found") << endl;
    cout << "Search 100? " << (search(s, 100) ? "Found" : "Not found") << endl;
}
