#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> s;   
    long long minEle;     

public:
    void push(long long x) {
        if (s.empty()) {
            s.push(x);
            minEle = x;
        } 
        else if (x >= minEle) {
            s.push(x);
        } 
        else {
            
            s.push(2*x - minEle);
            minEle = x;
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        long long top = s.top();
        s.pop();

        if (top < minEle) {
            
            cout << "Popped: " << minEle << endl;
            minEle = 2*minEle - top;
        } else {
            cout << "Popped: " << top << endl;
        }
    }

    long long top() {
        if (s.empty()) return -1;

        long long top = s.top();
        return (top < minEle) ? minEle : top;
    }

    long long getMin() {
        if (s.empty()) return -1;
        return minEle;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    SpecialStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    cout << "Current Min: " << st.getMin() << endl; 
    st.pop();  
    cout << "Current Min: " << st.getMin() << endl; 
    st.pop(); 
    cout << "Current Min: " << st.getMin() << endl; 
    st.pop();  
    cout << "Current Min: " << st.getMin() << endl; 
}
