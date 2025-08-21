#include <iostream>
using namespace std;

int main() {
    int r;
    cout<< "no of rows";
    cin>> r;

    int c;
    cout<<"enter no of columns";
    cin>> c;

    int matrix1[r][c];
    int matrix2[c][r];

    cout << "Enter elements of matrix1: ";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix1[i][j];
            matrix2[j][i] = matrix1[i][j];
        }
    }
    cout<<endl;

    cout << "Original matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transpose matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}