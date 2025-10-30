#include<iostream>
using namespace std;

class node{
public:

int data;
node*next;
};
node*head;
node*temp;

void create(){
    int choice=1;
    head=0;
while(choice){
    node*newnode = new node;
    cout<<"enter data";
    cin>> newnode->data;
    newnode->next =0;
    if(head==0){
       temp= head = newnode;
    }
    else{
        temp->next = newnode;
        temp=temp->next;
    }
    cout<<"want to enter a node;";
    cin>> choice;
}
}
int cnt;
void reverse(){
    node*prev;
    node*current;
    node*nextnode;
    prev=0;
    nextnode=current  = head;  
    while(nextnode!=0){
        nextnode=nextnode->next;
        current->next =prev;
        prev=current;
        current= nextnode;
    }
    head=prev;
    
}
void display(){
    temp=head;
    while(temp!=0){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    create();
    cout<<"without reverse";
    display();
    reverse();
    cout<<"with reverse";
    display();
}

