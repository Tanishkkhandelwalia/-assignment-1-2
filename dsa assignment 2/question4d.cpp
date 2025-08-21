#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

int main() {
    string strArray[] = {"Banana", "Apple", "Mango", "Cherry", "Peach"};
    int n = sizeof(strArray) / sizeof(strArray[0]);

    
    sort(strArray, strArray + n);

    
    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << strArray[i] << endl;
    }

    return 0;
}
