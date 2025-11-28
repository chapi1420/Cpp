#include <iostream>
using namespace std;

struct Queue {
    int arr[100];
    int front;
    int rear;
};

void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

bool isFull(Queue &q) {
    return q.rear == 99;
}

bool isEmpty(Queue &q) {
    return q.front > q.rear;
}

void enqueue(Queue &q, int val) {
    if (isFull(q)) {
        cout << "Queue Overflow\n";
        return;
    }
    q.arr[++q.rear] = val;
}

int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return q.arr[q.front++];
}

int peek(Queue &q) {
    if (isEmpty(q)) return -1;
    return q.arr[q.front];
}

void display(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue empty\n";
        return;
    }
    for (int i = q.front; i <= q.rear; i++)
        cout << q.arr[i] << " ";
    cout << endl;
}

int main() {
    Queue q;
    init(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Front element: " << peek(q) << endl;

    cout << "Dequeued: " << dequeue(q) << endl;

    cout << "Queue: ";
    display(q);

    return 0;
}
