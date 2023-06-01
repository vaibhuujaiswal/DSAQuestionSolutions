//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    stack<Node*> stleft;
    stack<Node*> stright;
    
    void BSTTraverseLeft(struct Node *root){
        while (root){
            stleft.push(root);
            root = root->left;
        }
    }
    
    void BSTTraverseRight(struct Node *root){
        while (root){
            stright.push(root);
            root = root->right;
        }
    }
    
    int nextLeft(){
        if (!stleft.empty()){
            Node* temp = stleft.top(); stleft.pop();
            int n = temp->data;
            temp = temp->right;
            while (temp){
                stleft.push(temp);
                temp = temp->left;
            }
            return n;
        }else{
            return -1;
        }
    }
    
    int nextRight(){
        if (!stright.empty()){
            Node* temp = stright.top(); stright.pop();
            int n = temp->data;
            temp = temp->left;
            while (temp){
                stright.push(temp);
                temp = temp->right;
            }
            return n;
        }else{
            return -1;
        }
    }
    
    int topLeft(){
        if (!stleft.empty()){
            return stleft.top()->data;
        }else{
            return -1;
        }
    }
    
    int topRight(){
        if (!stright.empty()){
            return stright.top()->data;
        }else{
            return -1;
        }
    }
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        BSTTraverseLeft(root);
        BSTTraverseRight(root);
        while ((!stleft.empty() && !stright.empty()) && (topLeft() < topRight())){
            if ((topLeft() + topRight()) == target) return 1;
            if ((topLeft() + topRight()) > target){
                nextRight();
            }else{
                nextLeft();
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
        //getline(cin, s);
       Solution obj;    
       cout << obj.isPairPresent(root, k) << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

// } Driver Code Ends