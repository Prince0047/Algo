#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node 
{
    public:
    
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// Traversal
void preorder(Node* root){
    
    if(root==NULL){
        return ;
    }
   cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// Post-order Traversal
void postorder(Node* root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// Count of Nodes
int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Sum of Nodes
int sumOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

// Height of the Tree
int calHeight(Node* root){
    if (root==NULL){
        return 0;
    }

    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Diametre of the Tree    O(n^2)
int calDiameter(Node* root){
    if (root==NULL){
        return 0;
    }

    int leftHeight = calHeight(root->left);
    int rightHeight = calHeight(root->right);

    int curDiameter = 1 + leftHeight + rightHeight;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(1 + leftHeight + rightHeight, max(lDiameter, rDiameter));

}

// Optimal Diameter Function    O(n)
int calDiameter2(Node* root, int* height){
    if (root==NULL){
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calDiameter2(root->left, &lh);
    int rDiameter = calDiameter2(root->right, &rh);

    int curDiameter = 1 + lh + rh;

    *height = 1 + max(lh, rh);

    return max(curDiameter, max(lDiameter, rDiameter));

}

int main()
{

    // Tree Traversal
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    // Count Nodes
    cout<<countNodes(root)<<endl;

    // Sum of Node
    cout<<sumOfNodes(root)<<endl;

    // Height of the Tree
    cout<<calHeight(root)<<endl;

    // Diameter of the Tree
    cout<<calDiameter(root)<<endl;

    // Diameter of the Tree (Optimised)
    int height = 0;
    cout<<calDiameter2(root, &height)<<endl;

	return 0;
}