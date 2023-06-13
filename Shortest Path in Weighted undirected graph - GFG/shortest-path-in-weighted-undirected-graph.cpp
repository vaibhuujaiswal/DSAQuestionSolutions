//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for (int i = 0; i < m; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<pair<int,int>> distance(n+1);
        for (int i = 1; i < n+1 ; i++){
            distance[i] = {1e9,-1};
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        distance[1] = {0,-1};
        q.push({0,1});
        while (!q.empty()){
            auto f = q.top(); q.pop();
            int node = f.second;
            int dist = f.first;
            for (auto traverse : adj[node]){
                int edgeWeight = traverse.second;
                int adjNode = traverse.first;
                if (distance[adjNode].first > edgeWeight + dist){
                    distance[adjNode] = {dist + edgeWeight, node};
                    q.push({distance[adjNode].first, adjNode});
                }
            }
        }
        
        // for (int i = 1; i < n+1; i++){
        //     if (distance[i].first == 1e9) distance[i].first = -1;
        // }
        vector<int> output;
        
        // for (auto i : distance){
        //     cout << i.first << i.second << endl;
        // }
        int i = n;

        while (distance[i].second != -1 and distance[i].second != 1){
            output.push_back(i);
            i = distance[i].second;
        }
        
        if (distance[i].second == -1){
            vector<int> temp;
            temp.push_back(-1);
            return temp;
        }else if (distance[i].second == 1){
            output.push_back(i);
            output.push_back(1);
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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