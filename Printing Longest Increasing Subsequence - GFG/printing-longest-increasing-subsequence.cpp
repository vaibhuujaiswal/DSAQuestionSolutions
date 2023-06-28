//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1); 
        vector<int> hash(n);
        int maxi = 0;
        int lastIndex = -1;
        for (int i = 0; i < n; i++){
            hash[i] = i;
            for (int prev = 0; prev < i; prev++){
                
                if (arr[i] > arr[prev] and 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];  
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (lastIndex != hash[lastIndex]){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends