//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int N,int M,int src)
      {
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
            distance[i] = INT_MIN;
        }
        
        distance[src] = 0; //src node
        while (!st.empty()){
            int node = st.top(); st.pop();
            //read all adjacent nodes
            for (auto i : adj[node]){
                int vertice = i.first; 
                int weight = i.second;
                if (distance[vertice] < distance[node] + weight){
                    if (distance[node] == (INT_MIN)) continue;
                    distance[vertice] = distance[node] + weight;
                }
            }
        }

        return distance;
    }
    
    
    
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
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends