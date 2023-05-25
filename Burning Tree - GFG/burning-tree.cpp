//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

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
class Solution {
    private:
    int loop(Node* targetNode, map<Node*, Node*> map){
        vector<int> output;
        queue<Node*> q;
        q.push(targetNode);
        unordered_map<Node*,bool> visited;
        visited[targetNode] = true;
        int count = 0;
        while (!q.empty()){
            count++;
            int n = q.size();
            for (int i = 0; i < n; i++){
                targetNode = q.front();
                q.pop();
                if (targetNode->left && !visited[targetNode->left]){
                    q.push(targetNode->left);   
                     visited[targetNode->left] = true;
                }
                if (targetNode->right && !visited[targetNode->right]){
                    q.push(targetNode->right);
                    visited[targetNode->right] = true;
                }
                if ((map.find(targetNode) != map.end()) && (!visited[map[targetNode]])){
                    q.push(map[targetNode]);
                    visited[map[targetNode]] = true;
                }
            }
        }
        return count-1;
    }

  public:
    int minTime(Node* root, int target) 
    {
         map<Node*, Node*> map;
        stack<Node*> s;
        s.push(root);
        Node* targetNode;
        while (!s.empty()){ //Using this stored all radial parent nodes of our required function
            Node* value = s.top();
            s.pop();
            if (value -> data == target) targetNode = value; //stores the target Node;
            if (value->right != NULL){
                map[value->right] = value;
                s.push(value->right);
            }
            if (value->left != NULL) {
                map[value->left] = value;
                s.push(value->left);
            }
        }
        
        return loop(targetNode, map);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends