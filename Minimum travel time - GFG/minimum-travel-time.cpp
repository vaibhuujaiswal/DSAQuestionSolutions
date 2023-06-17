//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    typedef pair<int,pair<int,int>> ppi;
    bool isValid(int r, int c, int n){
        return (r >= 0 and c >= 0 and r < n and c < n);
    }
    
    int Solve(int n, vector<vector<int>>& grid) {
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> visited(n,vector<int>(n,0));
        pq.push({grid[0][0], {0,0}});
        int minimumTime = 0;
        while (!pq.empty()){
            auto it = pq.top(); pq.pop();
            int nodeW = it.first;
            int r = it.second.first;
            int c = it.second.second;
            minimumTime = max(minimumTime,grid[r][c]);

            if (r == n-1 and c == n-1){
                minimumTime = max(minimumTime,grid[n-1][n-1]);
                return minimumTime;
            }
            int row[4] = {0,0,-1,1};
            int col[4] = {-1,1,0,0};
            for (int i = 0; i < 4; i++){
                int rnew = r + row[i];
                int cnew = c + col[i];
                if (isValid(rnew,cnew,n) and !visited[rnew][cnew]){
                    visited[rnew][cnew] = 1;
                    pq.push({grid[rnew][cnew],{rnew,cnew}});
                }
            }
        }
        return -1;
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
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends