#include <iostream>
using namespace std;

int main() {
    int A[] = {8, 4, 2, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int count = 0;

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }

    cout << "Number of inversions: " << count << endl;

    return 0;
}
