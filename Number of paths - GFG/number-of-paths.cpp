//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

int f(int indr, int indc, int a, int b, vector<vector<long long>> &dp){
        if (indr >= a || indc >= b || indr < 0 || indc < 0){
            return 0;
        }
        if (indr == 0 && indc == 0){
            return 1;
        }
        if (dp[indr][indc] != 0) return dp[indr][indc];
        long long l = f(indr-1,indc,a,b,dp);
        long long r = f(indr,indc-1,a,b,dp);
        return dp[indr][indc] = l + r;
    }

long long  numberOfPaths(int a, int b)
{
    vector<vector<long long>> dp(a, vector<long long>(b,0));
    return f(a-1,b-1,a,b,dp);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends