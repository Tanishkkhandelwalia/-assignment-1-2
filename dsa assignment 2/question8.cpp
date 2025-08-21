#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 1, 2, 2, 3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;

        
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements: " << distinctCount << endl;

    return 0;
}
