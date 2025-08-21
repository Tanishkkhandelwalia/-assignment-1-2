#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "you are good";
    string reversed = "";

   
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;
}
