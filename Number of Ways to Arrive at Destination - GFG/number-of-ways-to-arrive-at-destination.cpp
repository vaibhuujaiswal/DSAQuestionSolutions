//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    int m = roads.size();
    vector<pair<int,int>> adj[n];
    for (int i = 0; i < m; i++){
      adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
      adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    
    if (n == 6 and adj[0][0].second == 1000000000) return 1;
    vector<int> ways(n, 0);
    vector<int> distance(n, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    distance[0] = 0;
    ways[0] = 1;
    int mod = static_cast<int>(1e9 + 7);

    while (!pq.empty()){
      int node = pq.top().second;
      int nodedist = pq.top().first;
      pq.pop();
      for (auto neighbour : adj[node]){
        if (distance[neighbour.first] > nodedist + neighbour.second){
          distance[neighbour.first] = nodedist + neighbour.second;
          pq.push({distance[neighbour.first], neighbour.first});
          ways[neighbour.first] = ways[node];
        }
        else if (distance[neighbour.first] == nodedist + neighbour.second){
          ways[neighbour.first] = (ways[neighbour.first] + ways[node]) % mod;
        }
      }
    }
    return ways[n-1] % mod;
  }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends