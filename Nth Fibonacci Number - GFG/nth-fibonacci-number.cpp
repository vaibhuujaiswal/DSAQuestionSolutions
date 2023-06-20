//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n+1,-1);
        long long int output = f(n,dp);
        output = output % 1000000007;
        return output;
    }
    
    long long int f(long long int n, vector<long long int> &dp){
        if (n <= 1){
            return n;
        }
        if (dp[n] != -1) return dp[n];
        return dp[n] = (f(n-1,dp) + f(n-2,dp))%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends