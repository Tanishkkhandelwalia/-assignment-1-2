#include <iostream>
#include <cmath>  
#define MAX 100
using namespace std;

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;  
        }
        return arr[top--];
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int evaluatePostfix(const char* postfix) {
    Stack s;
    int i = 0;

    while (postfix[i] != '\0') {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            
            s.push(c - '0');
        } else if (isOperator(c)) {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        cout << "Error: Division by zero\n";
                        return -1;
                    }
                    result = val1 / val2; 
                    break;
                case '^': result = (int)pow(val1, val2); break;
                default:
                    cout << "Unknown operator: " << c << endl;
                    return -1;
            }
            s.push(result);
        } else if (c == ' ' || c == '\t') {
           
        } else {
            cout << "Invalid character in expression: " << c << endl;
            return -1;
        }

        i++;
    }

    return s.pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression (single-digit operands): ";
    cin.getline(postfix, MAX);
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
