//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int price[]) {
        if (N == 0) return 0;
        vector<vector<vector<int>>> dp(N , vector<vector<int>>(2,vector<int>(K+1,-1))); // int dp[n][2][3]
        return f(0,1,K,price,dp,N);
    }
    
    int f(int ind,int buy,int cap, int price[], vector<vector<vector<int>>>& dp, int N){
        if (cap == 0) return 0;
        if (ind == N) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if (buy){
            return dp[ind][buy][cap] = max(-price[ind] + f(ind+1,0,cap,price,dp,N),f(ind+1,1,cap,price,dp,N)); //buy
        }else{
            return dp[ind][buy][cap] = max(price[ind] + f(ind+1,1,cap-1,price,dp,N),f(ind+1,0,cap,price,dp,N)); //sell
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends