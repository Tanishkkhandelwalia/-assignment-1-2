#include<bits/stdc++.h>  
using namespace std;

class node{
    public:
    int data;
    node* next;   
};

node* head;

void  createcll(){
    head =0;
    int choice =1;
    while(choice){
    node*newnode = new node;
    cout<< "enter data " ;
    cin>> newnode->data;
    newnode->next =0;

    node*temp;
    if(head==0){
        head = temp = newnode; 
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;

    cout<<"you want to insert the node ?(0,1) " ;
    cin>> choice;
}
}

void display(){
    if(head==0){
        cout<<"list is empty " ;
    }
    else{
        node*temp ;
        temp = head;
        while(temp->next!=head){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<  temp->data<<" ";
    }
    cout<< endl;
}

int size(){
    int count =0;
    node*temp;
    temp = head;
   
    do{
        count++;
        temp = temp->next;
    }while(temp!=head);

    return count;
}

int main(){
    createcll();
    cout<<"circular linked list ";
    display();
    cout<<"the sixe of the circular list is"<<size();

}