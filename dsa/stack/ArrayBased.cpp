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

void display(){
    for(int i=top; i>0; i++){
        cout<<stackArr[i]<<endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element: " << peek() << endl;

    cout << "Popped: " << pop() << endl;

    push(40);
    display();

    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;
    cout << "Popped: " << pop() << endl;   


    return 0;
}

