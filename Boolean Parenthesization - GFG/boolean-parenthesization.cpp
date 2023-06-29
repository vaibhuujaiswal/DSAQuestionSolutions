//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define mod 1003
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(2, -1)));
        return f(0,N-1,1,S,dp);
    }
    
    int f(int i, int j, int isTrue, string &S, vector<vector<vector<int>>> &dp){
        if (i > j) return 0;
        if (i == j){
            if (isTrue) return (S[i] == 'T') ? 1 : 0;
            else return  (S[i] == 'F') ? 1 : 0;
        }
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int count = 0;
        for (int ind = i+1; ind <= j; ind += 2){
            int lt = f(i,ind-1,1,S,dp)%mod;
            int lf = f(i,ind-1,0,S,dp)%mod;
            int rt = f(ind+1,j,1,S,dp)%mod;
            int rf = f(ind+1,j,0,S,dp)%mod;
            
            if (S[ind] == '&'){
                count += (isTrue) ? (lt * rt)%mod : ((lt * rf)%mod + (lf * rt)%mod + (lf * rf)%mod)%mod;
            }else if (S[ind] == '|'){
                count += (isTrue) ? ((lt * rf)%mod + (lf * rt)%mod + (lt * rt)%mod) : ((lf * rf)%mod);
            }else if (S[ind] == '^'){
                count += (isTrue) ? ((lt * rf)%mod + (lf * rt)%mod)%mod : ((lf * rf)%mod + (lt * rt)%mod)%mod;
            }
            
        }
        
        return dp[i][j][isTrue] = count%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends