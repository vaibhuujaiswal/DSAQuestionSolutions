class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        for (int ele = 0; ele < n; ele++){
            int i = ele+1;
            int j = n-1;
            while (i < j){
                    if (nums[i] + nums[j] + nums[ele] == 0){
                        output.push_back({nums[i],nums[j],nums[ele]});
                        int templeft = i;
                        int tempright = j;
                        while (i < j and nums[templeft] == nums[i]) i++;
                        while (i < j and nums[tempright] == nums[j]) j--;
            
                    }else if (nums[i] + nums[j] + nums[ele] < 0){
                        i++;
                    }else{
                        j--;
                    }
                }
            while (ele < n-1 and nums[ele] == nums[ele+1]) ele++; //check this out
        }
        
        return output;
    }
};