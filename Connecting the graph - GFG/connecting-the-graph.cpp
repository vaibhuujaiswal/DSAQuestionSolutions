//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            size.resize(n,1);
            parent.resize(n);
            for (int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if (node == parent[node]){
                return node;
            }else{
                return parent[node] = findParent(parent[node]);
            }
        }
        
        void findUnionBySize(int node1, int node2){
            int u = findParent(node1);
            int v = findParent(node2);
            if (u == v) return;
            if (size[u] > size[v]){
                size[u] += size[v];
                parent[v] = u;
            }else{
                size[v] += size[u];
                parent[u] = v;
            }
        }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int countExtraEdge = 0;
        for (auto it : edge){
            int u = it[0];
            int v = it[1];
            if (ds.findParent(u) == ds.findParent(v)){
                countExtraEdge++;
            }else{
                ds.findUnionBySize(u,v);
            }
        }
        
        int numberOfComponents = 0;
        for (int i = 0; i < n; i++){
            if (ds.parent[i] == i){
                numberOfComponents++;
            }
        }
        int ans = numberOfComponents - 1;
        if (countExtraEdge >= ans){
            return ans;
        }else{
            return -1;
        }
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends