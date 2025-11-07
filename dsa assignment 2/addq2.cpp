#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canSplit(string s) {
    vector<int> freq(26, 0);
    for(char c : s) freq[c - 'a']++;

    // If any character appears >= 3 times → always possible
    for(int f : freq)
        if(f >= 3) return true;

    return false;  // otherwise impossible
}

int main() {
    string s;
    cin >> s;

    if(canSplit(s))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

