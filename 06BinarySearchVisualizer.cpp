#include <iostream>
using namespace std;


struct Node {

    int data;
    Node* left;
    Node* right;

};


Node* createNode(int value){

    Node* node = new Node();

    node->data = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}



Node* insert(Node* root,int value){

    if(root == nullptr)
        return createNode(value);


    if(value < root->data)
        root->left = insert(root->left,value);

    else
        root->right = insert(root->right,value);


    return root;
}



void display(Node* root,int space){

    if(root == nullptr)
        return;


    space += 5;


    display(root->right,space);


    cout<<endl;

    for(int i=5;i<space;i++)
        cout<<" ";

    cout<<root->data<<"\n";


    display(root->left,space);

}



int main(){

    Node* root=nullptr;


    int values[]={
        50,30,70,20,40,60,80
    };


    for(int i:values)
        root=insert(root,i);



    cout<<"Binary Search Tree\n";

    display(root,0);


    return 0;
}
