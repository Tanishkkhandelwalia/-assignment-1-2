#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);                      
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQueue s;
    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << (s.empty() ? "Stack Empty" : "Not Empty") << endl;

    return 0;
}
