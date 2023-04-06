//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long dp[n][3];
	    dp[0][0] = INT_MIN;
	    dp[0][1] = arr[0];
	    dp[0][2] = arr[0];
	    for (int i = 1; i < n; i++){
	        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
	        long long value = arr[i];
	        dp[i][1] = max(max(dp[i-1][1] * value, value), dp[i-1][2] * value);
	        dp[i][2] = min(min(dp[i-1][1] * value, value), dp[i-1][2] * value);
	    }
	    return max(dp[n-1][0],dp[n-1][1]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends