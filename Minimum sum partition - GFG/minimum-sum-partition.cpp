//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int minDifference(int arr[], int n) {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += arr[i];

        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= totalSum; target++) {
                bool nottake = dp[i - 1][target];
                bool take = false;
                if (arr[i] <= target)
                    take = dp[i - 1][target - arr[i]];
                dp[i][target] = nottake || take;
            }
        }

        int minv = 1e9;
        for (int sumIterator = 0; sumIterator <= totalSum; sumIterator++) {
            if (dp[n - 1][sumIterator]) {
                minv = min(minv, abs(sumIterator - (totalSum - sumIterator)));
            }
        }

        return minv;
    }
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends