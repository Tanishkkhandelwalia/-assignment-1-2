#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node*left ,*right;
};

node* create(){

    int x;
    node* newnode;
    newnode = new node;

    cout<<"enter data (-1 for no node) " ;
    cin>> x;

    if(x==-1){
        return 0;
    }
    newnode->data = x;

    cout<<" enter left child of "<< x;
    newnode->left = create();

    cout<<"enter right child of " <<x;
    newnode->right = create();

    return newnode;
}

void preorder(node*root){

    if(root ==0){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node*root){

    if(root==0){
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void postorder(node* root){

    if(root==0){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data <<" ";
}


int main(){
    node* root;
    root = create();

    cout<<"preorder is ";
    preorder(root);

    cout<<"inorder is ";
    inorder(root);

    cout<<"postorde is ";
    postorder(root);
}