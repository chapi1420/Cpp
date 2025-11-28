#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void resetStack() { top = -1; }

void push(int x) { stackArr[++top] = x; }
int pop() { return stackArr[top--]; }
bool isEmpty() { return top == -1; }

string decimalToBinary(int n) {
    resetStack();

    while (n > 0) {
        push(n % 2);
        n /= 2;
    }

    string bin = "";
    while (!isEmpty())
        bin += char(pop() + '0');

    return bin;
}

int main() {
    cout << decimalToBinary(19);
}
