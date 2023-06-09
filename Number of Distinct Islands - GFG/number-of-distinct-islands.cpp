//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> distinctIslands;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0)); //creates a visited array of distinct islands
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j] and grid[i][j] == 1) {
                    bfs(i,j,grid,distinctIslands,visited);
                }
            }
        }
        int output = distinctIslands.size();
        return output;
    }
    //int base represents the base value we are interested in;
    void bfs(int baser, int basec, vector<vector<int>>& grid, 
    set<vector<pair<int,int>>> &distinctIslands, vector<vector<int>> &visited){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({baser,basec});
        visited[baser][basec] = 1;
        vector<pair<int,int>> output;
        output.push_back({0,0});
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int rarr[] = {0,0,-1,1};
            int carr[] = {1,-1,0,0};
            for (int i = 0; i < 4; i++){
                int rnew = r + rarr[i];
                int cnew = c + carr[i];
                if (rnew < n and cnew < m and rnew >= 0 and cnew >= 0 and grid[rnew][cnew] == 1){
                    if (!visited[rnew][cnew]) {
                        visited[rnew][cnew] = 1;
                        output.push_back({baser - rnew,basec - cnew});
                        q.push({rnew, cnew});
                    }
                } 
            }
        }

        distinctIslands.insert(output);
        return;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends