#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

struct QueueLL {
    Node* front;
    Node* rear;
};

void init(QueueLL &q) {
    q.front = q.rear = NULL;
}

void enqueue(QueueLL &q, int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = temp;
        return;
    }

    q.rear->next = temp;
    q.rear = temp;
}

int dequeue(QueueLL &q) {
    if (q.front == NULL) {
        cout << "Queue Underflow\n";
        return -1;
    }

    Node* temp = q.front;
    int val = temp->data;

    q.front = q.front->next;
    if (q.front == NULL) q.rear = NULL;

    delete temp;
    return val;
}

int peek(QueueLL &q) {
    if (q.front == NULL) return -1;
    return q.front->data;
}

void display(QueueLL &q) {
    Node* curr = q.front;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


int main() {
    QueueLL q;
    init(q);

    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);

    cout << "Front: " << peek(q) << endl;

    cout << "Dequeued: " << dequeue(q) << endl;

    cout << "Queue now: ";
    display(q);

    return 0;
}
