#include<bits/stdc++.h> // insert node at beginning (using tail)
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node*tail;
int cnt;

void createcll(){

    int choice =1;
    tail =0;
    while(choice){
    node *newnode = new node;
    cout<<"enter data " ;
    cin>> newnode->data;
    newnode->next =0;
    if(tail==0){
        tail = newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;  
    }
    cnt++;
    cout<< "you want to insert (0,1) " ;
    cin>> choice;
    }

}

void display(){
    node* temp;
    if(tail==0){
        cout<<"tail is empty " ;
    }
    else{
        temp= tail->next;
        while(temp->next != tail->next){
            cout<< temp->data;
            temp = temp->next;
        }
        cout<< temp->data;
    }
}

void insertatbeg(){

    node*newnode = new node;
    cout<<"enter data" ;
    cin>> newnode->data;
    newnode-> next=0;

    if(tail==0){
        tail = newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insertatend(){

    node*newnode = new node;
    cout<<"enter data" ;
    cin>> newnode->data;
    newnode-> next=0;

    if(tail==0){
        tail = newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertatpos(){
    int i=1;
    int pos;
    cout<<"enter pos" ;
    cin>> pos;
    node*newnode = new node;
    cout<<   "enter data" ;
    cin>> newnode->data;
    newnode->next =0;
    if(pos<0 || pos>cnt){
        cout<<"invalisd position";

    }
    else if(pos==1){
    }
    else{
        node*temp;
        temp = tail->next;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = tail->next;
        tail->next = newnode;

    }
}
int main(){
    createcll();
    display();
    
    cout<<"insert at beginning";
    insertatbeg();
    display();
    cout<<endl;

    cout<<"insert at end";
    insertatend();
    display();
    cout<<endl;

    cout<<"insert at pos";
    insertatpos();
    display();
    cout<<endl;


    


}