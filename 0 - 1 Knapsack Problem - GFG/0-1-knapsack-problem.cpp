//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n, vector<int>(W + 1, -1));
       
       
       
       return f(n-1,W,dp,wt,val);
    }
    
    
    int f(int ind, int W, vector<vector<int>> &dp, int wt[], int val[]){
        if (ind == 0){
            if (W >= wt[0]) return val[0]; //pick 0;
            else return 0; //not pick index 0
        }
        if (W == 0) return 0;
        
        if (dp[ind][W] != -1) return dp[ind][W];
        
        int notpick = 0 + f(ind-1, W, dp, wt, val);
        int pick = 0;
        if (W >= wt[ind]) pick = val[ind] + f(ind-1, W - wt[ind], dp, wt, val);

        return dp[ind][W] = max(pick, notpick);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends