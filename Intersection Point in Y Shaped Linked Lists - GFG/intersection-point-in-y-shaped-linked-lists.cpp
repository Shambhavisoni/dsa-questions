//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* inputList(int size)
{
    if (size == 0) return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}


// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
    int len(Node* h){
        if(h==NULL){
            return 0;
        }
        return 1 + len(h->next);
    }
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
    Node* t1=head1;
    Node* t2=head2;
    
    int l1=len(head1);
    int l2=len(head2);
    
    int diff = abs(l1 - l2);
    
    if(l1>l2){
        while(diff>0){
            t1=t1->next;
            diff--;
        }
        
    }
    else{
        while(diff>0){
            t2=t2->next;
            diff--;
        }
    }
    
    while(t1!=NULL && t2!=NULL && t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    if(t1==NULL || t2==NULL){
        return -1;
    }
    return t1->data;
    }
};



//{ Driver Code Starts.


/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL) temp->next = common;
        
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends