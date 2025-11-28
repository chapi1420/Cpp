#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stackArr[top--];
}

int peek() {
    if (isEmpty()) {
        cout << "Empty\n";
        return -1;
    }
    return stackArr[top];
}


int main() {
    // Push elements
    push(10);
    push(20);
    push(30);

    // Display top element
    cout << "Top element: " << peek() << endl;

    // Pop an element
    cout << "Popped: " << pop() << endl;

    // Push another
    push(40);

    // Pop all to show stack behavior
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;   // this will trigger underflow

    return 0;
}

