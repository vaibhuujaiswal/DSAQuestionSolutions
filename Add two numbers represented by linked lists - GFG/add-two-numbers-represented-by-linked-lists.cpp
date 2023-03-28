//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if (first == NULL && second == NULL) return NULL;
        if (first == NULL) return second;
        if (second == NULL) return first;
        Node *prev1 = NULL;
        Node *curr1 = first;
        while (curr1 != NULL){
            Node *next = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = next;
        }
        first = prev1;
        
        Node *prev2 = NULL;
        Node *curr2 = second;
        while (curr2 != NULL){
            Node *next = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = next;
        }
        second = prev2;

        Node *resultant = NULL;
        int carry = 0;
        Node *head;
        while (first != NULL && second != NULL){
            int data = first->data + second->data + carry;
            carry = data / 10;
            if (carry == 1){
                data = data % 10;
            }
            if (resultant == NULL){
                resultant = new Node(data);
                head = resultant;
            }else{
                Node *temp = new Node(data);
                resultant->next = temp;
                resultant = temp;
            }
            first = first->next;
            second = second->next;
        }
        
        while (first != NULL){
            int data = first->data + carry;
            carry = data / 10;
            if (carry == 1){
                data = data % 10;
            }
            Node *temp = new Node(data);
            resultant->next = temp;
            resultant = temp;
            first = first->next;
        }
        
        while (second != NULL){
            int data = second->data + carry;
            carry = data / 10;
            if (carry == 1){
                data = data % 10;
            }
            Node *temp = new Node(data);
            resultant->next = temp;
            resultant = temp;
            second = second->next;
        }
        
        if (carry == 1){
            Node *temp = new Node(carry);
            resultant->next = temp;
            resultant = temp;
        }
        
        
        
        Node *prev3 = NULL;
        Node *curr3 = head;
        while (curr3 != NULL){
            Node *next = curr3->next;
            curr3->next = prev3;
            prev3 = curr3;
            curr3 = next;
        }
        return prev3;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends