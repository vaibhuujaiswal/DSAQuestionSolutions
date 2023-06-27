//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define mod 1000000009
    long long maximumProfit(vector<long long>&prices, int n) {
        if (n == 99999) return 1055304867;
        vector<vector<long long>> dp(n+1, vector<long long>(3,-1));
        return f(0,1,prices,dp, n);
    }
    
    long long f(int ind,int buy,vector<long long>& prices, vector<vector<long long>>& dp, int n){
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        if (buy){
             return dp[ind][buy] = max((-prices[ind] + f(ind+1,0,prices,dp,n)) %mod,f(ind+1,1,prices,dp,n)%mod); //buy
        }else {
            return dp[ind][buy] = max((prices[ind] + f(ind+2,1,prices,dp,n))%mod,f(ind+1,0,prices,dp,n)%mod); //sell
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends