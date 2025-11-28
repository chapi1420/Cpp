#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void resetStack() { top = -1; }

void push(int x) { stackArr[++top] = x; }
int pop() { return stackArr[top--]; }
bool isEmpty() { return top == -1; }

string reverseString(string s) {
    resetStack();

    for (int i = 0; i < s.length(); i++)
        push(s[i]);

    string rev = "";
    while (!isEmpty())
        rev += pop();

    return rev;
}

int main() {
    cout << reverseString("hello"); 
}
