#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int search(int* inorder, int start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int* preorder, int* inorder, int start, int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    int pos = search(inorder, start, end, curr);
    if(start==end){
        return node;
    }

    node->left = buildTree(preorder, inorder, start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, end);

    return node;
}

void preorderPrint(struct Node* root){
    
    if(root==NULL){
        return ;
    }
   cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main()
{
    // Building Tree using traversal
    int preorder[] = {1,2,3,4,5,6,7};
    int inorder[] = {4,2,5,1,6,3,7};

    // Build Tree
    struct Node* root = buildTree(preorder, inorder, 0, 6);
    preorderPrint(root);

	return 0;
}