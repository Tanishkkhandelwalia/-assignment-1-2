#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char c) {
        if (isFull()) {
            cout << " Stack Overflow "<<endl;
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow"<< endl;
            return '\0';
        }
        return arr[top--];
    }
};

int main() {
    string input;
    cout << "Enter a string ";
    getline(cin, input);

    Stack s;

    for (char c : input) {
        s.push(c);
    }

    string reversed = "";
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    cout << "Reversed string " << reversed << endl;

    return 0;
}
