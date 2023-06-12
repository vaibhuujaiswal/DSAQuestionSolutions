//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N]; //edges converted to adjacency list
        for (int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        //step 1-> perform topoSort (we will do this using dfs)
        int visited[N] = {0};
        stack<int> st; //will be used in step 2;
        for (int i = 0; i < N; i++){
            if (!visited[i]){
                topoSort(i, visited, adj, st);
            }
        }
        
        //step 2 -> finding distance
        // vector<int> distance(N,INT_MAX); //initalisze distance array with infinity;
        
        vector < int > distance(N);
        for (int i = 0; i < N; i++) {
            distance[i] = 1e9;
        }
        distance[0] = 0; //src node
        
        while (!st.empty()){
            int node = st.top(); st.pop();
            //read all adjacent nodes
            for (auto i : adj[node]){
                int vertice = i.first; 
                int weight = i.second;
                if (distance[node] + weight < distance[vertice]){
                    distance[vertice] = distance[node] + weight;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
        if (distance[i] == 1e9) distance[i] = -1;
      }
        return distance;
    }
    
    
    
    /* 0 - {1,2} 1 - {4,8}{3,6} 2 - {1,2}{4,2} 3 - {} 4 - {}
    
    
    st = 4 3 1 0 2 
    
    dist : 0 inf inf inf inf;
    index : 0   1.  2.  3.  4;
    
    */
    
    
    void topoSort(int node, int visited[], vector<pair<int,int>> adj[], stack<int> &st){
        visited[node] = 1;
        for (auto i : adj[node]){
            if (!visited[i.first]){
                topoSort(i.first, visited, adj, st);
            }
        }
        st.push(node);
    }

    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends