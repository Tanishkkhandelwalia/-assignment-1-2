#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next ;
};

node*head;
int cnt;

void  deleteatpos(int pos ){

    node*nextnode;
    node*temp;
    temp = head;
    int i=1;

    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    nextnode= temp->next;
    temp->next = nextnode->next;
    free(nextnode);

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

    cnt++;
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

cout<<" you want to insert at some pos ?(0,1) " ;
bool tell ;
cin>> tell ;

if(tell){
int pos;
cout<<"enter position ";
cin>>pos;
  deleteatpos(pos);
  display();
}

}
