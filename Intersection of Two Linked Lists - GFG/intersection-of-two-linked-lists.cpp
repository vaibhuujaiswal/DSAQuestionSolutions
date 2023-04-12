//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node *returnList = NULL;
        Node *head = returnList;
        unordered_set<int> us;
        Node *second = head2;
        Node *first = head1;
        if (first == NULL || second == NULL) return NULL;
        while (second != NULL){
            us.insert(second->data);
            second = second->next;
        }
        
        while (first != NULL){
            if (us.find(first->data) != us.end()){
                if (returnList == NULL){
                    returnList = new Node(first->data);
                    head = returnList;
                }else{
                    returnList->next = new Node(first->data);
                    returnList = returnList->next;
                }
            }
            first = first->next;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends