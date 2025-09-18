#include <iostream>
#define MAX 100
using namespace std;

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;  
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int main() {
    char infix[MAX], postfix[2 * MAX]; 
    int i = 0, j = 0;
    cout << "Enter infix expression: ";
    cin.getline(infix, MAX);

    Stack s;

    while (infix[i] != '\0') {
        char c = infix[i];

        if (isOperand(c)) {
            postfix[j++] = c;  
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(') {
                s.pop();  
            } else {
                cout << "Error: Mismatched parentheses\n";
                return 1;
            }
        } else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                
                if (c == '^' && s.peek() == '^')
                    break;
                postfix[j++] = s.pop();
            }
            s.push(c);
        } else if (c == ' ' || c == '\t') {
           
        } else {
            cout << "Error: Invalid character '" << c << "' encountered.\n";
            return 1;
        }

        i++;
    }

    
    while (!s.isEmpty()) {
        if (s.peek() == '(') {
            cout << "Error: Mismatched parentheses\n";
            return 1;
        }
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0';

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
