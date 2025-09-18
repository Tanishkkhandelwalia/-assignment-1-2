#include <iostream>
using namespace std;

class Stack
{
    static const int max = 5;
    int arr[max];
    int top = -1;

public:
    void push(int num)
    {
        if (top == max - 1){
            cout << "\nStack Full";
        }else{
            top++;
            arr[top]=num;
        }            
    }
    void pop()
    {
        int popped;
        if (top == -1)
            cout << "\nNot possible , stack is empty ";
        else
       { popped = arr[top];
        top--;
        cout<<"The number popped out is"<<popped<<endl;}
    }
    int peek()
    {
        if (top == -1)
            cout << "\nNot possible ,stack is empty ";
        int above = arr[top];
        return above;
    }
    void isEmpty()
    {
        if (top == -1)
            cout << "\nstack is empty ";
        else
            cout << "\nstack is not empty "<<endl;
    }
    void isFull()
    {
        if (top == max-1)
            cout << "\nStack Full";
        else
            cout << "\nstack not Full ";
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.peek()<<endl;
    s.display();
    s.pop();
    cout<<s.peek()<<endl;
    s.display();


    
}