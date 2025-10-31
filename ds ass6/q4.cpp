#include<bits/stdc++.h> // implementation of doubly linked list 
using namespace std;

class node{
    public:

    string data;
    node * prev;
    node* next;
};
node*head ;
node*tail;

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
    tail = temp;
   
}

void display(){

    node * temp ;
    temp = head;
    while(temp!=0){

        cout<< temp->data << " " ;
        temp  = temp->next;
    }
    cout<<endl;
}
void check(){

    node* start = head;
    node* end = tail;
    bool flag = true;

    while (start != nullptr && end != nullptr && start != end && end->next != start) {
        if (start->data != end->data) {
            flag = false;
            break;
        }
        start = start->next;
        end = end->prev;
    }

    if (flag)
        cout << " The linked list is a palindrome." << endl;
    else
        cout << " The linked list is not a palindrome." << endl;
}



int main(){
    create();
    cout<<"doubly linked list is ";
    display();
    check();
    return 0;
}
