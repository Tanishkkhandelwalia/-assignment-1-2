#include<bits/stdc++.h>
using namespace std;

class node{
    

    public:
    int data;
    node * next ;
};
node*head;
node*tail;

void  insertatend(){

    node*temp;
    temp = tail;
    cout<<" now at end a new link will insert" << endl;
    node*newnode = new node;

    cout<<"enter data " ;
    cin >>newnode->data ;

    newnode->next = 0 ;

    if(head==0){
        head = newnode;
    }

    else{
        temp->next = newnode;
    }

    return ;
}

void create(){
    head = 0;
    node*temp;
    int choice =1;

    while(choice){
    node*newnode = new node;

    cout<<"enter data" ;
    cin >> newnode -> data ;
    cout << "data" <<  newnode -> data << endl;
    newnode->next =0;


    if(head ==0){
        head = temp = newnode; 
    }
    
    else{
            temp->next = newnode;
            temp = newnode;
    }

    cout<< "do yo wnat to contine (0,1) " << endl;;
    cout<<"choice ";
    cin>> choice;
}
tail = temp;
}

void display(){
    node*temp;
    temp= head;
    while(temp!=0){
        cout<< temp->data << " " ;
        temp =temp->next;
    }
    cout<<endl;
}

int main(){
create();
cout<<"the linked list is ";
display();

cout<<" you want to insert at end ?(0,1) " ;
bool tell ;
cin>> tell ;
if(tell){
  insertatend();
  cout<<"the linked list is ";
  display();
}

}
