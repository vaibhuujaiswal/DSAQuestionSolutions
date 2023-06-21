//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        int mod = (int)(1000000007);
        if ((grid[0][0] == 0) || (grid[n-1][m-1] == 0)) return 0;
        vector<int> dp(m,0);
        for (int i = 0; i < n; i++){
            vector<int> temp(m,0);
            for (int j = 0; j < m; j++){
                int left = 0;
                int up = 0;
                if (i == 0 and j == 0) temp[j] = 1;
                else if (!grid[i][j]) temp[j] = 0;
                else{
                    if (i > 0) up = dp[j];
                    if (j > 0) left = temp[j-1];
                    temp[j] = (up + left)%mod;
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends