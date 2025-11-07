#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {

        // Pop all smaller elements
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        // If stack top is greater → it is NGE
        if (!st.empty())
            ans[i] = st.top();

        // Push current element
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    vector<int> result = nextGreaterElements(arr);

    for (int x : result) cout << x << " ";
}


