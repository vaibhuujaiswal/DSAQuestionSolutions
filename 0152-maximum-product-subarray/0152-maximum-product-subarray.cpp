class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++){
            prefix = prefix * nums[i];
            maxSum = max(prefix,maxSum);
            if (prefix == 0) prefix = 1;
        }
        
        for (int i = n-1; i >= 0; i--){
            suffix = suffix * nums[i];
            maxSum = max(suffix,maxSum);
            if (suffix == 0) suffix = 1;
        }
        return maxSum;
    }
};