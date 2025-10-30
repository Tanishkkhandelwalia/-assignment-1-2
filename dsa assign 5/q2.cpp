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
void display(){
    temp = head;
    while(temp!=0){
        if(temp->data==1){
            cnt++;
            node*prev;
            prev = temp;
            temp=temp->next;
            free(prev);
        }
        else{
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
    cout<<endl;
    cout<< "count " <<cnt;
}

int main(){
    create();
    display();

}