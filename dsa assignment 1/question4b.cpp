#include<iostream>
using namespace std;

int main(){

    int r1 =2 ;
    int c1=3;

    int r2= 3;
    int c2 = 2;

    int matrix1[r1][c1] ={{1,2,3},{4,5,6}};
    int matrix2[r2][c2]= {{7,8},{9,10},{11,12}};

    int resultmatrix[r1][c2] = {0};

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                resultmatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }


     cout << "Result matrix: "<< endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << resultmatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}