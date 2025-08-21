#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};  
    int n = 8; 
    int size = sizeof(arr) / 4;

    int missing = n;  

    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            missing = i + 1;
            break;
        }
    }

    cout << "Missing number is: " << missing << endl;

    return 0;
}
