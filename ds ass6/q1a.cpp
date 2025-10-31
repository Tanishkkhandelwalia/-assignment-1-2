#include<bits/stdc++.h> // inserting node at end in doubly linked list 
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

void insertatend(){

    node *newnode = new node;
    cout<< " enter data ";
    cin>> newnode->data;
    newnode->prev =0;
    newnode->next =0;   

    if(head==0){
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail  =  newnode;
    }
}
void insertatbeginning(){

    node *newnode = new node;
    cout<< " enter data ";
    cin>> newnode->data;
    newnode->prev =0;
    newnode->next =0;   

    if(head==0){
        head = tail = newnode;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertafterspecificpos(int pos){
    if(pos<0 ){
      cout<< "invalid position " ;
    }
    else{
        int i=1;
        node* temp ;
        temp = head;  
        while(i<pos){
            temp= temp->next;
            i++;
        }
        node *newnode= new node;
        cout<<"enter data " ;
        cin>> newnode->data;
        newnode->prev= temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev= newnode;

    }
}

int main(){
    create();
    display();
    int want ;
    cout<< "you want to insert at end " << "want ";
    cin>> want;
    if(want ==0){
        cout<< "do you want to insert " ;
    }
    else{
        cout<<"insert at end";
        insertatend();
        display();
        cout<<endl;
        cout<<"insert at beginning";
        insertatbeginning();
        display();
        cout<<endl;
        cout<<"inserta t specific pos";
        int pos;
        cout<<"enter position ";
        cin>>pos;
        insertafterspecificpos(pos);
        display();
    }

    return 0;
}
