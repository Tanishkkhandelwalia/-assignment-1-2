#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int count = 0;

    sort(arr, arr + n);

    int left = 0, right = 1;

    while (right < n) {
        int diff = arr[right] - arr[left];

        if (diff == k) {
            count++;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
            if (left == right) right++;
        }
    }

    cout << "Number of pairs with difference " << k << ": " << count << endl;

    return 0;
}
