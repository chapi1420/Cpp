#include <iostream>
using namespace std;

#define MAX 100
int stackArr[MAX];
int top = -1;

void resetStack() { top = -1; }

void push(int x) { stackArr[++top] = x; }
int pop() { return stackArr[top--]; }
bool isEmpty() { return top == -1; }

bool isPalindrome(string s) {
    resetStack();

    for (int i = 0; i < s.length(); i++)
        push(s[i]);

    for (int i = 0; i < s.length(); i++)
        if (s[i] != pop()) return false;

    return true;
}

int main() {
    cout << (isPalindrome("madam") ? "YES" : "NO");
}
