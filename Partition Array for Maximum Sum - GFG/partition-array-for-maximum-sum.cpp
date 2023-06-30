//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
        vector<int> dp(n,-1);
        return f(0,arr,n,k,dp);
    }
    
    int f(int i, vector<int>& arr, int n, int k, vector<int>& dp){
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int maxi = 0;
        int count = 1;
        int maxEle = 0;
        
        for (int ind = i; ind < n; ind++){
            if (count == k+1) break;
            maxEle = max(maxEle,arr[ind]);
            int cost = (maxEle * count) + f(ind+1,arr,n,k,dp);
            maxi = max(maxi,cost);
            count++;
        }
        
        return dp[i] = maxi;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends