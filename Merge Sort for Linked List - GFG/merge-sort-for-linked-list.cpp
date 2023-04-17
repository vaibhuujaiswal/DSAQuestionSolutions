//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if (head == NULL) return head;
        Node* slow = head;
        Node* fast = head;
        Node *temp = NULL;
        if (head->next == NULL){
             if (head == NULL || head->next == NULL) {
                return head;
            }
            long long int temp1 = head->data;
            long long int temp2 = head->next->data;
            if (temp2 < temp1){
                temp = head->next;
                temp->next = head;
                head->next = NULL;
                return temp;
            }else{
                return head;
            }
        }
        if (head == NULL || head->next == NULL){
            return head;
        }

        while (fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (temp == NULL) return head;
        temp->next = NULL;
        Node *first = mergeSort(head);
        Node *second = mergeSort(slow);
        return merged(first,second);
    }
    
   Node* merged(Node *head, Node *slow) {
    Node *start = NULL;
    Node *ptr = NULL;

    if (head == NULL) return slow;
    if (slow == NULL) return head;

    if (head->data <= slow->data) {
        start = head;
        ptr = head;
        head = head->next;
    } else {
        start = slow;
        ptr = slow;
        slow = slow->next;
    }

    while (head != NULL && slow != NULL) {
        if (head->data <= slow->data) {
            ptr->next = head;
            ptr = head;
            head = head->next;
        } else {
            ptr->next = slow;
            ptr = slow;
            slow = slow->next;
        }
    }

    if (head == NULL) ptr->next = slow;
    if (slow == NULL) ptr->next = head;

    return start;
}
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends