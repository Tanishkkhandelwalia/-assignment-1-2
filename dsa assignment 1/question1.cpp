#include<iostream>
using namespace std;
int main(){
    int arr[5] = {2,3,4,5,6}; // create

    cout<<"displaying array"; // display
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    int n;
    cout<<"enter value of n ";
    cin>>n;

    int arr[n];

    cout<<"inserting elements of array "; // inseert
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

     int pos;// delete
    cout << "Enter position to delete: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;

    int target =2; // linear search
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"target"<< target<<"is found at index "<< i;
        }
    }
    
}