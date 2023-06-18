//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
         vector<vector<int>> output;
         vector<int> temp;
         sort(nums.begin(), nums.end());
         valuePrint(nums,0,output,temp);
         return output;
         
    }
    
    void valuePrint(vector<int>& nums, int ind, vector<vector<int>> &output, vector<int> temp){
        output.push_back(temp);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            valuePrint(nums, i + 1, output, temp);
            temp.pop_back();
         }
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends