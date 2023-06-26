//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++){
            dp[0][j] = j; //base cases defined
        }
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    int replaceInS = 1 + dp[i-1][j-1];
                    int deletechInS = 1 + dp[i-1][j];
                    int insertInS = 1 + dp[i][j-1];
                    dp[i][j] = min(min(replaceInS,deletechInS),insertInS);
                }
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends