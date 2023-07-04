//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
        long long prefix = 1;
        long long suffix = 1;
        long long maxSum = INT_MIN;
        for (int i = 0; i < n; i++){
            prefix *= nums[i];
            maxSum = max(prefix,maxSum);
            if (prefix == 0) prefix = 1;
        }
        
        for (int i = n-1; i >= 0; i--){
            suffix *= nums[i];
            maxSum = max(suffix,maxSum);
            if (suffix == 0) suffix = 1;
        }
        return maxSum;
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