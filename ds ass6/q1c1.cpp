#include<bits/stdc++.h>  // implementation of a circular linked list
using namespace std;

class node{
    public:
    int data;
    node* next;   
};
node* head;
void  createcll(){
    head =0;
    int choice =1;
    while(choice){
    node*newnode = new node;
    cout<< "enter data " ;
    cin>> newnode->data;
    newnode->next =0;

    node*temp;
    if(head==0){
        head = temp = newnode; 
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;

    cout<<"you want to insert hte node (0,1) " ;
    cin>> choice;
}

}

void display(){
    if(head==0){
        cout<<"list is empty " ;
    }
    else{
        node*temp ;
        temp = head;
        while(temp->next!=head){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<  temp->data;
    }
}
void searchnode() {
    if (head == 0) {
        cout << "list is empty";
        return;
    }

    int value;
    cout << "enter value to search ";
    cin >> value;

    node* temp = head;
    int pos = 1;
    bool found = false;

    do {
        if (temp->data == value) {
            cout << " Node with value " << value << " found at position " << pos << " from head.\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        cout << " Node with value " << value << " not found.\n";
}


int main(){
    createcll();
    display();
    cout<<"you want to search the node";
    int tell;
    cin>>tell;
    if(tell){
        searchnode();
    }


}