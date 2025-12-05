#include <iostream>
#include <cstring>
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

int evaluatePostfix(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == ' ') continue;

        if (isdigit(c)) {
            push(c - '0');   
        }

        else {
            int a = pop();
            int b = pop();

            switch (c) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
                default: cout << "Invalid Operator\n"; break;
            }
        }
    }
    return pop();
}

int main() {
    string exp;

    cout << "Enter a postfix expression: ";
    getline(cin, exp);

    int result = evaluatePostfix(exp);
    cout << "Result = " << result << endl;

    return 0;
}
