#include <iostream>
#include <string>
using namespace std;

bool isBalanced(const string& expr) {
    int count = 0;  
    for (char ch : expr) {
        if (ch == '(') {
            count++;  
        } else if (ch == ')') {
            count--;  
            if (count < 0) {
                return false;
            }
        }
    }

    
    return count == 0;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (isBalanced(expression)) {
        cout << "Parentheses are balanced"<<endl;
    } else {
        cout << "Parentheses are NOT balanced"<< endl;
    }

    return 0;
}
