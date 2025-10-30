#include<iostream>
using namespace std;

class node{
public:

int data;
node*next;
};
node*head;
node*temp;
int cnt;

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
    cnt++;
}
}

void display(){
    node*temp;
    temp=head;
    int pos;
    if(cnt%2!=0){
        int pos= (cnt+1)/2;
        for(int i=1;i<pos;i++){
            temp = temp->next;
        }
        cout<<"the middle element is"<< temp->data;
    }
    else{
        int pos = cnt/2;
        for(int i=1;i<pos;i++){
            temp = temp->next;
        }
        cout<<"the middle element is"<< temp->data;
}

}

int main(){
    create();
    display();
}