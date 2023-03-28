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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        if (head == NULL) {
            return head;
        }
        Node *lastNode = head;
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        Node *check = lastNode;
        Node *curr = head;
        Node *prev = NULL;
        Node *evenhead = head;
        bool flag = false;
        while (curr != NULL && curr->next != check->next){
            int data = curr->data;
            if (data % 2 != 0){
                Node *temporary = curr->next;
                if (prev == NULL){
                    lastNode->next = curr;
                    curr->next = NULL;
                    prev = NULL;
                }else{
                    lastNode->next = curr;
                    prev->next = curr->next;
                    curr->next = NULL;
                }
                lastNode = lastNode->next;
                curr = temporary;
                continue;
            }
            else{
                if (!flag){
                    evenhead = curr;
                    flag = true;
                }
                prev = curr;
                curr = curr->next;
                continue;
            }
            curr = curr->next;
        }
        if (check->data % 2 != 0){
            if (!flag){
                lastNode->next = check;
                check->next = NULL;
                return head;
            }
            lastNode->next = curr;
            prev->next = curr->next;
            curr->next = NULL;
        }else if (!flag){
            evenhead = check;
        }
        return evenhead;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends