#include<bits/stdc++.h>
using namespace std;

class node{
    

    public:
    int data;
    node * next ;
};
node*head;

void searchnode() {
    if (head == 0) {
        cout << "list is empty";
        return;
    }

    int value;
    cout << "enter value to search ";
    cin >> value;

    node* temp = head;
    int position = 1;
    bool flag = false;

    while (temp != 0) {
        if (temp->data == value) {
            cout << " node with value " << value << " found at position " << position << " from head.\n";
            flag = true;
            break;
        }
        temp = temp->next;
        position++;
    }

    if (!flag) {
        cout << " Node with value " << value << " not found in the list.\n";
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

cout<<" you want to search a node ?(0,1) " ;
bool tell ;
cin>> tell ;
if(tell){
  searchnode();
  display();
}

}
