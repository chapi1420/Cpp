#include <iostream>
#include <cctype>
using namespace std;

#define MAX 100

char opStack[MAX];    
int topOp = -1;

void pushOp(char x) { opStack[++topOp] = x; }
char popOp() { return opStack[topOp--]; }
char peekOp() { return opStack[topOp]; }
bool isEmptyOp() { return topOp == -1; }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string changer(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            pushOp(ch);
        }

        else if (ch == ')') {
            while (!isEmptyOp() && peekOp() != '(') {
                postfix += popOp();
            }
            popOp(); 
        }

        else {
            while (!isEmptyOp() && precedence(peekOp()) >= precedence(ch)) {
                postfix += popOp();
            }
            pushOp(ch);
        }
    }

    while (!isEmptyOp()) {
        postfix += popOp();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = changer(infix);

    cout << "Postfix: " << postfix << endl;

    return 0;
}
