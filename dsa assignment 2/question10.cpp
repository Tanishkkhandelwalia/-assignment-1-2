#include <iostream>
#include <string>
using namespace std;


bool isSubstring(const string &s1, const string &s2) {
    return s2.find(s1) != string::npos;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n = s.length();
    bool possible = false;

    
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            
            if (isSubstring(A, B) && isSubstring(A, C)) {
                possible = true;
                break;
            }
            
            if (isSubstring(B, A) && isSubstring(B, C)) {
                possible = true;
                break;
            }
            
            if (isSubstring(C, A) && isSubstring(C, B)) {
                possible = true;
                break;
            }
        }
        if (possible) break;
    }

    if (possible)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
