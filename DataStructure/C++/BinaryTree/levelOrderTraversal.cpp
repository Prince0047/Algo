#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

};

// Level order Traversal
void printLevelOrder(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    // q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }

        }
    }
}

// Sum of Nodes at Kth Level
int sumAtK(Node* root, int k){
    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        /* code */
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            if(level == k){
                sum += node->data;
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }

        }

        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
    
}

// Right View of Tree
void rightView(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();

            if (i == n-1){
                cout<<curr->data<<" ";
            }
            
            if (curr->left != NULL){
                q.push(curr->left);
            }
            
            if (curr->right != NULL){
                q.push(curr->right);
            }

        }

    }
}

void leftView(Node* root) {

    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();

            if (i == 0){
                cout<<curr->data<<" ";
            }
            
            if (curr->left != NULL){
                q.push(curr->left);
            }
            
            if (curr->right != NULL){
                q.push(curr->right);
            }

        }

    }
}

// Least Common Ancestor
Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL){
        return root;
    }

    if( left != NULL && right != NULL){
        return NULL;
    }

    if (left != NULL){
        return LCA(root->left, n1, n2);
    }

    return LCA(root->right, n1, n2);
}

int findDist(Node* root, int k, int dist){
    if(root == NULL){
        return -1;
    }

    if(root->data == k){
        return dist;
    }

    int left = findDist(root->left, k, dist+1);
    if(left != -1){
        return left;
    }

    return findDist(root->right, k, dist+1);

}

// Distance between two Nodes
int distBtwNodes(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca,n2, 0);

    return d1+d2;
}

// Zig-Zag Traversal
void Zig_Zag(Node *root){
    if(root == NULL){
        return;
    }

    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
            nextLevel.push(temp->left);
            nextLevel.push(temp->right);
            }
            else{
                nextLevel.push(temp->right);
                nextLevel.push(temp->left);
            }
        }

        if(currLevel.empty()) {
            
            swap(currLevel, nextLevel);
            leftToRight = !leftToRight;
        }

    }
    

}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Level Order Traversal
    printLevelOrder(root);
    cout<<endl;

    // Sum of the nodes at kth Level
    cout<<sumAtK(root,2)<<endl;

    // Right View
    rightView(root);
    cout<<endl;

    leftView(root);
    cout<<endl;

    // Dist btw 2 Nodes
    cout<<distBtwNodes(root, 2,7)<<endl;

    // Zig-Zag Traversal
    Zig_Zag(root);
    cout<<endl;

    return 0;
}