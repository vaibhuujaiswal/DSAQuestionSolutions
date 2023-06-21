//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    int totalWays(int a, int b, vector<vector<int>> &grid) {
        vector<vector<int>> dp(a, vector<int>(b,0));
                if(grid[0][0]==1 || grid[a-1][b-1]==1){
            return 0;
        }
        return f(a-1,b-1,a,b,dp,grid)%1000000007;
    }
    
    int f(int indr, int indc, int a, int b, vector<vector<int>> &dp, vector<vector<int>> &grid){
        if (indr >= a || indc >= b || indr < 0 || indc < 0){
            return 0;
        }
        
        if (grid[indr][indc] == 1){
            return 0;
        }
        if (indr == 0 and indc == 0 and grid[indr][indc] == 0){
            return 1;
        }
        if (dp[indr][indc] != 0) return dp[indr][indc];
        int l = f(indr-1,indc,a,b,dp,grid)%1000000007;
        int r = f(indr,indc-1,a,b,dp,grid)%1000000007;
        return dp[indr][indc] = l + r;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends