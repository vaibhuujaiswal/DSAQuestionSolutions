//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int W) {
        vector<vector<int>> dp(W,vector<int>(W+1,-1));

        return f(W-1,W,price,dp);
    }
    
    int f(int ind, int W, int price[],vector<vector<int>> &dp){
        if (ind == 0){ //base case
            if (W == 0) return 0;
            if (ind + 1 <= W) return (int)(W/1)*price[0];
            else return 0;
        }
        if (dp[ind][W] != -1) return dp[ind][W];
        int nottake = f(ind - 1, W, price, dp);
        int take = 0;
        if (ind + 1 <= W){
            take = price[ind] + f(ind, W - ind - 1, price, dp);
        }
        return dp[ind][W] = max(take,nottake);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends