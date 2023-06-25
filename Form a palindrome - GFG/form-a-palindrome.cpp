//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
        string S1 = str;
        string S2 = str;
        reverse(S2.begin(),S2.end());
        int n = str.size();
        int m = str.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        
        int maxvalue = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (S1[i-1] == S2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n - dp[n][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends