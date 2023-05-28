//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* buildTree(int in[], int instart, int inend, int post[], int poststart, int postend, 
                map<int,vector<int>>& map, int n);

Node* buildTree(int in[], int instart, int inend, int post[], int poststart, int postend, 
                map<int,vector<int>>& map, int n)
{
    if (instart > inend || poststart > postend)
        return NULL;
    
    int rootData = post[postend];
    Node* root = new Node(rootData);

    vector<int>& indices = map[rootData];
    int inRoot = -1;

    for (int index : indices)
    {
        if (index >= instart && index <= inend)
        {
            inRoot = index;
            break;
        }
    }

    int numsRight = inend - inRoot;

    root->left = buildTree(in, instart, inRoot - 1, post, poststart, postend - numsRight - 1, map, n);
    root->right = buildTree(in, inRoot + 1, inend, post, postend - numsRight, postend - 1, map, n);

    return root;
}

Node* buildTree(int in[], int post[], int n)
{
    map<int,vector<int>> map; // save elements of inorder in map
    for (int i = 0; i < n; i++){
        map[in[i]].push_back(i);
    }

    int instart = 0;
    int inend = n - 1;
    int poststart = 0;
    int postend = n - 1;

    return buildTree(in, instart, inend, post, poststart, postend, map, n);
}
