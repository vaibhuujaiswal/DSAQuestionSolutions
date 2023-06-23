//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int target = 0;
        for (int i = 0; i < N; i++) target += arr[i];
        
        if (target % 2 != 0) return false;
        target = target/2;
        vector<vector<bool>> dp(N,vector<bool>(target+1,false));
        for (int i = 0; i < N; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= target) dp[0][arr[0]] = true;
        
        for (int i = 1; i < N; i++){
            for (int k = 1; k <= target; k++){
                bool nottaken = dp[i-1][k];
                bool taken = false;
                if (arr[i] <= k) taken = dp[i-1][k-arr[i]];
                dp[i][k] = (taken or nottaken);
            }
        }
        return dp[N-1][target];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends