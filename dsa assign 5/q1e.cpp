#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next ;
};
node*head;

void  deleteatend(){

    if(head==0){
        cout<<" linked list is empty nothing to delete " << endl ;
    }
    else{

        node*temp = head;
        node*prevnode = head;

        while(temp->next!=0){
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next =0;
        delete temp;
    }
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
}

void display(){
    node*temp;
    temp= head;
    while(temp!=0){
        cout<< temp->data << " " ;
        temp =temp->next;
    }
}

int main(){
create();
cout<<"the linked list is ";
display();

cout<<" you want to delete at beginning ?(0,1) " ;
bool tell ;
cin>> tell ;
if(tell){
  deleteatend();
  cout<<"the linked list is ";
  display();
}

}
