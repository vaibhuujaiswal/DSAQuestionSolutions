//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(struct Node* head) {
    if (head == NULL) cout << -1;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
// User function Template for C++


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// class Solution {
//     public:
//         Node* deletev(struct Node** curr){
//             Node* key = *curr;
//             if (key->prev == NULL){
//                 if (key->next == NULL){
//                     return nullptr;
//                 }else{
//                     Node* value = *curr;
//                     key = key->next;
//                     value->next = NULL;
//                     free(value);
//                     return key;
//                 }
//             }else{
//                 if (key->next == NULL){
//                     key = key->prev;
//                     key->next = NULL;
//                 }else{
//                     Node *last = key->prev;
//                     Node *forward = key->next;
//                     last->next = forward;
//                     forward->prev = last;
//                     return forward;
//                 }
//             }
//         }
//     public:
//         void deleteAllOccurOfX(struct Node** head_ref, int x) {
//             Node *iterator = *head_ref;
//             while (iterator != NULL){
//                 // cout << iterator->data << endl;
//                 if (iterator->data == x){
//                     iterator = deletev(&iterator);
//                     continue;
//                 }
//                 iterator = iterator->next;
//             }
//             iterator = *head_ref;
//             while (iterator != NULL){
//                 cout << iterator->data << endl;
//                 iterator = iterator->next;
//             }
//         }
// };
class Solution {
public:
    Node* deletev(Node* curr, Node** head_ref){
        if (curr->prev == NULL) {
            if (curr->next == NULL){
                *head_ref = NULL;
                return NULL;
            } else {
                Node* next_node = curr->next;
                *head_ref = (*head_ref)->next;
                next_node->prev = NULL;
                free(curr);
                return next_node;
            }
        } else {
            if (curr->next == NULL){
                curr->prev->next = NULL;
                free(curr);
                return NULL;
            } else {
                Node *prev_node = curr->prev;
                Node *next_node = curr->next;
                prev_node->next = next_node;
                next_node->prev = prev_node;
                free(curr);
                return next_node;
            }
        }
    }

    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node *iterator = *head_ref;
        while (iterator != NULL){
            if (iterator->data == x){
                iterator = deletev(iterator, head_ref);
            } else {
                iterator = iterator->next;
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        Node* head = new Node();
        head = NULL;

        int n;
        cin >> n;

        vector<int> inp(n);

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            // push(&head,val);
            inp[i] = val;
        }
        for (int i = n - 1; i >= 0; i--) {
            push(&head, inp[i]);
        }
        int key;
        cin >> key;
        // printList(head);
        // cout << endl;

        Solution obj;

        obj.deleteAllOccurOfX(&head, key);
        printList(head);
        cout << endl;

        // cout << "\n~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends