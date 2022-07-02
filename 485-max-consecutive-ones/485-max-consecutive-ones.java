class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int temp = 0;
        int global = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] == 0){
                global = Math.max(temp,global);
                temp = 0;
                continue;                
            }
            temp++;
            }
        global = Math.max(temp,global);
        return global;
        }
    }