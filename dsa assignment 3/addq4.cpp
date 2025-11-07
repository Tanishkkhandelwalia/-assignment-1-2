#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) cin >> temperatures[i];

    vector<int> answer(n, 0); 
    stack<int> st;            

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            answer[prev] = i - prev; 
        }
        st.push(i);
    }

    for (int x : answer)
        cout << x << " ";
    return 0;
}
