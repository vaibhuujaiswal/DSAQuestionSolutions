//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> visited(V,0);
	    
	    for (int i = 0; i < V; i++){
	        if (!visited[i]) {
	            visited[i] = 1;
	            if (!dfs(i, -1, visited,adj)) return false;
	        }
	    }
	    return true;
	}
	
	bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]){
        if (parent == -1){
            
        }else if (visited[parent] == 1){
            visited[node] = 2;
        }else if (visited[parent] == 2){
            visited[node] = 1;
        }
        
        for (auto i : adj[node]){
            if (!visited[i]){
                if (!dfs(i,node,visited,adj)) return false;
            }else{
                if (visited[i] == visited[node]) return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends