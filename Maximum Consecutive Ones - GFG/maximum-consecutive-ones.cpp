//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int global = 0;
        int j = 0; //back pointer
        int i = 0; //forward pointr
        int zero = 0;
        while (i < nums.size()){
            if (nums[i] == 0){
                zero++;
            }
            while (zero > k){
                if (nums[j] == 0){
                    zero--;
                }
                j++;
            }
            global = max(global,i - j + 1);
            i++;
        }
        return global;
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
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends