#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[] = {1,2,3,4,5};
    n = sizeof (arr) / 4;

    int start =0;
    int end =n-1;

    while (start<end){

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start ++;
        end --;
    }

    cout<<" reverse of array is ";
    for(int i=0;i<n;i++){
        cout<< arr[i] << " ";
    }

    return 0;

}