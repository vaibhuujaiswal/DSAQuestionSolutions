//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);
            for (int i = 0; i < n ; i++){
                parent[i] = i;
                size[i] = 1;
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
            int pu = findParent(node1);
            int pv = findParent(node2);
            if (pu == pv) return;
            if (size[pu] < size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                parent[pv] = pu;
                size[pu] += size[pv];
            }
       }
};


class disjointSet {
    vector<int> rank, parent, size;
public:
    disjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }


    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        disjointSet ds(maxRow + maxCol + 1); //1 just for precautions
        unordered_map<int,int> umap;
        for (auto it : stones){
            int r = it[0];
            int c = maxRow + 1 + it[1];
            umap[r] = 1;
            umap[c] = 1;
            ds.unionBySize(r,c);
        }
        
        int cnt = 0;
        for (auto it : umap) { //count only those nodes that are actual coordinates
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        
        return n - cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends