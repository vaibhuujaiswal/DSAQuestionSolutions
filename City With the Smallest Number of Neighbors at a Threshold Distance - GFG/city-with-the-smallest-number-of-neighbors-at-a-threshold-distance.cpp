//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e9));
        for (int i = 0; i < m; i++){
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for (int i = 0; i < n; i++) adj[i][i] = 0;

        
        for (int via = 0; via < n; via++){
            for (int u = 0; u < n; u++){
                for (int v = 0; v < n; v++){
                    if (via == 1e9 || via == 1e9) continue;
                    adj[u][v] = min(adj[u][v], adj[u][via] + adj[via][v]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) adj[i][i] = 1e9;

        // for (auto i : adj){
        //     for (auto j : i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        
        pair<int,int> minCount = {-1,INT_MAX};
        int i = 0;
        for (auto outer : adj){
            int count = 0;
            for (auto inner : outer){
                if (inner <= distanceThreshold) count++;
            }
            if (minCount.second >= count){
                minCount.first = i;
                minCount.second = count;
            }
            i++;
        }
        // cout << minCount.second;
        return minCount.first;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends