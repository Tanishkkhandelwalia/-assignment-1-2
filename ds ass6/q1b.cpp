#include<bits/stdc++.h> // deleting node from specific position double linked list  
using namespace std;

class node{
    public:

    int data;
    node * prev;
    node* next;
};
node*head = 0;
node*tail;

void create(){
int choice =1;
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
    tail = temp;
   
}

void display(){

    node * temp ;
    temp = head;
    while(temp!=0){

        cout<< temp->data << " " ;
        temp  = temp->next;
    }
    
}

void   deletefrompos(int pos){

    if(pos<0){
        cout<< "invalis position " ;
    }
    else{
        int i=1;
        node*temp;
        temp = head;
          while(i<pos){
            temp = temp->next;
            i++;
          }
          tail->prev = temp->prev;
          temp->prev->next = tail;
          free(temp);
    }
}

int main(){
    create();
    int want ;
    cout<< "you want to delete a node at end  " << "want ";
    cin>> want;
    if(want ==0){
        cout<< "do not want to insert " ;
    }
    else{
        int pos;
        cout<<"enter position";
        cin>>pos;
        deletefrompos(pos);
    }

    display();
    return 0;
}
