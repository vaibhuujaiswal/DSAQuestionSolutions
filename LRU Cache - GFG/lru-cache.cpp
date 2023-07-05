//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node{
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
    Node(int k, int v){
        this->key = k;
        this->value = v;
        this->next = NULL;
        this->prev = NULL;
    }
};


class LRUCache
{
    private:
    Node* addDLL(int key, int value){//will be added in front of list;
        Node *newv = new Node(key,value);
        newv->next = head->next;
        head->next->prev = newv;
        head->next = newv;
        newv->prev = head;
        return newv;
    }
    
    void deleteDLL(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = NULL;
        node->next = NULL;
        free(node);
        return;
    }

    public:
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);
        unordered_map<int,Node*> map;
        int upperbound;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        head->next = tail;
        tail->prev = head;
        upperbound = cap;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if (map.find(key) != map.end()){
            Node* node = map[key];
            int value = node->value;
            deleteDLL(node);
            Node* newnode = addDLL(key,value);
            map[key] = newnode; //updated keyvalue
            return value;
        }
        else return -1;
        
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (map.find(key) != map.end()){
            Node* node = map[key];
            deleteDLL(node);
            
        }else if (map.size() == upperbound){ //remove LRU cache i.e. the one prev to tail
                map.erase(tail->prev->key);
                deleteDLL(tail->prev);
        }
        
        Node* newnode = addDLL(key,value);
        map[key] = newnode;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends