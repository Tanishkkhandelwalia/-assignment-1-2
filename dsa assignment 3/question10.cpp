#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool canSortWithStack(vector<int> A) {
    int n = A.size();
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    int idx = 0; 
    stack<int> st;

    for (int x : A) {
        st.push(x);
        
        while (!st.empty() && st.top() == sortedA[idx]) {
            st.pop();
            idx++;
        }
    }

    return st.empty(); 
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    if (canSortWithStack(A))
        cout << "YES\n";   
    else
        cout << "NO\n";    
}
