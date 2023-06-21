//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a, vector<int>(b,0));
        return f(a-1,b-1,a,b,dp);
    }
    
    int f(int indr, int indc, int a, int b, vector<vector<int>> &dp){
        if (indr >= a || indc >= b || indr < 0 || indc < 0){
            return 0;
        }
        if (indr == 0 && indc == 0){
            return 1;
        }
        if (dp[indr][indc] != 0) return dp[indr][indc];
        int l = f(indr-1,indc,a,b,dp);
        int r = f(indr,indc-1,a,b,dp);
        return dp[indr][indc] = l + r;
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends