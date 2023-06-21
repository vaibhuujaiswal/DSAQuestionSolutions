//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    public:
    //Function to find total number of unique paths.
    long long int numberOfPaths(int a, int b)
    {
        vector<vector<long long int>> dp(a, vector<long long int>(b,0));
        return f(a-1,b-1,a,b,dp)%1000000007;
    }
    
    long long int f(int indr, int indc, int a, int b, vector<vector<long long int>> &dp){
        if (indr >= a || indc >= b || indr < 0 || indc < 0){
            return 0;
        }
        if (indr == 0 && indc == 0){
            return 1;
        }
        if (dp[indr][indc] != 0) return dp[indr][indc];
        long long int l = f(indr-1,indc,a,b,dp)%1000000007;
        long long int r = f(indr,indc-1,a,b,dp)%1000000007;
        return dp[indr][indc] = (l + r)%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends