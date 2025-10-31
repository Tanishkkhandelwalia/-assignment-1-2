#include<bits/stdc++.h> // implementation of doubly linked list 
using namespace std;

class node{
    public:

    int data;
    node * prev;
    node* next;
};
node*head = 0;

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
   
}

void display(){

    node * temp ;
    temp = head;
    while(temp!=0){

        cout<< temp->data << " " ;
        temp  = temp->next;
    }
    
}

void searchnode() {
    if (head == 0) {
        cout << "list is empty";
        return;
    }

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    node* temp = head;
    int pos = 1;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << " Node with value " << value << " found at position " << pos << " from head.\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        cout << " Node with value " << value << " not found.\n";
}

int main(){
    create();
    display();
    cout<<"you want to search the node";int tell;
    cin>>tell;
    if(tell){
        searchnode();
    }

    return 0;
}
