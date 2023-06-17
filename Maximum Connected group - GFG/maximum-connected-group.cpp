//{ Driver Code Starts
// Initial Template for C++

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
        
        int findSize(int node){
            int pu = findParent(node);
            return size[pu];
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
    bool isValid(int newr, int newc, int n) {
            return newr >= 0 && newr < n && newc >= 0 && newc < n;
    
        
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> visited(n*n,0);
        DisjointSet ds(n*n);
        
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.findUnionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        
        int outputSize = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] == 1) continue;
                int num = (r * n) + c;
                if (grid[r][c] == 0){
                    int tempSize = 0;
                    int row[4] = {-1,1,0,0};
                    int col[4] = {0,0,1,-1};
                    set<int> s;
                    for (int i = 0; i < 4; i++){
                        int rnew = r + row[i];
                        int cnew = c + col[i];
                        int numnew = (rnew * n) + cnew;
                        if (rnew >= 0 and cnew >= 0 and rnew < n and cnew < n and grid[rnew][cnew] == 1){
                            if (s.find(ds.findParent(numnew)) == s.end()){
                                tempSize += ds.findSize(numnew);
                                s.insert(ds.findParent(numnew));
                            }
                        }
                    }
                    outputSize = max(outputSize,tempSize+1);
                }
            }
        }
        
        for (int i = 0; i < n*n; i++){
            outputSize = max(outputSize,ds.findSize(i));
        }
        // cout << ds.findSize(2);
        return outputSize;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends