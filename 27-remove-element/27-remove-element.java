//In this solution we will flip the value with the element that is not val since we do not need to preserve the order of the elements.
class Solution {
    public int removeElement(int[] nums, int val) {
        int position = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] == val){
                if (position == nums.length - 1){
                    return i; 
                }else if (position > i){
                    while (nums[position] == val){
                        if (position == nums.length - 1) return i; 
                        position++;
                    }
                }else if (position <= i){
                    position = i;
                    while (nums[position] == val){
                        if (position == nums.length - 1) return i; 
                        position++;
                    }
                }
                nums[i] = nums[position];
                nums[position] = val;
            }
        }
        return nums.length;
    }
}