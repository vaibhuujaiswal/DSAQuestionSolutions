//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        if (head == NULL){
            Node *value = new Node(1);
            return value;
        }
        int result = adder(head);
        if (result == 1){
            Node *newv = new Node(1);
            newv->next = head;
            return newv;
        }
        return head;
    }
    
    public:
    int adder(Node *head){
        if (head == NULL){
            return 0;
        }
        if (head->next == NULL){
            int nodalValue = head->data;
            if (nodalValue == 9){
                head->data = 0;
                return 1;
            }else{
                head->data = head->data + 1;
                return 0;
            }
        }
        int v = adder(head->next);
        if (v == 0) return 0;
        if (v == 1){
            int nodalValue = head->data;
            if (nodalValue == 9){
                head->data = 0;
                return 1;
            }else{
                head->data = head->data + 1;
                return 0;
            }
    }
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends