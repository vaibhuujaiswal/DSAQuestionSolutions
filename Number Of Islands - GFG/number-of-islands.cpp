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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m); //define disjoint set with number n*m matrix
        vector<int> islands; //array of size k has to be returned

        vector<int> visited(n*m, 0); //mark all nodes/sea as unvisited or basically marked as sea
        int count = 0;
        for (auto it : operators){
            int r = it[0];
            int c = it[1];
            int num = (r * m + c);

            if (visited[num]){
                islands.push_back(count);
                continue;
            }else{
                visited[num] = 1;
                count++;
            }
            
            int row[4] = {0,0,1,-1};
            int col[4] = {1,-1,0,0};
            
            for (int i = 0; i < 4; i++){
                int rnew = r + row[i];
                int cnew = c + col[i];
                if (rnew >= 0 && cnew >= 0 && rnew < n && cnew < m) {
                    int newnum = (rnew * m + cnew);
                    // cout << newnum << endl;
                    if (visited[newnum]) {
                        if (ds.findParent(newnum) != ds.findParent(num)) {
                            ds.findUnionBySize(newnum, num);
                            count--;
                        }
                    }
                }
            }
            islands.push_back(count);
        }
        return islands;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends