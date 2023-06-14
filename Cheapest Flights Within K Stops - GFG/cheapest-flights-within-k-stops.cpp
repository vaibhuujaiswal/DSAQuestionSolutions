//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int,int>> adj[n];
        for (int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> distance(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while (!q.empty()){
            auto it = q.front(); q.pop();
            int step = it.first;
            int node = it.second.first;
            int price = it.second.second;
            if (node == dst) continue;
            if (step >= k+1) continue;
            for (auto i : adj[node]){
                int v = i.first;
                int cost = i.second;
                if (distance[v] > price + cost){
                    distance[v] = price + cost;
                    q.push({step+1,{v,distance[v]}});
                }
            }
        }
        if (distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends