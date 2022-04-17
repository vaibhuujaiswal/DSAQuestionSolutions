class Solution {
    public int removeDuplicates(int[] nums) {
        int pos=0;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=nums[pos]){
                nums[pos+1] = nums[i];
                pos++;
            }
        }
        return pos+1;
    }
}