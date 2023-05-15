//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        return sum(nums,k) - sum(nums,k-1);
    }
    
    int sum(vector<int>& nums, int k){
        int l = 0;
        int r = 0;
        int oddCount = 0;
        int subarrayCount = 0;
        while (r < nums.size()){
            if (nums[r] % 2 != 0) oddCount++;
            while (oddCount > k && l <= r){
                if (nums[l] % 2 != 0) oddCount--;
                l++;
            }
            subarrayCount += r - l + 1;
            r++;
        }
        return subarrayCount;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends