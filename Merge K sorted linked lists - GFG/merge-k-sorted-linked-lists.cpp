//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 
// class Solution {
// public:

//     struct Compare {
//         bool operator()(pair<Node*,int> a, pair<Node*,int> b) {
//             return (a.first->data >= b.first->data);
//         }
//     };

//     // Function to merge K sorted linked list.
//     Node* mergeKLists(Node* arr[], int K) {
        
//         priority_queue<pair<Node*,int>, vector<pair<Node*,int>>, Compare> minheap;
//         vector<Node*> ptr(K);

//         for (int i = 0; i < K; i++) {
//             if (arr[i] == NULL) continue;
//             ptr[i] = arr[i];
//             minheap.push({arr[i], i});
//         }

//         if (minheap.empty()) return NULL;
//         Node* head = NULL;
//         Node* output = NULL;
//         head = minheap.top().first;
//         output = head;
//         int idx = minheap.top().second;
//         ptr[idx] = ptr[idx]->next;
//         if (ptr[idx]) minheap.push({ptr[idx], idx});

//         while (!minheap.empty()) {
            
//             // Node* temp = minheap.top().first;
//             // if (temp == NULL) continue;
//             // idx = minheap.top().second;
//             // if (head == NULL) {
//             //     head = temp;
//             //     output = head;
//             //     continue;
//             // }
//             // minheap.pop();
//             // head->next = temp;
//             // head = head->next;
            
//             // Node* newnext = ptr[idx]->next;
//             // ptr[idx] = newnext;
//             // if (ptr[idx] == NULL) continue;
//             // minheap.push({ptr[idx], idx});
//              Node* temp = minheap.top().first;
//             if (temp == NULL) {
//                 minheap.pop();
//                 continue;
//             }
//             idx = minheap.top().second;
//             minheap.pop();
//             head->next = temp;
//             head = head->next;
        
//             Node* newnext = ptr[idx]->next;
//             ptr[idx] = newnext;
//             // if (ptr[idx] != NULL) minheap.push({ptr[idx], idx});
//         }
        
//         if (head) {
//         head->next = NULL;
//     }
//         return output;
//     }
// };

class Solution {
public:
    struct Compare {
        bool operator()(pair<Node*, int> a, pair<Node*, int> b) {
            return (a.first->data > b.first->data);
        }
    };

    Node* mergeKLists(Node* arr[], int K) {
        priority_queue<pair<Node*, int>, vector<pair<Node*, int>>, Compare> minHeap;
        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Push the heads of all lists into the min-heap
        for (int i = 0; i < K; i++) {
            if (arr[i]) {
                minHeap.push({ arr[i], i });
            }
        }

        // Merge the lists
        while (!minHeap.empty()) {
            pair<Node*, int> curr = minHeap.top();
            minHeap.pop();
            Node* node = curr.first;
            int listIndex = curr.second;

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                minHeap.push({ node->next, listIndex });
            }
        }

        Node* mergedList = dummy->next;
        delete dummy;

        return mergedList;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends