class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        for (int ele2 = 0; ele2 < n; ele2++){
            for (int ele = ele2+1; ele < n; ele++){
                int i = ele+1;
                int j = n-1;
                while (i < j){
                        // cout << nums[ele2] << " " <<  nums[ele]<< " " << nums[i] << " " <<nums[j] << endl;
                        long long int a = nums[i];
                        long long int b = nums[j];
                        long long int c = nums[ele];
                        long long int d = nums[ele2];
                        long long int value = a + b + c + d;
                        if (value == target){
                            output.push_back({nums[ele2],nums[ele],nums[i],nums[j]});
                            int templeft = i;
                            int tempright = j;
                            while (i < j and nums[templeft] == nums[i]) i++;
                            while (i < j and nums[tempright] == nums[j]) j--;

                        }else if (value < target){
                            i++;
                        }else{
                            j--;
                        }
                    }
                while (ele < n-1 and nums[ele] == nums[ele+1]) ele++; //check this out
            }
            while (ele2 < n-1 and nums[ele2] == nums[ele2+1]) ele2++; //check this out
        }
        
        return output;
    }
};