#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at Tail
void insertTail(node* &head, int val){
 
    node* n = new node(val);
    
    if(head==NULL){
        head = n;
        return;
    }
    
    node* temp = head;
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

// Insert at Head
void insertHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Search 
bool search(node* head, int key){
    node* temp = head;
    bool flag = false;
    while(temp!=NULL){
        if(temp->data==key){
            flag = true;
        }
        temp = temp->next;
    }
    return flag;
}

// Delete
void deleteNode(node* &head, int val){
 
    node* temp = head;
    if(head==NULL){
        return;
    }
    
    if(head->next==NULL){
        delete(head);
    }
    
    if (head->data == val){
        head = temp->next;
        delete(temp);
        return;
    }
    
    while(temp->next->data != val && temp->next!=NULL){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = todelete->next;
    delete(todelete);
}

// Reverse a linked List (Iterative)
void reverseList(node* &head){
    node* prev=NULL;
    node* cur=head;
    node* next;
    while(cur!=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return;
}

// Reverse a linked List (Recursive)
node* recursiveList(node* &head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = recursiveList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

// Reverse K nodes 
node* ReverseK(node* &head, int k){
    
    node* prev = NULL;
    node* cur = head;
    node* next;
    
    int count = 0;
    while(cur!=NULL && count<k){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        count ++;
    }
    if(next!=NULL){
        head->next = ReverseK(next,k);
    }
    return prev;
    
}

// Display
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
	cout << "Hello World!" << endl;
    node* head = NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertHead(head,5);
    display(head);
    head = ReverseK(head,2);
	display(head);
	return 0;
}