class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 2) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int i;
        for (i = n-2; i >= 0 ; i--){
            if (nums[i] < nums[i+1]){
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for (j = n-1; j >= 0; j--){
            if (nums[i] < nums[j]){
                break;
            }
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        reverse(nums.begin() + i + 1, nums.end());
    }
};