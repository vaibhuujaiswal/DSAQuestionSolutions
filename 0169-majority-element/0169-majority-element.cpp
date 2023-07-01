class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = INT_MIN;
        int vote = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (vote == 0){
                ele = nums[i];
                vote++;
            }else if (nums[i] == ele){
                vote++;
            }else{
                vote--;
            }
        }

        return ele;
    }
};