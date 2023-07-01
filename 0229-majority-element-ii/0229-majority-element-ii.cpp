class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> list;
        int first = INT_MIN;
        int second = INT_MIN;
        int votef = 0;
        int votes = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            if (votef == 0 and second != nums[i]){
                first = nums[i];
                votef = 1;
            }else if (votes == 0 and first != nums[i]){
                second = nums[i];
                votes = 1;
            }else{
                if (first == nums[i]){
                    votef++;
                }else if (second == nums[i]){
                    votes++;
                }else{
                    votef--;
                    votes--;
                }
            }
        }

        votes = 0;
        votef = 0;
        for (int i = 0; i < n; i++){
            if (first == nums[i]) votes++;
            if (second == nums[i]) votef++;
        }

        int mini = int(n / 3) + 1;
        if (votes >= mini) list.push_back(first);
        if (votef >= mini) list.push_back(second);

        return list;
    }
};