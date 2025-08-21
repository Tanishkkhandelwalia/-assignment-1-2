#include <iostream>
#include <string>
using namespace std;


bool isVowel(char ch) {
    ch = tolower(ch);  
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    string input = "your name";
    string result = "";

    for (int i = 0; i < input.length(); i++) {
        if (!isVowel(input[i])) {
            result += input[i];
        }
    }

    cout << "Original string: " << input << endl;
    cout << "String without vowels: " << result << endl;

    return 0;
}
