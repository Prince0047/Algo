#include<bits/stdc++.h>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node* search(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if( root->data == key){
        return root;
    }
    
    if( root->data > key ) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insertBST(root, 0);
    insertBST(root, 1);
    insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 2);
    insertBST(root, 4);
    inorder(root);
    cout<<endl;

    Node* keyNode = search(root, 7);
    if(keyNode != NULL){
        cout<<"key exist"<<endl;
    }
    else{
        cout<<"key doesn't exist"<<endl;
    }

    return 0;
}