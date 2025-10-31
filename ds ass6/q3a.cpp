#include<bits/stdc++.h> // implementation of doubly linked list 
using namespace std;

class node{
    public:

    int data;
    node * prev;
    node* next;
};
node*head ;

void create(){
int choice =1;
head=0;
node * temp = 0 ;

    while(choice){

         node *newnode = new node;
         newnode->prev =0;
         newnode->next =0;

         cout<< "enter data " ;
         cin>> newnode->data;

         if(head ==0){
            head = newnode;
            temp = newnode;
         }
         else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode; ;
         }

         cout<< " do you want to continue ? (0,1) " << "choice " ;
         cin>> choice;

    }
   
}

void display(){

    node * temp ;
    temp = head;
    while(temp!=0){

        cout<< temp->data << " " ;
        temp  = temp->next;
    }
    
}

int size(){

    int count=0;
    node*temp;
    temp = head;
    while(temp!=0){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    create();
    cout<<"doubly linked list is ";
    display();
    cout<<"the size of doubly linked list is"<< size();

    return 0;
}
