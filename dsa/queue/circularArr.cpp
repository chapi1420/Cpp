#include<iostream>
using namespace std;


struct CircularQueue {
    int arr[5];
    int front, rear, count;
};

void init(CircularQueue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

bool isFull(CircularQueue &q) {
    return q.count == 5;
}

bool isEmpty(CircularQueue &q) {
    return q.count == 0;
}

void enqueue(CircularQueue &q, int val) {
    if (isFull(q)) {
        cout << "Queue Overflow\n";
        return;
    }
    q.rear = (q.rear + 1) % 5;
    q.arr[q.rear] = val;
    q.count++;
}

int dequeue(CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue Underflow\n";
        return -1;
    }
    int val = q.arr[q.front];
    q.front = (q.front + 1) % 5;
    q.count--;
    return val;
}

int peek(CircularQueue &q) {
    if (isEmpty(q)) return -1;
    return q.arr[q.front];
}

void display(CircularQueue &q) {
    if (isEmpty(q)) {
        cout << "Queue empty\n";
        return;
    }
    int idx = q.front;
    for (int i = 0; i < q.count; i++) {
        cout << q.arr[idx] << " ";
        idx = (idx + 1) % 5;
    }
    cout << endl;
}


int main() {
    CircularQueue q;
    init(q);

    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);
    enqueue(q, 25);

    cout << "Dequeued: " << dequeue(q) << endl;

    enqueue(q, 100);  

    cout << "Queue: ";
    display(q);

    return 0;
}
