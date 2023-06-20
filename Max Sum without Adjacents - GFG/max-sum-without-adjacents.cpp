//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,-1);
	    return f(arr,n,n-1,dp);
	}
	
	int f(int *arr, int n, int ind, vector<int> &dp){
	    if (ind < 0) return 0;
	    if (ind == 0) return arr[0];
	    if (dp[ind] != -1) return dp[ind];
	    int choice1 = f(arr, n ,ind-2, dp) + arr[ind];
	    int choice2 = f(arr,n,ind-1,dp);
	    return dp[ind] = max(choice1,choice2);
	}
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends