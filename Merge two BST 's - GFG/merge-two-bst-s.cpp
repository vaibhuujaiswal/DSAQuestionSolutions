//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/*
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


class Solution
{
    public:
        void BSTIterator(Node* root, stack<Node*> &st) {
            while (root){
                st.push(root);
                root = root->left;
            }
        }
        
        int next(stack<Node*> &st) {
            if (!st.empty()){
                Node* temp = st.top(); st.pop();
                Node* dummy = temp;
                temp = temp->right;
                while (temp){
                    st.push(temp);
                    temp = temp->left;
                }
                return dummy->data;
            }else{
                return -1;
            }
        }
    
    bool hasNext(stack<Node*> &st) {
        if (st.empty()){
            return false;
        }else{
            return true;
        }
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> output;
        if (root1 == NULL && root2 == NULL) return output;
        stack<Node*> st1;
        stack<Node*> st2;
        BSTIterator(root1, st1);
        BSTIterator(root2, st2);
        int n1 = -1;
        int n2 = -1;
        while (hasNext(st1) && hasNext(st2)){
            if (n1 < 0) n1 = next(st1);
            if (n2 < 0) n2 = next(st2);
            if (n1 > n2){
                if (n2 < 0) continue;
                output.push_back(n2);
                n2 = -1;
            }else if (n1 < n2){
                if (n1 < 0) continue;
                output.push_back(n1);
                n1 = -1;
            }else if (n1 == n2){
                if (n1 < 0) continue;
                output.push_back(n1);
                output.push_back(n2);
                n1 = -1;
                n2 = -1;
            }
        }
        
        while (hasNext(st1)){
            if (n1 < 0) n1 = next(st1);
            if (n2 > 0){
                if (n1 < n2){
                    output.push_back(n1);
                    n1 = -1;
                }else if (n1 > n2){
                    output.push_back(n2);
                    n2 = -1;
                }else{
                    output.push_back(n1);
                    output.push_back(n1);
                    n2 = -1;
                    n1 = -1;
                }
                continue;
            }
            output.push_back(n1);
            n1 = -1;
        }
        
        while (hasNext(st2)){
            if (n2 < 0) n2 = next(st2);
            if (n1 > 0){
                if (n2 < n1){
                    output.push_back(n2);
                    n2 = -1;
                }else if (n2 > n1){
                    output.push_back(n1);
                    n1 = -1;
                }else{
                    output.push_back(n1);
                    output.push_back(n1);
                    n2 = -1;
                    n1 = -1;
                }
                continue;
            }
            output.push_back(n2);
            n2 = -1;
        }
        
        if (n1 > 0) output.push_back(n1);
        if (n2 > 0) output.push_back(n2);
        return output;
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
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends