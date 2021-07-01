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

void insertHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void makeCycle(node* &head, int pos){
    int count = 1;
    node* temp = head;
    node* posptr;
    while(temp->next!=NULL){
        if(count==pos){
            posptr = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = posptr;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    node* cyclePtr = NULL;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast){
            cyclePtr = slow;
            break;
        }
    }
    if(cyclePtr){
        fast = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = NULL;
    }
    else{
        cout<<"No cycle present"<<endl;
    }
}

int length(node *head){
    int l = 0;
    node* temp = head;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}

node* kappend(node* &head, int k){

    node* newhead;
    node* tail = head;
    node* newTail;
    int count = 1;
    int l = length(head);
    k = k%l;
    cout<<l<<"size"<<endl;
    
    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newhead = tail;
        }
        tail = tail->next;
        count ++;
    }
    newTail->next = NULL;
    
    tail->next = head;
    
    return newhead;
    
    
}

void intersect(node*head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while(pos){
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int intersecPos(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d=0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

node* mergesort(node* &head1, node* &head2){
    
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;
    
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next= p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    if(p1==NULL){
        p3->next = p2;
    }
    else{
        p3->next = p1;
    }
    return dummyNode->next;
}

node* mergeRecursive(node* &head1, node* &head2){
    
    node* result;
    if (head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next,head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}


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
    insertTail(head,5);
    insertTail(head,6);
    // makeCycle(head,3);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);
    // node* newhead = kappend(head,3);
    // display(newhead);
    node* head2 = NULL;
    insertTail(head2,7);
    insertTail(head2,8);
    // intersect(head,head2,3);
    // cout<<intersecPos(head,head2)<<endl;

    display(head);
    display(head2);
    // node* sorthead = mergesort(head,head2);
    // display(sorthead);

    node* result = mergeRecursive(head, head2);
    display(result);
    
    


    return 0;
}