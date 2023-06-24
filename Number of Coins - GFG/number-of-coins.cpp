//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int arr[], int n, int target) 
	{ 
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        int output = f(n-1,target,arr,dp);
        if (output == 1e9){
            return -1;
        }else{
            return output;
        }
	} 
	
	int f(int ind,int target,int arr[],vector<vector<int>> &dp){
        if (ind == 0){
            if (target % arr[0] == 0) return target / arr[0];
            return 1e9;
        }
        if (dp[ind][target] != -1) return dp[ind][target];
        int notpick = f(ind-1,target,arr,dp);
        int pick = 1e9;
        if (arr[ind] <= target) pick = 1 + f(ind,target - arr[ind], arr,dp);
        return dp[ind][target] = min(pick,notpick);
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends