#include<bits/stdc++.h>  // deletion of a node from position from circular linkd list
using namespace std;

class node{
    public:
    int data;
    node* next;   
};
node* head;
node*tail;
int cnt =0;
void  createcll(){
    head =0;
    int choice =1;
     node*temp;
    while(choice){
    node*newnode = new node;
    cout<< "enter data " ;
    cin>> newnode->data;
    newnode->next =0;

   
    if(head==0){
        head = temp = newnode; 
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    cnt++;
    temp->next = head;
    cout<<"you want to insert hte node (0,1) " ;
    cin>> choice;
}
tail= temp;

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

void deleteatpos(){
    int pos ;
    int i=1;
    node*current;
    node*nextnode;
    cout<<"enter position";
    cin>> pos;
    if(pos<1||pos>cnt){
        cout<<"invalid position";
    }
    else if(pos==1){
        //deletefrombeg()
    }
    else{
        while(i<pos-1){
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next= nextnode->next;
        free(nextnode);
    }
}

int main(){
    createcll();
     int want;
    cout<<" did you want to delete at beg " ;
    cin>> want;
    deleteatpos();
    display();

}
